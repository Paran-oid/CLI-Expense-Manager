cmake_minimum_required(VERSION 3.31.2)

project(ExpenseTracker)

set(CMAKE_C_STANDARD 23)

set(SRC main.c
        src/menu.c
        src/file_manager.c
        src/core/core.c
        src/user_service.c)

set(INCLUDE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/models
    ${CMAKE_SOURCE_DIR}/include/core)

add_executable(ExpenseTracker ${SRC})

include_directories(${INCLUDE})

add_custom_target(run ALL
    DEPENDS ExpenseTracker
    COMMAND echo ""
    COMMAND ./ExpenseTracker
    COMMAND echo ""
)