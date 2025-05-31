#include "TextEditor.h"

void deleteString(start *first) {
    start *currentChar = first, *previousChar = nullptr;

    while (currentChar != nullptr) {
        previousChar = currentChar;
        currentChar = currentChar->ptr;
        delete previousChar;
    }
}

void TextEditor::cut() {
    std::cout << "Choose line and index and number of symbols:" << std::endl;

    int lineIdx, charIdx, size;
    std::cin >> lineIdx >> charIdx >> size;

    command *cmd = new command;

    internalDelete(lineHead, cmd, lineIdx, charIdx, size);

    deleteString(copyBuffer);
    copyBuffer = cmd->ptr;
    delete cmd;
}

void TextEditor::paste() {
    std::cout << "Choose line and index" << std::endl;

    int lineIdx, charIdx;
    std::cin >> lineIdx >> charIdx;

    command* cmd = new command;
    cmd->cmdNumber = 12;
    cmd->lineNum = lineIdx;
    cmd->index = charIdx;
    cmd->size = getSize(copyBuffer);
    cmd->ptr = copyBuffer;

    internalInsert(lineHead, copyBuffer, lineIdx, charIdx);

    undoStack.push(cmd);
}


void TextEditor::copy() {
    std::cout << "Choose line and index and number of symbols:" << std::endl;

    int lineIdx, charIdx, size, i = 1;
    std::cin >> lineIdx >> charIdx >> size;

    if (size == 0) return;

    start *indexPointer = getCharPointerByIndexes(lineHead, lineIdx, charIdx);
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
