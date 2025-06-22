#include "CheckBox.h"

void CheckBox::setCheckBoxInfo() {
    checkLine * newLine = dynamic_cast<checkLine *>(
        getLine(checkLineHead, getNumber("Write the checkbox number to edit the info")));

    start * input = convertStringToLinkedList(getInput(), 32);
    deleteString(newLine->context);

    newLine->context = input;
}

void CheckBox::setCheckBoxStatus() {
    checkLine * lineNum = dynamic_cast<checkLine *>(
        getLine(checkLineHead, getNumber("Write the checkbox number to set the status")));

    const int status = getNumber("Write 1 to check, 0 - to uncheck");
    if (status == 1) lineNum->status = true;
    if (status == 0) lineNum->status = false;
}

void CheckBox::newCheckLine() {
    checkLineHead->next = new checkLine;

    {
        auto *newLine = dynamic_cast<checkLine *>(checkLineHead->next);
        start * input = convertStringToLinkedList(getInput(), 32);
        newLine->context = input;
    }

    ++linesCount;
}