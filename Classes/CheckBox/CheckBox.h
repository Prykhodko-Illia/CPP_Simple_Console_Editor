#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "../../GeneralCommands/library.h"
#include "../../GeneralCommands/structures.cpp"

class CheckBox {
private:
    checkLine *checkLineHead = nullptr;
    int linesCount;

public:
    CheckBox() {
        checkLineHead = new checkLine;
        checkLineHead->context = nullptr;
        checkLineHead->next = nullptr;

        linesCount = 1;
    }

    void setCheckBoxInfo();
    void setCheckBoxStatus();
    void newCheckLine();

    void deleteCheckLine();

    void printCheckbox();

    ~CheckBox() {
        //write full implementation
        delete checkLineHead;
    }
};

#endif //CHECKBOX_H
