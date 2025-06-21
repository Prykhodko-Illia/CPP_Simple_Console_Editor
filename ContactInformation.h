#ifndef CONTACTINFORMATION_H
#define CONTACTINFORMATION_H

#include "structures.cpp"
#include "library.h"

infoLine * getLine(infoLine *infoLineHead) {
    int i = 0, line = 0;

    std::cout << "Write the line number" << std::endl;
    std::cin >> line;

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

class ContactInformation {
private:
    infoLine *infoLineHead;
public:
    ContactInformation() {
        infoLineHead = new infoLine;
        infoLineHead->name = nullptr;
        infoLineHead->surname = nullptr;
        infoLineHead->email = nullptr;
        infoLineHead->next = nullptr;
    }

    void SetInfo() {
        infoLine *newLine = getLine(infoLineHead);

        setInField(newLine, "name");
        setInField(newLine, "surname");
        setInField(newLine, "email");
    }

    void ChangeInfo() {
        infoLine *newLine = getLine(infoLineHead);

        int fN = 0, fS = 0, fE = 0;
        std::cout << "Write 1 if you want to change: Name/Surname/Email "
                     "(ex: 1 0 1) - sets all except surname" << std::endl;

        std::cin >> fN >> fS >> fE;
        if (fN == 1) setInField(newLine, "name");
        if (fS == 1) setInField(newLine, "surname");
        if (fE == 1) setInField(newLine, "email");
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
