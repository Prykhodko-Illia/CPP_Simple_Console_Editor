#include <iostream>
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

int getSize(start *head) {
    int size = 0;
    while (head != nullptr) {
        head = head->ptr;
        size++;
    }

    return size;
}

void internalAppend(line *lineHead, start *newText) {
    line * lastLine = nullptr;
    lastLine = getLastLine(lineHead);

    start *lastChar = nullptr;

    if (lastLine->content == nullptr)  lastLine->content = newText;
    else {
        lastChar = lastLine->content;
        while (lastChar->ptr != nullptr) {
            lastChar = lastChar->ptr;
        }
        lastChar->ptr = newText;
    }
}

void TextEditor::append() {
    std::string input = getInput();

    start *newText = nullptr;
    newText = convertStringToLinkedList(input, 32);

    int size = getSize(newText);

    command *cmd = new command;
    cmd->cmdNumber = 1;
    cmd->ptr = newText;
    cmd->size = size;

    undoStack.push(cmd);

    internalInsert(lineHead, newText, cursorLine, cursorChar);

    cursorChar += size;

    std::cout << std::endl << "Successfully added" << std::endl;
}

void internalNewLine(line *lineHead) {
    line *newLine = nullptr;
    newLine = new line;
    newLine->content = nullptr;
    newLine->next = nullptr;

    getLastLine(lineHead)->next = newLine;
}

void internalNewCursorLine(line *lineHead, int lineIdx) {
    line *newLine = nullptr;
    newLine = new line;
    newLine->content = nullptr;
    newLine->next = nullptr;

    line *current = lineHead;
    int i = 1;
    while (current->next != nullptr && i < lineIdx) {
        current = current->next;
        i++;
    }

    if (current->next) newLine->next = current->next;
    current->next = newLine;
}

void TextEditor::newLine() {
    internalNewCursorLine(lineHead, cursorLine);
    cursorLine++;
    cursorChar = 0;

    command *cmd = new command;
    cmd->cmdNumber = 2;
    undoStack.push(cmd);


    std::cout << "New line is started" << std::endl;
}
