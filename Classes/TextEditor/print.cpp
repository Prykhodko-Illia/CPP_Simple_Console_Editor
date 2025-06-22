#include <iostream>

#include "TextEditor.h"

void TextEditor::printHelpInfo() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "1 - append to the last" << std::endl;
    std::cout << "2 - start new line" << std::endl;
    std::cout << "3 - saving to file" << std::endl;
    std::cout << "4 - load from file";
    std::cout << "5 - print all text" << std::endl;
    std::cout << "6 - insert at [line] [index]" << std::endl;
    std::cout << "7 - searching string in the text" << std::endl;
    std::cout << "8 - delete" << std::endl;
    std::cout << "9 - undo" << std::endl;
    std::cout << "10 - redo" << std::endl;
    std::cout << "11 - cut" << std::endl;
    std::cout << "12 - paste" << std::endl;
    std::cout << "13 - copy" << std::endl;
    std::cout << "14 - insert with replacement" <<std::endl;
    std::cout << "15 - set cursor" << std::endl;
    std::cout << std::endl;
    std::cout << "0 - end execution" << std::endl;
    std::cout << std::endl;
}

void TextEditor::printAll() {
    textLine *temporary = nullptr;
    temporary = lineHead;

    while ((temporary)->next != nullptr) {
        if (temporary->content != nullptr) {
            printString(temporary->content);
        } else {
            std::cout  << std::endl;;
        }
        temporary = dynamic_cast<textLine *>(temporary->next);
    }

    if (temporary->content != nullptr) {
        printString(temporary->content);
    } else {std::cout  << std::endl;;}
}
