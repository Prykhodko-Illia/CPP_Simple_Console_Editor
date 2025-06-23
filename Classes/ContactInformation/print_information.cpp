#include "ContactInformation.h"

void printInfoLine(infoLine *line) {
    std::cout << "Contact - ";
    if (line->name == nullptr) std::cout << "";
    else printString(line->name, false);

    std::cout << " ";
    if (line->name == nullptr) std::cout << "";
    else printString(line->surname, false);

    std::cout << ", E-mail: ";
    if (line->name == nullptr) std::cout << "";
    else printString(line->email, false);

    std::cout << std::endl;
}

void ContactInformation::printContent() {
    infoLine *temp = infoLineHead;

    while (temp != nullptr) {
        printInfoLine(temp);
        temp = dynamic_cast<infoLine *>(temp->next);
    }
}