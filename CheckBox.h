#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "library.h"
#include "structures.cpp"

void deleteCheckLineInfo(checkLine *checkLineHead, bool nextFlag) {
    deleteString(checkLineHead->context);

    if (nextFlag) checkLineHead = nullptr;
}

void printCheckLine(checkLine *line) {
    if (line->status == true) std::cout << "[   ]";
    if (line->status == false) std::cout << "[ x ]";

    std::cout << " " << line->context;
}

class CheckBox {
private:
    checkLine *checkLineHead = nullptr;
    int linesCount;

public:
    CheckBox() {
        checkLineHead = new checkLine;
        checkLineHead->context = nullptr;
        checkLineHead->next = nullptr;

        linesCount = 1;
    }

    void setCheckBoxInfo() {
        checkLine * newLine = getLine(checkLineHead, getNumber("Write the checkbox number to edit the info"));
        start * input = convertStringToLinkedList(getInput());

        deleteString(newLine->context);
        newLine->context = input;
    }

    void setCheckboxStatus() {
        checkLine * lineNum = getLine(checkLineHead, getNumber("Write the checkbox number to set the status"));

        const int status = getNumber("Write 1 to check, 0 - to uncheck");
        if (status == 1) lineNum->status = true;
        if (status == 0) lineNum->status = false;
    }

    void newCheckLine() {
        checkLineHead->next = new checkLine;

        {
            checkLine *newLine = dynamic_cast<checkLine *>(checkLineHead->next);
            start * input = convertStringToLinkedList(getInput());
            newLine->context = input;
        }

        ++linesCount;
    }

    void deleteCheckLine() {
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

    void PrintCheckbox() {
        checkLine *temp = checkLineHead;

        while (temp != nullptr) {
            printCheckLine(temp);
            temp = dynamic_cast<checkLine *>(temp->next);
        }
    }

    ~CheckBox() {
        //write full implementation
        delete checkLineHead;
    }
};

#endif //CHECKBOX_H
