#include "ConsoleEditor.h"

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

void undoAppendLine(textLine *lineHead, command *currentCommand) {
    int lineIdx = 1, charIdx = 0;

    textLine *lastLine = lineHead;
    while (lastLine->next != nullptr) {
        lastLine = dynamic_cast<textLine *>(lastLine->next);
        lineIdx++;
    }

    start *lastChar = lastLine->content;
    while (lastChar != currentCommand->ptr) {
        lastChar = lastChar->ptr;
        charIdx++;
    }

    if (charIdx != 0) charIdx++;
    internalDelete(lineHead, nullptr, lineIdx, charIdx, currentCommand->size);
}

void undoInsert(textLine *lineHead, command *currentCommand) {
    internalDelete(lineHead, nullptr, currentCommand->lineNum, currentCommand->index, currentCommand->size);
}

void undoDelete(textLine *lineHead, command *currentCommand) {
    internalInsert(lineHead, currentCommand->ptr, currentCommand->lineNum, currentCommand->index);
}

void undoInsertReplacement(textLine *lineHead, command *currentCommand) {
    command *temp = new command;
    internalDelete(lineHead, temp, currentCommand->lineNum, currentCommand->index, currentCommand->size);
    internalInsert(lineHead, currentCommand->ptr, currentCommand->lineNum, currentCommand->index);

    currentCommand->ptr = temp->ptr;
    delete temp;
}
//
// void ConsoleEditor::undo() {
//     if (undoStack.empty()) {
//         std::cout << "The stack is empty" << std::endl;
//         return;
//     }
//
//     command *currentCommand = undoStack.top();
//     switch (currentCommand->cmdNumber) {
//         case 1:
//             undoAppendLine(lineHead, currentCommand);
//             break;
//         case 2:
//             undoDeleteLine(lineHead);
//             break;
//         case 6:
//         case 12:
//             undoInsert(lineHead, currentCommand);
//             break;
//         case 8:
//             undoDelete(lineHead, currentCommand);
//             break;
//         case 14:
//             undoInsertReplacement(lineHead, currentCommand);
//             break;
//         default:
//             return;
//     }
//
//     redoStack.push(currentCommand);
//     undoStack.pop();
// }