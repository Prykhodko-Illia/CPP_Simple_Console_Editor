cmake_minimum_required(VERSION 3.31)
project(Console_Editor_Upgraded)

set(CMAKE_CXX_STANDARD 20)

add_executable(Console_Editor_Upgraded main.cpp
        Classes/ConsoleEditor/ConsoleEditor.h
        GeneralCommands/structures.cpp
        GeneralCommands/library.h
        Classes/ConsoleEditor/print.cpp
        Classes/ConsoleEditor/fileCommands.cpp
        Classes/ConsoleEditor/undo.cpp
        Classes/ConsoleEditor/redo.cpp
        Classes/ContactInformation/ContactInformation.h
        Classes/CheckBox/CheckBox.h
        GeneralCommands/generalCommands.cpp
        Classes/ContactInformation/set_information.cpp
        Classes/ContactInformation/delete_information.cpp
        Classes/ContactInformation/print_information.cpp
        Classes/CheckBox/set_check_box.cpp
        Classes/CheckBox/delete_check_box.cpp
        Classes/CheckBox/print_check_box.cpp
        Classes/TextInformation/TextInformation.h
        Classes/TextInformation/set_text.cpp
        Classes/TextInformation/insert_text.cpp
        Classes/TextInformation/search_text.cpp
        Classes/TextInformation/set_cursor_text.cpp
        Classes/TextInformation/delete_text.cpp
        Classes/TextInformation/cut_copy_paste_text.cpp
        Classes/TextInformation/print_text.cpp)
