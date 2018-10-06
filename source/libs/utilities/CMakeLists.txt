add_library(
    File_Accessor SHARED
    File_Accessor.hpp
    File_Accessor.cpp
)

add_library(
    Date_Operations SHARED
    Date_Operations.hpp
    Date_Operations.cpp
)

add_library(
    Regex_Operations SHARED
    Regex_Operations.hpp
    Regex_Operations.cpp
)

target_link_libraries(File_Accessor stdc++fs)