#include "TextInformation.h"

void TextInformation::cut() {
    std::cout << "Choose number of symbols to cut" << std::endl;
    int size;
    std::cin >> size;

    auto *cmd = new textCommand;

    internalDelete(lineHead, cmd, cursorLine, cursorChar, size);

    deleteString(copyBuffer);
    copyBuffer = cmd->content;
    delete cmd;
}

void TextInformation::paste(std::stack<command *> &undoStack, int frameNumber) {
    int size = getSize(copyBuffer);

    auto cmd = new textCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 12;
    cmd->lineNumber = cursorLine;
    cmd->index = cursorChar;
    cmd->size = size;
    cmd->content = copyBuffer;

    internalInsert(lineHead, copyBuffer, cursorLine, cursorChar);
    cursorChar += size;

    undoStack.push(cmd);
}


void TextInformation::copy() {
    std::cout << "Choose number of symbols to copy" << std::endl;
    int size, i = 1;
    std::cin >> size;

    if (size == 0) return;

    start *indexPointer = getCharPointerByIndexes(lineHead, cursorLine, cursorChar);
    start *currentChar = nullptr;

    currentChar = new start;
    currentChar->ptr = nullptr;
    currentChar->value = indexPointer->value;

    deleteString(copyBuffer);
    copyBuffer = currentChar;

    while (indexPointer->ptr != nullptr && i < size) {
        currentChar->ptr = new start;
        currentChar = currentChar->ptr;
        indexPointer = indexPointer->ptr;
        currentChar->value = indexPointer->value;
        i++;
    }

    currentChar->ptr = nullptr;
}
