#include "TextEditor.h"

void redoAppend(line *lineHead, command *currentCommand) {
    internalAppend(lineHead, currentCommand->ptr);
}

void redoNewLine(line *lineHead) {
    internalNewLine(lineHead);
};

void redoInsert(line *lineHead, command *currentCommand) {
    internalInsert(lineHead, nullptr, currentCommand->ptr, currentCommand->lineNum, currentCommand->index);
}

void redoDelete(line *lineHead, command *currentCommand) {
    internalDelete(lineHead, nullptr, currentCommand->lineNum, currentCommand->index, currentCommand->size);
}

void TextEditor::redo() {
    if (redoStack.empty()) {
        std::cout << "The stack is empty" << std::endl;
        return;
    }

    command *currentCommand = redoStack.top();
    switch (currentCommand->cmdNumber) {
        case 1:
            redoAppend(lineHead, currentCommand);
            break;
        case 2:
            redoNewLine(lineHead);
            break;
        case 6:
            redoInsert(lineHead, currentCommand);
            break;
        case 8:
            redoDelete(lineHead, currentCommand);
            break;
        default:
            return;
    }

    redoStack.pop();
    undoStack.push(currentCommand);
}