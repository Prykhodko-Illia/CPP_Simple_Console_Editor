#include <iostream>
#include <string>
#include "TextEditor.h"

line * getLastLine(line * firstLine) {
    line *temporary = nullptr;
    temporary = firstLine;

    int i = 0;
    while (temporary->next != nullptr) {
        temporary = temporary->next;
        i++;

        if (i > 1000) {
            std::cout << "Error in getting last line";
            break;
        }
    }

    return temporary;
}

start * convertStringToLinkedList(std::string input, int size) {
    start *head = nullptr;
    head = new start;
    head->value = input[0];
    head->ptr = nullptr;

    start *temp = nullptr;
    temp = head;

    for (int i = 1; (input[i] != '\n') && (i < size) && (input[i] != '\0'); i++) {
        start *nextChar = nullptr;
        nextChar = new start;
        nextChar->value = input[i];
        nextChar->ptr = nullptr;

        temp->ptr = nextChar;
        temp = nextChar;
    }

    return head;
}

void TextEditor::append() {
    std::string input = getInput();

    line * lastLine = nullptr;
    lastLine = getLastLine(lineHead);

    start *newText = nullptr;
    newText = convertStringToLinkedList(input, 32);

    start *lastChar = nullptr;
    if (lastLine->content == nullptr) {
        lastLine->content = newText;
        std::cout << std::endl << "Successfully added" << std::endl;
        return;
    }

    lastChar = lastLine->content;
    while (lastChar->ptr != nullptr) {
        lastChar = lastChar->ptr;
    }

    lastChar->ptr = newText;

    std::cout << std::endl << "Successfully added" << std::endl;
}

void TextEditor::newLine() {
    line *newLine = nullptr;
    newLine = new line;
    newLine->content = nullptr;
    newLine->next = nullptr;

    getLastLine(lineHead)->next = newLine;

    std::cout << "New line is started" << std::endl;
}
