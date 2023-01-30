cmake_minimum_required(VERSION 3.24)

add_executable(Skillbox_33
        main.cpp
        use_lib.cpp
        Basket.cpp
        FishGame.cpp
        solution_1.cpp
        solution_2.cpp
        solution_3_vector.cpp
        solution_3_multimap.cpp
        )

target_include_directories(Skillbox_33 PUBLIC ${INCLUDE_DIR})
