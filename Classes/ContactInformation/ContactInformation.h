#ifndef CONTACTINFORMATION_H
#define CONTACTINFORMATION_H

#include "../../GeneralCommands/library.h"
#include "../Frame/Frame.h"

class ContactInformation : public Frame {
private:
    infoLine *infoLineHead;
    int linesCount;

public:
    ContactInformation() {
        infoLineHead = new infoLine;
        infoLineInitialization(infoLineHead, true);
        linesCount = 1;
        scopeId = 2;
    }

    static void printHelpInfo();

    void setInfo();
    void editInfo();
    void newLine();

    void deleteInfo();

    void printContent() override;

    ~ContactInformation() {
        // write implementation
        delete infoLineHead;
    }

};


#endif //CONTACTINFORMATION_H
