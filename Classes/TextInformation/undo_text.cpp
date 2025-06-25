#include "TextInformation.h"

void undoDeleteLine(textLine *lineHead) {
    textLine *temp = lineHead;
    textLine *previous = nullptr;
    while (temp->next != nullptr) {
        previous = temp;
        temp = dynamic_cast<textLine *>(temp->next);
    }

    if (previous != nullptr) previous->next = nullptr;

    delete temp;
}

void undoAppendLine(textLine *lineHead, textCommand *currentCommand) {
    int lineIdx = 1, charIdx = 0;

    const textLine *lastLine = lineHead;
    while (lastLine->next != nullptr) {
        lastLine = dynamic_cast<textLine *>(lastLine->next);
        lineIdx++;
    }

    start *lastChar = lastLine->content;
    while (lastChar != currentCommand->content) {
        lastChar = lastChar->ptr;
        charIdx++;
    }

    if (charIdx != 0) charIdx++;
    internalDelete(lineHead, currentCommand, lineIdx, charIdx, currentCommand->size);
}

void undoInsert(textLine *lineHead, textCommand *currentCommand) {
    internalDelete(lineHead, currentCommand, currentCommand->lineNumber, currentCommand->index, currentCommand->size);
}

void undoDelete(textLine *lineHead, const textCommand *currentCommand) {
    internalInsert(lineHead, currentCommand->content, currentCommand->lineNumber, currentCommand->index);
}

void undoInsertReplacement(textLine *lineHead, textCommand *currentCommand) {
    auto *temp = new textCommand;
    internalDelete(lineHead, temp, currentCommand->lineNumber, currentCommand->index, currentCommand->size);
    internalInsert(lineHead, currentCommand->content, currentCommand->lineNumber, currentCommand->index);

    currentCommand->content = temp->content;
    delete temp;
}

void TextInformation::undo(TextInformation &frame, textCommand *command) {
    switch (command->cmdNumber) {
        case 1:
            undoAppendLine(frame.lineHead, command);
            break;
        case 2:
            undoDeleteLine(frame.lineHead);
            break;
        case 12:
            undoInsert(frame.lineHead, command);
            break;
        case 8:
            undoDelete(frame.lineHead, command);
            break;
        case 14:
            undoInsertReplacement(frame.lineHead, command);
            break;
        default:
            break;
    }
}