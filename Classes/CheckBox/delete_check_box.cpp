#include "CheckBox.h"

void checkLineInitialization(checkLine *linePointer, bool nextFlag) {
    linePointer->context = nullptr;

    if (nextFlag) {
        linePointer->next = nullptr;
    }
}

void internalDeleteCheckLine(checkLine *&checkLineHead, int lineNumber, checkBoxCommand *cmd, int &linesCount) {
    if (lineNumber == 1) {
        cmd->content = checkLineHead->context;
        cmd->status = checkLineHead->status;

        checkLineInitialization(checkLineHead, false);

        if (checkLineHead->next != nullptr) {
            checkLineHead = dynamic_cast<checkLine *>(checkLineHead->next);
            --linesCount;
        } else {
            cmd->del_first = true;
        }
    } else if (lineNumber >= linesCount) {
        auto *previousLine = dynamic_cast<checkLine *>(getLine(checkLineHead, linesCount - 2));

        auto currentLine = dynamic_cast<checkLine *>(previousLine->next);

        cmd->content = currentLine->context;
        cmd->status = currentLine->status;

        checkLineInitialization(currentLine, true);
        previousLine->next = nullptr;
        delete currentLine;

        --linesCount;
    } else {
        auto previousLine = dynamic_cast<checkLine *>(getLine(checkLineHead, linesCount - 2));
        auto lineToDelete = dynamic_cast<checkLine *>(previousLine->next);

        cmd->content = lineToDelete->context;
        cmd->status = lineToDelete->status;

        previousLine->next = lineToDelete->next;
        delete lineToDelete;

        --linesCount;
    }
}

void CheckBox::deleteCheckLine(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the line number to delete");

    if (lineNumber < 1) {
        std::cout << "Lines numbers are integers";
        return;
    }

    auto cmd = new checkBoxCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 4;
    cmd->lineNumber = lineNumber;

    internalDeleteCheckLine(checkLineHead, lineNumber, cmd, linesCount);

    undoStack.push(cmd);
}