#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "../../GeneralCommands/library.h"
#include "../classes.h"
#include <stack>
#include <vector>

class ConsoleEditor {
private:
    std::stack<command *> undoStack;
    std::stack<command *> redoStack;

    std::vector<Frame *> frames;

public:
    ConsoleEditor() {

    }
    static void printHelpInfo();

    void createNewFrame();
    void editFrame();
    void deleteFrame();

    void printAll() const;

    void encrypt() {
        const int key = getNumber("Write encryption key");

        CaesarCipher::encrypt(frames, key);
    }

    void decrypt() {
        const int key = getNumber("Write encryption key");

        CaesarCipher::encrypt(frames, -key);
    }

    // int saveToFile();
    // void load () {
    //     lineHead = loadFromFile(lineHead);
    //     int cursorLine = 1;
    //     int cursorChar = 0;
    // }
    //
    // void undo();
    // void redo();
};

#endif //TEXTEDITOR_H
