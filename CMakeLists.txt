cmake_minimum_required(VERSION 3.0)

add_compile_options(-Wall -Wextra -Wpedantic)

# #add_library(GLOB wew
# #            "*.cpp"
# #            Utilities/"*.cpp"
# #            )
# include_directories(${PROJECT_SOURCE_DIR})
# add_executable(a.out practice.cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17") # -lstdc++fs #-lstdc++fs -lpthread
#set(CMAKE_EXE_LINKER_FLAGS "-lstdc++fs")
#target_link_libraries(stdc++fs).

set(EXECUTABLE_OUTPUT_PATH ../)

file(GLOB_RECURSE Foo_SOURCES "*.cpp")
file(GLOB_RECURSE Foo_HEADERS "*.hpp")
message(${Foo_SOURCES} \n)
set (Foo_INCLUDE_DIRS "")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

add_executable (a.out
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Penalty.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Person.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Sprint.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Tests.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Time.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Utilities/Date_Operations.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Utilities/File_Accessor.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/Utilities/Regex_Operations.cpp
/mnt/c/Users/myung/Documents/GitHub/latespenaltytracker/practice.cpp )


#message(a.out, ${Foo_SOURCES} \n \n \n \n)
#message(a.out, ${Foo_HEADERS} \n)

#add_executable (a.out ${WEW})
#target_include_directories(a.out PRIVATE ${Foo_INCLUDE_DIRS})
target_link_libraries(a.out stdc++fs)