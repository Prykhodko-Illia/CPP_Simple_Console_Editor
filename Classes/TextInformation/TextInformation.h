#ifndef TEXTINFORMATION_H
#define TEXTINFORMATION_H

#include "../../GeneralCommands/library.h"

class TextInformation {
private:
    textLine *lineHead = nullptr;
    int cursorLine = 1;
    int cursorChar = 0;

    start *copyBuffer = nullptr;
public:
    TextInformation() {
        lineHead = new textLine;

        lineHead->content = nullptr;
        lineHead->next = nullptr;
    }

    static void printHelpInfo();

    void append();
    void newLine();

    void insert();
    void insert_replacement();

    void deleteContent();
    void search();

    void setCursor();

    void cut();
    void paste();
    void copy();

    void printText();

    ~TextInformation() {
        clearHeap(lineHead);
    }
};



#endif //TEXTINFORMATION_H
