cmake_minimum_required(VERSION 3.20)
project(macs_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mcs
    src/main.cpp
    src/lexer/lexer.cpp
    src/parser/parser.cpp
    src/ast/ast.cpp
    src/semantic/semantic.cpp
    src/codegen/codegen.cpp
    src/errors/error.cpp
)

target_include_directories(mcs PRIVATE include)