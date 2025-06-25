#include "CheckBox.h"

void redoSetCheckBoxInfo(checkLine *checkLineHead, checkBoxCommand *command) {
    auto line = dynamic_cast<checkLine *>(getLine(checkLineHead, command->lineNumber));

    internalSetCheckBoxInfo(line, command->content, command);
}

void redoSetCheckBoxStatus(checkLine *checkLineHead, checkBoxCommand *command) {
    auto line = dynamic_cast<checkLine *>(getLine(checkLineHead, command->lineNumber));

    internalSetCheckBoxStatus(line, command->status, command);
}

void redoNewCheckLine(checkLine *checkLineHead, checkBoxCommand *command) {
    auto newLine = new checkLine;

    newLine->context = command->content;
    newLine->status = command->status;
    newLine->next = nullptr;

    auto lastLine = dynamic_cast<checkLine *>(getLastLine(checkLineHead));
    lastLine->next = newLine;
}

void redoDeleteCheckLine(checkLine *&checkLineHead, checkBoxCommand *command, int linesCount) {
    internalDeleteCheckLine(checkLineHead, command->lineNumber, command, linesCount);
}

void CheckBox::redo(CheckBox &frame, checkBoxCommand *command) {
    switch (command->cmdNumber) {
        case 1:
            redoSetCheckBoxInfo(frame.checkLineHead, command);
            break;
        case 2:
            redoSetCheckBoxStatus(frame.checkLineHead, command);
            break;
        case 3:
            redoNewCheckLine(frame.checkLineHead, command);
            ++frame.linesCount;
            break;
        case 4:
            redoDeleteCheckLine(frame.checkLineHead, command, frame.linesCount);
            break;
        default:
            break;
    }
}