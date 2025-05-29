cmake_minimum_required(VERSION 3.31)
project(Console_Editor_Upgraded)

set(CMAKE_CXX_STANDARD 20)

add_executable(Console_Editor_Upgraded main.cpp
        TextEditor.cpp
        TextEditor.h
        structures.cpp
        library.h
        append_newLine.cpp
        print.cpp
        insert.cpp
        search.cpp
        fileCommands.cpp)
