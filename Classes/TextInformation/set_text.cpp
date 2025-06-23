#include "TextInformation.h"

void internalAppend(textLine *lineHead, start *newText) {
    textLine * lastLine = nullptr;
    lastLine = dynamic_cast<textLine *>(getLastLine(lineHead));

    start *lastChar = nullptr;

    if (lastLine->content == nullptr)  lastLine->content = newText;
    else {
        lastChar = lastLine->content;
        while (lastChar->ptr != nullptr) {
            lastChar = lastChar->ptr;
        }
        lastChar->ptr = newText;
    }
}

void TextInformation::append() {
    std::string input = getInput();

    start *newText = nullptr;
    newText = convertStringToLinkedList(input, 32);

    int size = getSize(newText);

    // command *cmd = new command;
    // cmd->cmdNumber = 1;
    // cmd->ptr = newText;
    // cmd->size = size;
    //
    // undoStack.push(cmd);

    internalInsert(lineHead, newText, cursorLine, cursorChar);

    cursorChar += size;

    std::cout << std::endl << "Successfully added" << std::endl;
}

void internalNewLine(textLine *lineHead) {
    textLine *newLine = nullptr;
    newLine = new textLine;
    newLine->content = nullptr;
    newLine->next = nullptr;

    getLastLine(lineHead)->next = newLine;
}

void internalNewCursorLine(textLine *lineHead, int lineIdx) {
    textLine *newLine = nullptr;
    newLine = new textLine;
    newLine->content = nullptr;
    newLine->next = nullptr;

    textLine *current = lineHead;
    int i = 1;
    while (current->next != nullptr && i < lineIdx) {
        current = dynamic_cast<textLine *>(current->next);
        i++;
    }

    if (current->next) newLine->next = current->next;
    current->next = newLine;
}

void TextInformation::newLine() {
    internalNewCursorLine(lineHead, cursorLine);
    cursorLine++;
    cursorChar = 0;

    // command *cmd = new command;
    // cmd->cmdNumber = 2;
    // undoStack.push(cmd);

    std::cout << "New line is started" << std::endl;
}