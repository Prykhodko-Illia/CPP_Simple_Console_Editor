#ifndef CONTACTINFORMATION_H
#define CONTACTINFORMATION_H

#include "../../GeneralCommands/library.h"
#include "../Frame/Frame.h"
#include <stack>

class ContactInformation : public Frame {
private:
    infoLine *infoLineHead = nullptr;
    int linesCount = 0;

public:
    ContactInformation() {
        infoLineHead = new infoLine;
        infoLineInitialization(infoLineHead, true);
        linesCount = 1;
        scopeId = 2;
    }

    static void printHelpInfo();
    static void undo(ContactInformation &frame, contactCommand *command);
    static void redo(ContactInformation &frame, contactCommand *command);

    void setInfo(std::stack<command *> &undoStack, int frameNumber);
    void editInfo(std::stack<command *> &undoStack, int frameNumber);
    void newLine(std::stack<command *> &undoStack, int frameNumber);

    void deleteInfo(std::stack<command *> &undoStack, int frameNumber);

    void printContent() override;

    infoLine * getLineHead() {
        return infoLineHead;
    }

    ~ContactInformation() {
        // write implementation
        delete infoLineHead;
    }

};


#endif //CONTACTINFORMATION_H
