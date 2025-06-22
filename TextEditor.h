#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "structures.cpp"
#include "library.h"
#include <stack>


class TextEditor {
private:
    textLine *lineHead = nullptr;
    std::stack<command *> undoStack;
    std::stack<command *> redoStack;
    start *copyBuffer = nullptr;

    // start *cursorPoint = nullptr;
    int cursorLine = 1;
    int cursorChar = 0;

public:
    TextEditor() {
        lineHead = new textLine;

        lineHead->content = nullptr;
        lineHead->next = nullptr;
    }
    static void printHelpInfo();

    void append();
    void newLine();

    int saveToFile();
    void load () {
        lineHead = loadFromFile(lineHead);
        int cursorLine = 1;
        int cursorChar = 0;
    }

    void printAll();

    void insert();
    void search();

    void deleteContent();

    void undo();
    void redo();

    void cut();
    void paste();
    void copy();

    void insert_replacement();

    void setCursor();
    
    ~TextEditor() {
        clearHeap(lineHead);
    }
};

#endif //TEXTEDITOR_H
