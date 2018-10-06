add_executable (a.out main.cpp)

target_link_libraries(a.out
                PRIVATE stdc++fs
                PRIVATE Sprint
                PRIVATE Penalty
                PRIVATE Person
                PRIVATE File_Accessor
                PRIVATE Date_Operations
                PRIVATE Regex_Operations
                )
