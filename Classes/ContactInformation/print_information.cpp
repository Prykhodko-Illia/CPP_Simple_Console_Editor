#include "ContactInformation.h"

void printInfoLine(infoLine *line) {
    std::cout << "Contact - " << line->name << " " << line->surname << ", E-mail: " << line->email << std::endl;
}

void ContactInformation::printInfo() const{
    infoLine *temp = infoLineHead;

    while (temp != nullptr) {
        printInfoLine(temp);
        temp = dynamic_cast<infoLine *>(temp->next);
    }
}