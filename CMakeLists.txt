cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# On debian-like:
# sudo apt-get install libx11-dev libxrandr-dev freeglut3-dev libudev-dev libfreetype-dev libopenal-dev libvorbis-dev
#
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "2.5.1"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(sample_test src/testZero.cpp src/sampleTests.cpp)
target_include_directories(sample_test PUBLIC include)
target_link_libraries(sample_test gmock_main gtest gmock)



add_executable(sfml_sample src/sfmlSample.cpp)
target_link_libraries(sfml_sample sfml-graphics)


add_custom_target(run_tests
                  COMMAND sample_test
                  DEPENDS sample_test)

enable_testing()
add_test(tests sample_test)
