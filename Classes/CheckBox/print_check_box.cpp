﻿#include "CheckBox.h"

void printCheckLine(checkLine *line) {
    if (line->status == false) std::cout << "[   ]";
    if (line->status == true) std::cout << "[ x ]";

    std::cout << " ";
    if (line->context != nullptr) printString(line->context);
}

void CheckBox::printContent() {
    checkLine *temp = checkLineHead;

    while (temp != nullptr) {
        printCheckLine(temp);
        temp = dynamic_cast<checkLine *>(temp->next);
    }

    std::cout << std::endl;
}