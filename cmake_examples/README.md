## CMake introduction

`cmake_minimum_required(VERSION 3.5)`

specify the minimum version of CMake, when creating a project using CMake.(`A-hello-cmake`)

`project (hello_cmake)`
A CMake build can include a project name to make referencing certain variables easier when using multiple projects.(`A-hello-cmake`)

`add_executable(hello_cmake main.cpp)`
An executable should be build from the specified source files, The first argument to the add_executable() function is the name of the executable to be built, 
and the second argument is the list of source files to compile.(`A-hello-cmake`)

`set(SOURCES
    src/Hello.cpp
    src/main.cpp
)`
Creating a variable which includes the source files allows you to be clearer about these files and easily add them to multiple commands.(`B-hello-header`)

`target_include_directories(hello_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)`
When you have different include folders, you can make your compiler aware of them using the target_include_directories() function. When compiling this target this will add these directories to the compiler with the -I flag e.g. -I/directory/path.
The PRIVATE identifier specifies the scope of the include. (`B-hello-header`)
`PROJECT_SOURCE_DIR`: The source directory of the current cmake project.








### Building
```shell
mkdir build
cd build
cmake ..
make
./${project_name}

make clean #remove the executable file
make VERBOSE=1 #To see the full output for debugging purposes

```
