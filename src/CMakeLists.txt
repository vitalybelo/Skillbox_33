cmake_minimum_required(VERSION 3.23)

add_executable(Skillbox_33
        main.cpp
        use_lib.cpp
        OnlineStore.cpp
        FishGame.cpp
        solution_1.cpp
        solution_2.cpp
        solution_3_vector.cpp
        solution_3_multimap.cpp
        solution_4.cpp
        )

target_include_directories(Skillbox_33 PUBLIC ${INCLUDE_DIR})
