cmake_minimum_required(VERSION 3.10)
project (latespenaltytracker VERSION 0.0.0)
add_subdirectory(utilities)
add_compile_options(-Wall -Wextra -Wpedantic)

add_library(
    Sprint SHARED
    Sprint.hpp
    Sprint.cpp
)

add_library(
    Penalty SHARED
    Penalty.hpp
    Penalty.cpp
)

add_library(
    Person SHARED
    Person.hpp
    Person.cpp
)

add_library(
    Tests SHARED
    Tests.hpp
    Tests.cpp
)

add_library(
    Time SHARED
    Time.hpp
    Time.cpp
)

add_library(
    File_Accessor SHARED
    utilities/File_Accessor.hpp
    utilities/File_Accessor.cpp
)

add_library(
    Date_Operations SHARED
    utilities/Date_Operations.hpp
    utilities/Date_Operations.cpp
)

add_library(
    Regex_Operations SHARED
    utilities/Regex_Operations.hpp
    utilities/Regex_Operations.cpp
)

target_link_libraries(File_Accessor stdc++fs)


#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--std=c++17 -lstdc++fs") # -lstdc++fs #-lstdc++fs -lpthread
set(CMAKE_C_COMPILER "/usr/bin/gcc-8")
set(CMAKE_CXX_COMPILER "/usr/bin/g++-8")
#set(CMAKE_EXE_LINKER_FLAGS "-lstdc++fs")
#target_link_libraries(stdc++fs).

#set(EXECUTABLE_OUTPUT_PATH ../)
# set (EXCLUDE_DIR "../build/")
# file(GLOB_RECURSE Foo_SOURCES "*.cpp")
# file(GLOB_RECURSE Foo_HEADERS "*.hpp")
# message(${Foo_SOURCES} \n)
# set (Foo_INCLUDE_DIRS "")
# foreach (_headerFile ${Foo_HEADERS})
#     get_filename_component(_dir ${_headerFile} PATH)
#     list (APPEND Foo_INCLUDE_DIRS ${_dir})
# endforeach()
# list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

add_executable (a.out main.cpp)


#message(a.out, ${Foo_SOURCES} \n \n \n \n)
#message(a.out, ${Foo_HEADERS} \n)

#add_executable (a.out ${WEW})
#target_include_directories(a.out PRIVATE ${Foo_INCLUDE_DIRS})
target_link_libraries(a.out stdc++fs Tests Sprint Penalty Person File_Accessor Date_Operations Regex_Operations) #stdc++fs