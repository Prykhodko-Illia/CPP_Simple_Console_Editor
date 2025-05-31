#include <iostream>
#include "TextEditor.h"
#include "library.h"

start * getCharPointerByIndexes(line *head, int lineNumber, int charNumber) {
    line *currentLine = nullptr;
    currentLine = head;

    for (int i = 1; i < lineNumber; i++) {
        if (currentLine->next == nullptr) {
            break;
        }

        currentLine = currentLine->next;
    }

    start *currentChar = nullptr;
    if (currentLine->content == nullptr) return nullptr;
    currentChar = currentLine->content;


    for (int i = 1; i < charNumber; i++) {
        if (currentChar->ptr == nullptr) {
            break;
        }

        currentChar = currentChar->ptr;
    }

    return currentChar;
}

void internalInsert(line *lineHead, start *newStringFirst, int lineNumber, int index) {
    if (index == 0) {
        line *currentLine = nullptr;
        currentLine = lineHead;

        for (int i = 1; i < lineNumber; i++) {
            if (currentLine->next == nullptr) {
                break;
            }

            currentLine = currentLine->next;
        }

        if (currentLine->content == nullptr) currentLine->content = newStringFirst;
        else {
            start *currentChar = newStringFirst;
            while (currentChar->ptr != nullptr) currentChar = currentChar->ptr;

            currentChar->ptr = currentLine->content;
            currentLine->content = newStringFirst;
        }

        return;
    }

    start *indexPointer = getCharPointerByIndexes(lineHead, lineNumber, (index - 1));

    if (indexPointer == nullptr) {
        line *currentLine = nullptr;
        currentLine = lineHead;

        for (int i = 1; i < lineNumber; i++) {
            if (currentLine->next == nullptr) {
                break;
            }

            currentLine = currentLine->next;
        }

        currentLine->content = newStringFirst;
    } else {
        start *newStringLast = nullptr;
        newStringLast = newStringFirst;

        while (newStringLast->ptr != nullptr) {
            newStringLast = newStringLast->ptr;
        }

        newStringLast->ptr = indexPointer->ptr;
        indexPointer->ptr = newStringFirst;
    }
};

void TextEditor::insert() {
    std::cout << "Choose line and index:";
    int lineNumber = 0, index = 0;

    std::cin >> lineNumber >> index;

    command* cmd = new command;
    cmd->cmdNumber = 6;
    cmd->lineNum = lineNumber;
    cmd->index = index + 1;

    std::string insertText = getInput(); //TODO: customize user input
    start *newStringFirst = nullptr;

    newStringFirst = convertStringToLinkedList(insertText, 32);

    cmd->size = getSize(newStringFirst);
    cmd->ptr = newStringFirst;

    internalInsert(lineHead, newStringFirst, lineNumber, index);

    undoStack.push(cmd);
}