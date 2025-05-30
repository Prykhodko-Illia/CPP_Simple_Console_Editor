#include <iostream>
#include "TextEditor.h"
#include "library.h"
void internalDelete(line *lineHead, command *cmd, int lineNum, int index, int size) {
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
        line *currentLine = lineHead;
        int j = 0;

        while (currentLine->next != nullptr && j < (lineNum - 1)) {
            currentLine = currentLine->next;
            j++;
        }

        if (cmd != nullptr) cmd->lineNum = j + 1;
        currentLine->content = currentChar;
    }
    else indexPointer->ptr = currentChar;

    if (previousChar) previousChar->ptr = nullptr;
}

void TextEditor::deleteContent() {
    std::cout << "Choose line, index and number of symbols" << std::endl;

    int lineNum, index, size, i = 0;
    std::cin >> lineNum >> index >> size;

    if (size == 0) return;

    command *cmd = new command;
    cmd->cmdNumber = 8;
    cmd->lineNum = lineNum;
    cmd->index = index;
    cmd->size = size;

    internalDelete(lineHead, cmd, lineNum, index, size);

    undoStack.push(cmd);

    std::cout << "Succesfully deleted" << std::endl;
}