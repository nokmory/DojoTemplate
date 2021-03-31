cmake_minimum_required(VERSION 3.10)
project(ChangeMyName CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(cmake/GTest.cmake)

add_executable(sample_test src/testZero.cpp)
target_include_directories(sample_test PUBLIC include)
target_link_libraries(sample_test gtest_main gtest)

enable_testing()
add_test(tests sample_test)
