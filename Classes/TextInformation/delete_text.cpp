#include "TextInformation.h"

void internalDelete(textLine *lineHead, textCommand *cmd, int lineNum, int index, int size) {
    int i = 0;

    start *indexPointer = getCharPointerByIndexes(lineHead, lineNum, index - 1);
    start *currentChar = nullptr, *previousChar = nullptr;

    if (index == 0) currentChar = indexPointer;
    else currentChar = indexPointer->ptr;

    if (cmd != nullptr) cmd->content = currentChar;

    while (currentChar != nullptr && i < size) {
        previousChar = currentChar;
        currentChar = currentChar->ptr;
        i++;
    }

    if (index == 0) {
        textLine *currentLine = lineHead;
        int j = 0;

        while (currentLine->next != nullptr && j < (lineNum - 1)) {
            currentLine = dynamic_cast<textLine *>(currentLine->next);
            j++;
        }

        if (cmd != nullptr) cmd->lineNumber = j + 1;
        currentLine->content = currentChar;
    }
    else indexPointer->ptr = currentChar;

    if (previousChar) previousChar->ptr = nullptr;
}

void TextInformation::deleteContent(std::stack<command *> &undoStack, int frameNumber) {
    std::cout << "Choose number of size to delete" << std::endl;
    int size;
    std::cin >> size;

    if (size == 0) return;

    auto cmd = new textCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 8;
    cmd->lineNumber = cursorLine;
    cmd->index = cursorChar;
    cmd->size = size;

    internalDelete(lineHead, nullptr, cursorLine, cursorChar, size);

    undoStack.push(cmd);

    std::cout << "Succesfully deleted" << std::endl;
}