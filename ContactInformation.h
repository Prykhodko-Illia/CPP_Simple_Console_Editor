#ifndef CONTACTINFORMATION_H
#define CONTACTINFORMATION_H

#include "structures.cpp"
#include "library.h"


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
