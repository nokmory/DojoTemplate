# Dojo template
This is a template for quick start of a new C++ project. The autor used it mainly for coding dojo exercises but it is a pretty good starting point for any C++ project if you just want to start coding with TDD ;)
It uses CMake for configuration, and project local GTest/GMock for unit tests.

## Usage

1. Clone the repository
> git clone https://github.com/nokmory/DojoTemplate.git MyNewAwesomeProject
2. Depending how you want to use it:
#### Raw
If you have everything installed already and don't really care about versions of compiler etc. then:
    
1. Prepare a build directory, for example
> mkdir build
2. Run CMake to generate build files, for example
> cmake -s MyNewAwesomeProject/workspace -b build
It will generate Makefile by default, use -G"Ninja" to get ninja scripts instead.

### Docker/Podman
If you want a different (for example: never) compiler or don't want to install additional software on your system beyond Podman or Docker

1. Get inside repo
> cd MyAwesomeProject
2. Get the gcc image with cmake and ninja ready:
> podman build . -t=gcc_latest
3. Start interactive shell in the container and mount the workspace. Build folder will live and die with the container
> podman run --mount type=bind,source=`pwd`/workspace,destination=/workspace -p 2222:2222 --rm -it gcc_latest
4. Run Cmake
> cmake -G"Ninja" /workspace

### Compilation + tests
To compile and run the tests just
> make run_tests

or

> ninja run_tests

depending which generator was used earlier.

Initially there should be a single test failing, named testFailedSuccesfully

You can remove `src/sampleTests.cpp` form `sample_tests` binary definition in `workspace/CMakeLists.txt` to get rid of unnecessary noise.

Happy coding!
