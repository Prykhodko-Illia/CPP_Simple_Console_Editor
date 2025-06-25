#include "CheckBox.h"

void undoSetCheckBoxInfo(checkLine *checkLineHead, checkBoxCommand *command) {
    auto lineNum =  dynamic_cast<checkLine *>(getLine(checkLineHead, command->lineNumber));
    internalSetCheckBoxInfo(lineNum, command->content, command);
}

void undoSetCheckBoxStatus(checkLine *checkLineHead, checkBoxCommand *command) {
    auto lineNum =  dynamic_cast<checkLine *>(getLine(checkLineHead, command->lineNumber));
    internalSetCheckBoxStatus(lineNum, command->status, command);
}

void undoNewCheckLine(checkLine *checkLineHead, checkBoxCommand *command, int &linesCount) {
    auto previousLine = dynamic_cast<checkLine *>(getLine(checkLineHead, linesCount - 1));
    auto lastLine = dynamic_cast<checkLine *>(previousLine->next);

    command->content = lastLine->context;

    checkLineInitialization(lastLine, true);
    delete lastLine;

    previousLine->next = nullptr;
}

void undoDeleteCheckLine(checkLine *&checkLineHead, checkBoxCommand *command) {
    auto newLine = new checkLine;
    checkLineInitialization(newLine, true);

    internalSetCheckBoxInfo(newLine, command->content, command);
    internalSetCheckBoxStatus(newLine, command->status, command);

    if (command->lineNumber == 1) {
        if (command->del_first == false) {
            newLine->next = checkLineHead;
        }

        checkLineHead = newLine;
        return;
    }

    auto previousLine = getLine(checkLineHead, (command->lineNumber - 1));
    newLine->next = previousLine->next;
    previousLine->next = newLine;
}

void CheckBox::undo(CheckBox &frame, checkBoxCommand *command) {
    switch (command->cmdNumber) {
        case 1:
            undoSetCheckBoxInfo(frame.checkLineHead, command);
            break;
        case 2:
            undoSetCheckBoxStatus(frame.checkLineHead, command);
            break;
        case 3:
            undoNewCheckLine(frame.checkLineHead, command, frame.linesCount);
            --frame.linesCount;
            break;
        case 4:
            undoDeleteCheckLine(frame.checkLineHead, command);
            if (command->del_first == false) ++frame.linesCount;
            break;
        default:
            break;
    }
}