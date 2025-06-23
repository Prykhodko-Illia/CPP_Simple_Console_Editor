#include "TextInformation.h"

void TextInformation::printContent() {
    textLine *temp = lineHead;

    while (temp != nullptr) {
        if (temp->content != nullptr) {
            printString(temp->content);
        } else {
            std::cout << std::endl;
        }

        temp = dynamic_cast<textLine *>(temp->next);
    }
}