cmake_minimum_required(VERSION 3.16)

project(QuizTests)

find_package(Qt6 REQUIRED COMPONENTS Test)

set(CMAKE_AUTOMOC ON)

add_executable(tests
    ../src/question.cpp
    test_question.cpp
)

target_link_libraries(tests Qt6::Test)
