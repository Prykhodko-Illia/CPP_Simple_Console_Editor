#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "../../GeneralCommands/library.h"
#include <stack>

class ConsoleEditor {
private:
    std::stack<command *> undoStack;
    std::stack<command *> redoStack;

    // start *cursorPoint = nullptr;

public:
    ConsoleEditor();

    static void printHelpInfo();

    // int saveToFile();
    // void load () {
    //     lineHead = loadFromFile(lineHead);
    //     int cursorLine = 1;
    //     int cursorChar = 0;
    // }

    void undo();
    void redo();

    ~ConsoleEditor() {

    }
};

#endif //TEXTEDITOR_H
