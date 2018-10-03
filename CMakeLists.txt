cmake_minimum_required(VERSION 3.10)
project (latespenaltytracker VERSION 0.0.0)

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
    File_Accessor SHARED
    Utilities/File_Accessor.hpp
    Utilities/File_Accessor.cpp
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

add_executable (a.out
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Tests.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Time.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Utilities/Date_Operations.cpp
#/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Utilities/File_Accessor.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Utilities/Regex_Operations.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/practice.cpp )


#message(a.out, ${Foo_SOURCES} \n \n \n \n)
#message(a.out, ${Foo_HEADERS} \n)

#add_executable (a.out ${WEW})
#target_include_directories(a.out PRIVATE ${Foo_INCLUDE_DIRS})
target_link_libraries(a.out stdc++fs Sprint Penalty Person File_Accessor) #stdc++fs