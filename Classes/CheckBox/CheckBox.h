#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "../../GeneralCommands/library.h"
#include "../Frame/Frame.h"

class CheckBox : public Frame {
private:
    checkLine *checkLineHead = nullptr;
    int linesCount;

public:
    CheckBox() {
        checkLineHead = new checkLine;
        checkLineHead->context = nullptr;
        checkLineHead->next = nullptr;

        linesCount = 1;
        scopeId = 3;
    }

    static void printHelpInfo();

    void setCheckBoxInfo();
    void setCheckBoxStatus();
    void newCheckLine();

    void deleteCheckLine();

    void printContent() override;

    checkLine * getLineHead() {
        return checkLineHead;
    }

    ~CheckBox() {
        //write full implementation
        delete checkLineHead;
    }
};

#endif //CHECKBOX_H
