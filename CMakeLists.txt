cmake_minimum_required(VERSION 3.31)
project(Console_Editor_Upgraded)

set(CMAKE_CXX_STANDARD 20)

add_executable(Console_Editor_Upgraded main.cpp
        Classes/TextEditor/TextEditor.h
        GeneralCommands/structures.cpp
        GeneralCommands/library.h
        Classes/TextEditor/append_newLine.cpp
        Classes/TextEditor/print.cpp
        Classes/TextEditor/insert.cpp
        Classes/TextEditor/search.cpp
        Classes/TextEditor/fileCommands.cpp
        Classes/TextEditor/delete.cpp
        Classes/TextEditor/undo.cpp
        Classes/TextEditor/redo.cpp
        Classes/TextEditor/cut_copy_paste.cpp
        Classes/TextEditor/insert_replacement.cpp
        Classes/TextEditor/set_cursor.cpp
        Classes/ContactInformation/ContactInformation.cpp
        Classes/ContactInformation/ContactInformation.h
        Classes/CheckBox/CheckBox.cpp
        Classes/CheckBox/CheckBox.h
        GeneralCommands/generalCommands.cpp
        Classes/ContactInformation/set_information.cpp
        Classes/ContactInformation/delete_information.cpp
        Classes/ContactInformation/print_information.cpp
        Classes/CheckBox/set_check_box.cpp
        Classes/CheckBox/delete_check_box.cpp
        Classes/CheckBox/print_check_box.cpp)
