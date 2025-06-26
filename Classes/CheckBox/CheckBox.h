#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "../../GeneralCommands/library.h"
#include "../Frame/Frame.h"
#include <stack>

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
    static void undo(CheckBox &frame, checkBoxCommand *command);
    static void redo(CheckBox &frame, checkBoxCommand *command);

    void setCheckBoxInfo(std::stack<command *> &undoStack, int frameNumber);
    void setCheckBoxStatus(std::stack<command *> &undoStack, int frameNumber);
    void newCheckLine(std::stack<command *> &undoStack, int frameNumber);

    void deleteCheckLine(std::stack<command *> &undoStack, int frameNumber);

    void printContent() override;

    [[nodiscard]] checkLine * getLineHead() const{
        return checkLineHead;
    }

    ~CheckBox() {
        //write full implementation
        delete checkLineHead;
    }
};

#endif //CHECKBOX_H
