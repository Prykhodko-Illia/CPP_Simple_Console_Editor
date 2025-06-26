#ifndef TEXTINFORMATION_H
#define TEXTINFORMATION_H

#include "../../GeneralCommands/library.h"
#include "../Frame/Frame.h"
#include <stack>

class TextInformation : public Frame {
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

        scopeId = 1;
    }

    static void printHelpInfo();
    static void undo(TextInformation &frame, textCommand *command);
    static void redo(TextInformation &frame, textCommand *command);

    void append(std::stack<command *> &undoStack, int frameNumber);
    void newLine(std::stack<command *> &undoStack, int frameNumber);

    void insert(std::stack<command *> &undoStack, int frameNumber);
    void insert_replacement(std::stack<command *> &undoStack, int frameNumber);

    void deleteContent(std::stack<command *> &undoStack, int frameNumber);
    void search();

    void setCursor();

    void cut();
    void paste(std::stack<command *> &undoStack, int frameNumber);
    void copy();

    void printContent() override;

    [[nodiscard]] textLine * getLineHead() const {
        return lineHead;
    }

    ~TextInformation() final{
        clearHeap(lineHead);
    }
};



#endif //TEXTINFORMATION_H
