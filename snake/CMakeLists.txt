cmake_minimum_required(VERSION 3.0.0)
project(snake VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(snake main.cpp ./src/background.cpp ./src/display.cpp ./src/food.cpp ./src/internals.cpp ./src/snake.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
