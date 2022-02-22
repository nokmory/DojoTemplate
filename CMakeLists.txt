cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

# On debian-like:
# sudo apt-get install libx11-dev libxrandr-dev freeglut3-dev libudev-dev libfreetype-dev libopenal-dev libvorbis-dev
#
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "master"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

if(NOT MSVC)
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(sample_test src/testZero.cpp src/sampleTests.cpp)
target_include_directories(sample_test PUBLIC include)
target_link_libraries(sample_test PRIVATE gmock_main gtest gmock)



add_executable(sfml_sample src/sfmlSample.cpp)
target_link_libraries(sfml_sample PRIVATE sfml-graphics sfml-window sfml-system)


add_custom_target(run_tests
                  COMMAND sample_test
                  DEPENDS sample_test)

enable_testing()
add_test(tests sample_test)