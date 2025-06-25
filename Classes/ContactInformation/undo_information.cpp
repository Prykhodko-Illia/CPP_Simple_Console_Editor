#include "ContactInformation.h"

void undoSetInfo(infoLine *infoLineHead, contactCommand *command) {
    auto line = dynamic_cast<infoLine *>(getLine(infoLineHead, command->lineNumber));

    internalSetInField(line, "name", command->name, command);
    internalSetInField(line, "surname", command->surname, command);
    internalSetInField(line, "email", command->email, command);
}

void undoNewLine(infoLine *infoLineHead, contactCommand *command, int linesCount) {
    auto previousLine = dynamic_cast<infoLine *>(getLine(infoLineHead, linesCount - 1));
    auto lastLine = dynamic_cast<infoLine *>(previousLine->next);

    command->name = lastLine->name;
    command->surname = lastLine->surname;
    command->email = lastLine->email;

    infoLineInitialization(lastLine, true);
    delete lastLine;

    previousLine->next = nullptr;
}

void undoDeleteInfo(infoLine *&infoLineHead, contactCommand *command) {
    auto newLine = new infoLine;
    infoLineInitialization(newLine, true);

    internalSetInField(newLine, "name", command->name, command);
    internalSetInField(newLine, "surname", command->surname, command);
    internalSetInField(newLine, "email", command->email, command);

    if (command->lineNumber == 1) {
        if (command->del_first == false) {
            newLine->next = infoLineHead;
        }

        infoLineHead = newLine;
        return;
    }

    auto previousLine = getLine(infoLineHead, (command->lineNumber - 1));
    newLine->next = previousLine->next;
    previousLine->next = newLine;
}

void ContactInformation::undo(ContactInformation &frame, contactCommand *command) {
    switch (command->cmdNumber) {
        case 1:
        case 2:
            undoSetInfo(frame.infoLineHead, command);
            break;
        case 3:
            undoNewLine(frame.infoLineHead, command, frame.linesCount);
            --frame.linesCount;
            break;
        case 4:
            undoDeleteInfo(frame.infoLineHead, command);
            if (command->del_first == false) ++frame.linesCount;
            break;
        default:
            break;
    }
}