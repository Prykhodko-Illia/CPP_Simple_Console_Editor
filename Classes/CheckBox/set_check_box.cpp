#include "CheckBox.h"

void internalSetCheckBoxInfo(checkLine *newLine, start *input, checkBoxCommand *cmd) {
    cmd->content = newLine->context;
    newLine->context = input;
}

void internalSetCheckBoxStatus(checkLine *lineNum, bool status, checkBoxCommand *cmd) {
    cmd->status = lineNum->status;
    if (status) lineNum->status = true;
    else lineNum->status = false;
}

void CheckBox::setCheckBoxInfo(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the checkbox number to edit the info");
    start * input = convertStringToLinkedList(getInput("Write the text for the checkbox: "), 32);

    auto newLine = dynamic_cast<checkLine *>(getLine(checkLineHead, lineNumber));

    auto cmd = new checkBoxCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 1;
    cmd->lineNumber = lineNumber;

    internalSetCheckBoxInfo(newLine, input, cmd);

    undoStack.push(cmd);
}

void CheckBox::setCheckBoxStatus(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the checkbox number to set the status");
    int status = getNumber("Write 1 to check, 0 - to uncheck");

    auto lineNum = dynamic_cast<checkLine *>(getLine(checkLineHead, lineNumber));

    auto cmd = new checkBoxCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 2;
    cmd->lineNumber = lineNumber;

    internalSetCheckBoxStatus(lineNum, status, cmd);

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
        start * input = convertStringToLinkedList(getInput("Write the text for the checkbox: "), 32);
        newLine->context = input;
    }

    ++linesCount;
    undoStack.push(cmd);
}