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
    Time SHARED
    Time.hpp
    Time.cpp
)
set(RELATIVE_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
message(STATUS "The relative path used for libs: " "${RELATIVE_INCLUDE_PATH}")
target_include_directories(Sprint PUBLIC "${RELATIVE_INCLUDE_PATH}")
target_include_directories(Penalty PUBLIC "${RELATIVE_INCLUDE_PATH}")
target_include_directories(Person PUBLIC "${RELATIVE_INCLUDE_PATH}")
target_include_directories(Time PUBLIC "${RELATIVE_INCLUDE_PATH}")