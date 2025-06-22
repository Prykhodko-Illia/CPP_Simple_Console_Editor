#include "CheckBox.h"

void deleteCheckLineInfo(checkLine *checkLineHead, bool nextFlag) {
    deleteString(checkLineHead->context);

    if (nextFlag) checkLineHead = nullptr;
}

void CheckBox::deleteCheckLine() {
    int line = getNumber("Write the line number to delete");

    if (line < 1) {
        std::cout << "Lines numbers are integers";
        return;
    }

    if (line == 1) {
        deleteCheckLineInfo(checkLineHead, false);

        if (checkLineHead->next != nullptr) {
            checkLineHead = dynamic_cast<checkLine *>(checkLineHead->next);
            --linesCount;
        }
    } else if (line >= linesCount) {
        infoLine *previousLine = dynamic_cast<checkLine *>(getLine(checkLineHead, linesCount - 1));
        deleteCheckLineInfo(dynamic_cast<checkLine *>(previousLine->next), true);

        previousLine->next = nullptr;
        --linesCount;
    } else {
        infoLine *previousLine = dynamic_cast<checkLine *>(getLine(checkLineHead, linesCount - 1));
        infoLine *lineToDelete = dynamic_cast<checkLine *>(previousLine->next);

        deleteCheckLineInfo(lineToDelete, false);
        previousLine->next = lineToDelete->next;

        delete lineToDelete;
        --linesCount;
    }
}