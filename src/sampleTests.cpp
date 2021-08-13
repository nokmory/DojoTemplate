#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(environmentTest, passingTest)
{
    EXPECT_EQ(true, true);
}

struct Fixture : public testing::Test
{
    int sth;
    Fixture() : sth(7) {}
};

TEST_F(Fixture, testUsingFixture)
{
    EXPECT_EQ(sth, 7);
}

using ReturnType = int;
using ArgType1 = char;
using ArgType2 = double;

class FreeInterface
{
public:
    virtual ReturnType methodName(ArgType1, ArgType2) const = 0;
};

struct FreeMock : public FreeInterface
{
    MOCK_METHOD(ReturnType, methodName, (ArgType1, ArgType2), (const, override));
    // MOCK_CONST_METHOD2(methodName, ReturnType(ArgType1, ArgType2)); //Ye olde way
};

TEST(environmentTest, mockPassingTest)
{
    testing::NiceMock<FreeMock> niceMock;
    testing::StrictMock<FreeMock> strictMock;
    EXPECT_CALL(niceMock, methodName()).Times(1);
    niceMock.methodName();
}

struct Params
{
    int val;
};

bool operator==(const Params &lhs, const Params &rhs)
{
    return lhs.val == rhs.val;
}

struct ParametricTests : public ::testing::TestWithParam<Params>
{
};

TEST_P(ParametricTests, aTest)
{
    auto params = GetParam();
    EXPECT_EQ(params.val % 2, 0);
}

INSTANTIATE_TEST_CASE_P(ParametricInstatiation, ParametricTests,
                        ::testing::Values(Params{2}, Params{4}));
