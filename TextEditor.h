#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "structures.cpp"
#include "library.h"
#include <stack>


class TextEditor {
private:
    line *lineHead = nullptr;
    std::stack<command *> undoStack;
    std::stack<command *> redoStack;
    start *copyBuffer = nullptr;

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

    void deleteContent();

    void undo();
    void redo();

    void cut();
    void paste();
    void copy();
    
    ~TextEditor() {
        delete lineHead;
    }
};

#endif //TEXTEDITOR_H
