cmake_minimum_required(VERSION 3.10)
project(badlang)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    bad_compiler/bad_compiler_main.cpp
    bad_compiler/bad_source_get.cpp
    bad_compiler/bad_lexer/bad_lexer.cpp
    bad_compiler/bad_parser/bad_parser.cpp
    bad_compiler/bad_compiler/bad_compiler.cpp
    bad_compiler/main.bad
)

add_executable(badlang ${SOURCES})
