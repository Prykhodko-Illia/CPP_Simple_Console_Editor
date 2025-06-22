#ifndef CONTACTINFORMATION_H
#define CONTACTINFORMATION_H

#include "../../GeneralCommands/library.h"

class ContactInformation {
private:
    infoLine *infoLineHead;
    int linesCount;

public:
    ContactInformation() {
        infoLineHead = new infoLine;
        infoLineInitialization(infoLineHead, true);
        linesCount = 1;
    }

    static void printHelpInfo();

    void setInfo();
    void editInfo();
    void newLine();

    void deleteInfo();

    void printInfo() const;

    ~ContactInformation() {
        // write implementation
        delete infoLineHead;
    }

};


#endif //CONTACTINFORMATION_H
