cmake_minimum_required(VERSION 3.31)
project(Console_Editor_Upgraded)

set(CMAKE_CXX_STANDARD 20)

add_executable(Console_Editor_Upgraded main.cpp
        Classes/ConsoleEditor/ConsoleEditor.h
        GeneralCommands/structures.cpp
        GeneralCommands/library.h
        Classes/ConsoleEditor/fileCommands.cpp
        Classes/TextInformation/undo_text.cpp
        Classes/TextInformation/redo_text.cpp
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
        Classes/TextInformation/print_text.cpp
        Scopes/check_box_scope.cpp
        Scopes/text_information_scope.cpp
        Scopes/contact_information_scope.cpp
        Classes/TextInformation/print_help_text.cpp
        Scopes/scopes.h
        Classes/ContactInformation/print_help_information.cpp
        Classes/CheckBox/print_help_check_box.cpp
        Classes/Frame/Frame.h
        Classes/classes.h
        Scopes/main_scope.cpp
        Classes/ConsoleEditor/print_help_console_editor.cpp
        Classes/ConsoleEditor/create_new_frame_console_editor.cpp
        Classes/ConsoleEditor/edit_frame_console_editor.cpp
        Classes/ConsoleEditor/delete_frame_console_editor.cpp
        Classes/ConsoleEditor/print_all_console_editor.cpp
        Classes/ConsoleEditor/encrypt_console_editor.cpp
        Classes/ConsoleEditor/undo_console_editor.cpp
        Classes/ConsoleEditor/redo_console_editor.cpp
        Classes/ContactInformation/undo_information.cpp
)
