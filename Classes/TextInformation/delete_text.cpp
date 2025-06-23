#include "TextInformation.h"

void internalDelete(textLine *lineHead, command *cmd, int lineNum, int index, int size) {
    int i = 0;

    start *indexPointer = getCharPointerByIndexes(lineHead, lineNum, index - 1);
    start *currentChar = nullptr, *previousChar = nullptr;

    if (index == 0) currentChar = indexPointer;
    else currentChar = indexPointer->ptr;

    if (cmd != nullptr) cmd->ptr = currentChar;

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

        if (cmd != nullptr) cmd->lineNum = j + 1;
        currentLine->content = currentChar;
    }
    else indexPointer->ptr = currentChar;

    if (previousChar) previousChar->ptr = nullptr;
}

void TextInformation::deleteContent() {
    // std::cout << "Choose line, index and number of symbols" << std::endl;
    //
    // int lineNum, index, size;
    // std::cin >> lineNum >> index >> size;

    std::cout << "Choose number of size to delete" << std::endl;
    int size;
    std::cin >> size;

    if (size == 0) return;

    // command *cmd = new command;
    // cmd->cmdNumber = 8;
    // cmd->lineNum = cursorLine;
    // cmd->index = cursorChar;
    // cmd->size = size;

    internalDelete(lineHead, nullptr, cursorLine, cursorChar, size);

    // undoStack.push(cmd);

    std::cout << "Succesfully deleted" << std::endl;
}