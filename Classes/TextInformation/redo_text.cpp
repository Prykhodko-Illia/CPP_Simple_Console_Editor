#include "TextInformation.h"

void redoAppend(textLine *lineHead, const textCommand *currentCommand) {
    internalAppend(lineHead, currentCommand->content);
}

void redoNewLine(textLine *lineHead) {
    internalNewLine(lineHead);
};

void redoInsert(textLine *lineHead, textCommand const *currentCommand) {
    internalInsert(lineHead, currentCommand->content, currentCommand->lineNumber, currentCommand->index);
}

void redoDelete(textLine *lineHead, textCommand *currentCommand) {
    internalDelete(lineHead, currentCommand, currentCommand->lineNumber, currentCommand->index, currentCommand->size);
}

void redoInsertReplacement(textLine *lineHead, textCommand *currentCommand) {
    auto *temp = new textCommand;
    internalDelete(lineHead, temp, currentCommand->lineNumber, currentCommand->index, currentCommand->size);
    internalInsert(lineHead, currentCommand->content, currentCommand->lineNumber, currentCommand->index);

    currentCommand->content = temp->content;
    delete temp;
}

void TextInformation::redo(TextInformation &frame, textCommand *command) {
    switch (command->cmdNumber) {
        case 1:
            redoAppend(frame.lineHead, command);
            break;
        case 2:
            redoNewLine(frame.lineHead);
            break;
        case 6:
        case 12:
            redoInsert(frame.lineHead, command);
            break;
        case 8:
            redoDelete(frame.lineHead, command);
            break;
        case 14:
            redoInsertReplacement(frame.lineHead, command);
            break;
        default:
            break;
    }
}