#include "ContactInformation.h"

void redoSetInfo(infoLine *infoLineHead, contactCommand *command) {
    auto line = dynamic_cast<infoLine *>(getLine(infoLineHead, command->lineNumber));

    internalSetInField(line, "name", command->name, command);
    internalSetInField(line, "surname", command->surname, command);
    internalSetInField(line, "email", command->email, command);
}

void redoNewLine(infoLine *infoLineHead, contactCommand *command) {
    auto newLine = new infoLine;

    newLine->name = command->name;
    newLine->surname = command->surname;
    newLine->email = command->email;
    newLine->next = nullptr;

    auto lastLine = dynamic_cast<infoLine *>(getLastLine(infoLineHead));
    lastLine->next = newLine;
}

void redoDeleteInfo(infoLine *infoLineHead, contactCommand *command, int &linesCount) {
    internalDeleteInfo(infoLineHead, command->lineNumber, command, linesCount);
}

void ContactInformation::redo(ContactInformation &frame, contactCommand *command) {
    switch (command->cmdNumber) {
        case 1:
        case 2:
            redoSetInfo(frame.infoLineHead, command);
            break;
        case 3:
            redoNewLine(frame.infoLineHead, command);
            ++frame.linesCount;
            break;
        case 4:
            redoDeleteInfo(frame.infoLineHead, command, frame.linesCount);
            break;
        default:
            break;
    }
}