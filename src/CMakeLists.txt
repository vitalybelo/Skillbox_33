cmake_minimum_required(VERSION 3.24)

add_executable(Skillbox_33
        main.cpp
        use_lib.cpp
        solution_1.cpp
        Basket.cpp)

target_include_directories(Skillbox_33 PUBLIC ${INCLUDE_DIR})
