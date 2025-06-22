#include "ContactInformation.h"

void infoLineClearing(infoLine *linePointer, bool nextFlag) {
    deleteString(linePointer->name);
    deleteString(linePointer->surname);
    deleteString(linePointer->email);

    if (nextFlag) {
        linePointer->next = nullptr;
    }
}

void ContactInformation::deleteInfo() {
    int line = getNumber("Write the line number to delete");

    if (line < 1) {
        std::cout << "Lines numbers are integers";
        return;
    }

    if (line == 1) {
        infoLineInitialization(infoLineHead, false);

        if (infoLineHead->next != nullptr) {
            infoLineHead = dynamic_cast<infoLine *>(infoLineHead->next);
            --linesCount;
        }
    } else if (line >= linesCount) {
        auto *previousLine = dynamic_cast<infoLine *>(getLine(infoLineHead, linesCount - 1));
        infoLineClearing(dynamic_cast<infoLine *>(previousLine->next), true);

        previousLine->next = nullptr;
        --linesCount;
    } else {
        auto *previousLine = dynamic_cast<infoLine *>(getLine(infoLineHead, linesCount - 1));
        auto *lineToDelete = dynamic_cast<infoLine *>(previousLine->next);

        infoLineClearing(lineToDelete, false);
        previousLine->next = lineToDelete->next;

        delete lineToDelete;
        --linesCount;
    }
}