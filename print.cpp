#include <iostream>

#include "TextEditor.h"

void TextEditor::printHelpInfo() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "1 - append to the last" << std::endl;
    std::cout << "2 - start new line" << std::endl;
    std::cout << "3 - saving to file" << std::endl;
    std::cout << "5 - print all text" << std::endl;
    std::cout << "6 - insert at [line] [index]" << std::endl;
    std::cout << "7 - searching string in the text" << std::endl;
    std::cout << "8 - delete at [line] [index]" << std::endl;
    std::cout << "9 - undo command" << std::endl;
    std::cout << "10 - redo command" << std::endl;
    std::cout << "11 - undo command" << std::endl;
    std::cout << "12 - cut command" << std::endl;
    std::cout << "13 - paste command" << std::endl;
    std::cout << "14 - copy command" << std::endl;
    std::cout << std::endl;
    std::cout << "0 - end execution" << std::endl;
    std::cout << std::endl;
}

std::string getInput() {
    std::cout << "Enter text to append: "  << std::endl;;

    std::string input;
    std::cin.ignore();

    std::getline(std::cin, input);

    return input;
}

void printString(start *head) {
    start *temp = nullptr;
    temp = head;

    int i = 0;
    while ((temp->ptr != nullptr) && (i < 1000)) {
        std::cout << temp->value;
        temp = temp->ptr;
        i++;
    }

    std::cout << temp->value  << std::endl;;
}

void TextEditor::printAll() {
    line *temporary = nullptr;
    temporary = lineHead;

    while ((temporary)->next != nullptr) {
        if (temporary->content != nullptr) {
            printString(temporary->content);
        } else {
            std::cout  << std::endl;;
        }
        temporary = temporary->next;
    }

    if (temporary->content != nullptr) {
        printString(temporary->content);
    } else {std::cout  << std::endl;;}
}
