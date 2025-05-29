#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "structures.cpp"
#include "library.h"


class TextEditor {
private:
    line *lineHead = nullptr;

public:
    TextEditor() {
        lineHead = new line;

        lineHead->content = nullptr;
        lineHead->next = nullptr;
    }
    static void printHelpInfo();

    void append();
    void newLine();

    int saveToFile();
    void load () {
        lineHead = loadFromFile(lineHead);
    }

    void printAll();

    void insert();
    void search();
    
    ~TextEditor() {
        delete lineHead;
    }
};

#endif //TEXTEDITOR_H
