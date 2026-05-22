cmake_minimum_required(VERSION 3.20)
project(mcs_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

include_directories(include)

add_executable(mcs
    src/main.cpp
    src/lexer/Lexer.cpp
    src/parser/Parser.cpp
    src/ast/AST.cpp
    src/semantic/Semantic.cpp
    src/codegen/CodeGen.cpp
)

target_link_libraries(mcs LLVM)