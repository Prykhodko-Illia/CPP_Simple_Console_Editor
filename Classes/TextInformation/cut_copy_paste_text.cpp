#include "TextInformation.h"

void TextInformation::cut() {
    // std::cout << "Choose line and index and number of symbols:" << std::endl;
    //
    // int lineIdx, charIdx, size;
    // std::cin >> lineIdx >> charIdx >> size;

    std::cout << "Choose number of symbols to cut" << std::endl;
    int size;
    std::cin >> size;

    command *cmd = new command;

    internalDelete(lineHead, cmd, cursorLine, cursorChar, size);

    deleteString(copyBuffer);
    copyBuffer = cmd->ptr;
    delete cmd;
}

void TextInformation::paste() {
    // std::cout << "Choose line and index" << std::endl;
    //
    // int lineIdx, charIdx;
    // std::cin >> lineIdx >> charIdx;

    int size = getSize(copyBuffer);
    //
    // command* cmd = new command;
    // cmd->cmdNumber = 12;
    // cmd->lineNum = cursorLine;
    // cmd->index = cursorChar;
    // cmd->size = size;
    // cmd->ptr = copyBuffer;

    internalInsert(lineHead, copyBuffer, cursorLine, cursorChar);
    cursorChar += size;

    // undoStack.push(cmd);
}


void TextInformation::copy() {
    // std::cout << "Choose line and index and number of symbols:" << std::endl;
    //
    // int lineIdx, charIdx, size, i = 1;
    // std::cin >> lineIdx >> charIdx >> size;

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
