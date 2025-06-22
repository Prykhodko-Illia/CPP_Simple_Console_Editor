#include "ConsoleEditor.h"

void redoAppend(textLine *lineHead, command *currentCommand) {
    internalAppend(lineHead, currentCommand->ptr);
}

void redoNewLine(textLine *lineHead) {
    internalNewLine(lineHead);
};

void redoInsert(textLine *lineHead, command *currentCommand) {
    internalInsert(lineHead, currentCommand->ptr, currentCommand->lineNum, currentCommand->index);
}

void redoDelete(textLine *lineHead, command *currentCommand) {
    internalDelete(lineHead, nullptr, currentCommand->lineNum, currentCommand->index, currentCommand->size);
}

void redoInsertReplacement(textLine *lineHead, command *currentCommand) {
    command *temp = new command;
    internalDelete(lineHead, temp, currentCommand->lineNum, currentCommand->index, currentCommand->size);
    internalInsert(lineHead, currentCommand->ptr, currentCommand->lineNum, currentCommand->index);

    currentCommand->ptr = temp->ptr;
    delete temp;
}
//
// void ConsoleEditor::redo() {
//     if (redoStack.empty()) {
//         std::cout << "The stack is empty" << std::endl;
//         return;
//     }
//
//     command *currentCommand = redoStack.top();
//     switch (currentCommand->cmdNumber) {
//         case 1:
//             redoAppend(lineHead, currentCommand);
//             break;
//         case 2:
//             redoNewLine(lineHead);
//             break;
//         case 6:
//         case 12:
//             redoInsert(lineHead, currentCommand);
//             break;
//         case 8:
//             redoDelete(lineHead, currentCommand);
//             break;
//         case 14:
//             redoInsertReplacement(lineHead, currentCommand);
//             break;
//         default:
//             return;
//     }
//
//     redoStack.pop();
//     undoStack.push(currentCommand);
// }