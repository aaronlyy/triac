cmake_minimum_required(VERSION 3.15)
project(triac C)

set(CMAKE_C_STANDARD 11)

add_library(triac
    src/socket.c
)

target_include_directories(triac
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(socket_echo examples/socket_echo.c)
target_link_libraries(socket_echo triac)