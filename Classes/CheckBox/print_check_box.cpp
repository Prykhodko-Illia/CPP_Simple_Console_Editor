#include "CheckBox.h"

void printCheckLine(checkLine *line) {
    if (line->status == true) std::cout << "[   ]";
    if (line->status == false) std::cout << "[ x ]";

    std::cout << " " << line->context;
}

void CheckBox::printCheckbox() {
    checkLine *temp = checkLineHead;

    while (temp != nullptr) {
        printCheckLine(temp);
        temp = dynamic_cast<checkLine *>(temp->next);
    }
}