﻿#include "TextInformation.h"

start * getCharPointerByIndexes(textLine *head, int lineNumber, int charNumber) {
    textLine *currentLine = nullptr;
    currentLine = head;

    for (int i = 1; i < lineNumber; i++) {
        if (currentLine->next == nullptr) {
            break;
        }

        currentLine = dynamic_cast<textLine *>(currentLine->next);
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

void internalInsert(textLine *lineHead, start *newStringFirst, int lineNumber, int index) {
    if (index == 0) {
        textLine *currentLine = nullptr;
        currentLine = lineHead;

        for (int i = 1; i < lineNumber; i++) {
            if (currentLine->next == nullptr) {
                break;
            }

            currentLine = dynamic_cast<textLine *>(currentLine->next);
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
        textLine *currentLine = nullptr;
        currentLine = lineHead;

        for (int i = 1; i < lineNumber; i++) {
            if (currentLine->next == nullptr) {
                break;
            }

            currentLine = dynamic_cast<textLine *>(currentLine->next);
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

void TextInformation::insert(std::stack<command *> &undoStack, int frameNumber) {
    std::cout << "Choose line and index:";
    int lineNumber = 0, index = 0;

    std::cin >> lineNumber >> index;

    auto cmd = new textCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 6;
    cmd->lineNumber = lineNumber;
    cmd->index = index + 1;

    std::string insertText = getInput("Write the text to insert: ");
    start *newStringFirst = nullptr;

    newStringFirst = convertStringToLinkedList(insertText, 32);

    cmd->size = getSize(newStringFirst);
    cmd->content = newStringFirst;

    internalInsert(lineHead, newStringFirst, lineNumber, index);

    undoStack.push(cmd);
}

void TextInformation::insert_replacement(std::stack<command *> &undoStack, int frameNumber) {
    std::string input = getInput("Write the text to insert with replacement: ");
    start *first = convertStringToLinkedList(input, 32);
    int size = getSize(first);

    auto cmd = new textCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 14;
    cmd->lineNumber = cursorLine;
    cmd->index = cursorChar;
    cmd->size = size;

    internalDelete(lineHead, nullptr, cursorLine, cursorChar, size);
    internalInsert(lineHead, first, cursorLine, cursorChar);

    undoStack.push(cmd);
}