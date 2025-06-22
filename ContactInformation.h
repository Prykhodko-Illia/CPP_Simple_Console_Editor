#ifndef CONTACTINFORMATION_H
#define CONTACTINFORMATION_H

#include "structures.cpp"
#include "library.h"

int getNumber(const std::string text) {
    int line = 0;

    std::cout << "Write" << text << "number" << std::endl;
    std::cin >> line;

    return line;
}

infoLine * getLine(infoLine *infoLineHead, int line) {
    int i = 0;

    infoLine *temp = infoLineHead;
    while (temp->next != nullptr && i < line) {
        temp = dynamic_cast<infoLine *>(temp->next);
        ++i;
    }

    return temp;
}

void setInField(infoLine *line, const std::string fieldName) {
    std::cout << "Write " << fieldName << " to set in: " << std::endl;

    start *value;

    {
        std::string input;
        std::cin >> input;

        value = convertStringToLinkedList(input, input.length());
    }

    if (fieldName == "name") line->name = value;
    if (fieldName == "surname") line->surname = value;
    if (fieldName == "email") line->email = value;
}

void infoLineInitialization(infoLine *linePointer) {
    linePointer->name = nullptr;
    linePointer->surname = nullptr;
    linePointer->email = nullptr;
    linePointer->next = nullptr;
}

void infoLineClearing(infoLine *linePointer, bool nextFlag) {
    linePointer->name = nullptr;
    linePointer->surname = nullptr;
    linePointer->email = nullptr;

    if (nextFlag) {
        linePointer->next = nullptr;
    }
}

class ContactInformation {
private:
    infoLine *infoLineHead;
    int linesCount;

public:
    ContactInformation() {
        infoLineHead = new infoLine;
        infoLineInitialization(infoLineHead);
        linesCount = 1;
    }

    void SetInfo() {
        infoLine *newLine = getLine(infoLineHead, getNumber("the line to set info "));

        setInField(newLine, "name");
        setInField(newLine, "surname");
        setInField(newLine, "email");
    }

    void EditInfo() {
        infoLine *newLine = getLine(infoLineHead, getNumber("the line to edit "));

        int fN = 0, fS = 0, fE = 0;
        std::cout << "Write 1 if you want to edit: Name/Surname/Email "
                     "(ex: 1 0 1) - sets all except surname" << std::endl;

        std::cin >> fN >> fS >> fE;
        if (fN == 1) setInField(newLine, "name");
        if (fS == 1) setInField(newLine, "surname");
        if (fE == 1) setInField(newLine, "email");
    }

    void newLine() {
        infoLineHead->next = new infoLine;

        infoLine *newLine = dynamic_cast<infoLine *>(infoLineHead->next);
        infoLineInitialization(newLine);

        ++linesCount;
    }

    void DeleteInfo() {
        int line = getNumber("the line to delete ");

        if (line < 1) {
            std::cout << "Lines numbers are integers";
            return;
        }

        if (line == 1) {
            infoLineClearing(infoLineHead, false);

            if (infoLineHead->next != nullptr) {
                infoLineHead = dynamic_cast<infoLine *>(infoLineHead->next);
                --linesCount;
            }
        } else if (line >= linesCount) {
            infoLine *previousLine = getLine(infoLineHead, linesCount - 1);
            infoLineClearing(dynamic_cast<infoLine *>(previousLine->next), true);

            previousLine->next = nullptr;
            --linesCount;
        } else {
            infoLine *previousLine = getLine(infoLineHead, linesCount - 1);
            infoLine *lineToDelete = dynamic_cast<infoLine *>(previousLine->next);

            infoLineClearing(lineToDelete, false);
            previousLine->next = lineToDelete->next;

            delete lineToDelete;
            --linesCount;
        }
    }

    void PrintInfo() const {
        std::cout << "Contact - " << infoLineHead->name << " " << infoLineHead->surname << ", E-mail: " << infoLineHead->email << std::endl;
    }

    ~ContactInformation() {
        // write implementation
        delete infoLineHead;
    }

};


#endif //CONTACTINFORMATION_H
