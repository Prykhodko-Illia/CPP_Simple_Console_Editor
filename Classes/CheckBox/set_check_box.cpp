#include "CheckBox.h"

void internalSetCheckBoxInfo(checkLine *checkLineHead, start *input, int lineNumber, checkBoxCommand *cmd) {
    auto newLine = dynamic_cast<checkLine *>(getLine(checkLineHead, lineNumber));

    cmd->content = newLine->context;
    newLine->context = input;
}

void internalSetCheckBoxStatus(checkLine *checkLineHead, int status, int lineNumber, checkBoxCommand *cmd) {
    auto lineNum = dynamic_cast<checkLine *>(getLine(checkLineHead, lineNumber));

    cmd->status = lineNum->status;
    if (status == 1) lineNum->status = true;
    if (status == 0) lineNum->status = false;
}

void CheckBox::setCheckBoxInfo(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the checkbox number to edit the info");
    start * input = convertStringToLinkedList(getInput(), 32);

    auto cmd = new checkBoxCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 1;
    cmd->lineNumber = lineNumber;

    internalSetCheckBoxInfo(checkLineHead, input, lineNumber, cmd);

    undoStack.push(cmd);
}

void CheckBox::setCheckBoxStatus(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the checkbox number to set the status");
    int status = getNumber("Write 1 to check, 0 - to uncheck");

    auto cmd = new checkBoxCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 2;
    cmd->lineNumber = lineNumber;

    internalSetCheckBoxStatus(checkLineHead, status, lineNumber, cmd);

    undoStack.push(cmd);
}

void CheckBox::newCheckLine(std::stack<command *> &undoStack, int frameNumber) {
    auto lastLine = dynamic_cast<checkLine *>(getLastLine(checkLineHead));
    lastLine->next = new checkLine;

    auto cmd = new checkBoxCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 3;

    {
        auto newLine = dynamic_cast<checkLine *>(lastLine->next);
        start * input = convertStringToLinkedList(getInput(), 32);
        newLine->context = input;
    }

    ++linesCount;
    undoStack.push(cmd);
}