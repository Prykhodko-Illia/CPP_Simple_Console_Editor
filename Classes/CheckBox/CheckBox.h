#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "../../GeneralCommands/library.h"

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

    static void printHelpInfo();

    void setCheckBoxInfo();
    void setCheckBoxStatus();
    void newCheckLine();

    void deleteCheckLine();

    void printCheckBox();

    ~CheckBox() {
        //write full implementation
        delete checkLineHead;
    }
};

#endif //CHECKBOX_H
