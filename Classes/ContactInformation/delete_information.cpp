#include "ContactInformation.h"

void infoLineClearing(infoLine *linePointer, bool nextFlag) {
    deleteString(linePointer->name);
    deleteString(linePointer->surname);
    deleteString(linePointer->email);

    if (nextFlag) {
        linePointer->next = nullptr;
    }
}

void internalDeleteInfo(infoLine *&infoLineHead, int lineNumber, contactCommand *cmd, int &linesCount) {
    if (lineNumber == 1) {
        cmd->name = infoLineHead->name;
        cmd->surname = infoLineHead->surname;
        cmd->email = infoLineHead->email;

        infoLineInitialization(infoLineHead, false);

        if (infoLineHead->next != nullptr) {
            infoLineHead = dynamic_cast<infoLine *>(infoLineHead->next);
            --linesCount;
        } else {
            cmd->del_first = true;
        }
    } else if (lineNumber >= linesCount) {
        auto previousLine = dynamic_cast<infoLine *>(getLine(infoLineHead, linesCount - 2));

        auto currentLine = dynamic_cast<infoLine *>(previousLine->next);

        cmd->name = currentLine->name;
        cmd->surname = currentLine->surname;
        cmd->email = currentLine->email;

        infoLineClearing(currentLine, true);
        previousLine->next = nullptr;
        delete currentLine;

        --linesCount;
    } else {
        auto previousLine = dynamic_cast<infoLine *>(getLine(infoLineHead, linesCount - 2));
        auto lineToDelete = dynamic_cast<infoLine *>(previousLine->next);

        cmd->name = lineToDelete->name;
        cmd->surname = lineToDelete->surname;
        cmd->email = lineToDelete->email;

        previousLine->next = lineToDelete->next;
        delete lineToDelete;

        --linesCount;
    }
}

void ContactInformation::deleteInfo(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the line number to delete");

    if (lineNumber < 1) {
        std::cout << "Lines numbers are integers";
        return;
    }

    auto cmd = new contactCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 4;
    cmd->lineNumber = lineNumber;

    internalDeleteInfo(infoLineHead, lineNumber, cmd, linesCount);

    undoStack.push(cmd);
}