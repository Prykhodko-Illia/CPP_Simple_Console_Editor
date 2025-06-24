#include "../ConsoleEditor/ConsoleEditor.h"

void redoAppend(textLine *lineHead, const textCommand *currentCommand) {
    internalAppend(lineHead, currentCommand->content);
}

void redoNewLine(textLine *lineHead) {
    internalNewLine(lineHead);
};

void redoInsert(textLine *lineHead, textCommand const *currentCommand) {
    internalInsert(lineHead, currentCommand->content, currentCommand->lineNumber, currentCommand->index);
}

void redoDelete(textLine *lineHead, textCommand const *currentCommand) {
    internalDelete(lineHead, nullptr, currentCommand->lineNumber, currentCommand->index, currentCommand->size);
}

void redoInsertReplacement(textLine *lineHead, textCommand *currentCommand) {
    auto *temp = new textCommand;
    internalDelete(lineHead, temp, currentCommand->lineNumber, currentCommand->index, currentCommand->size);
    internalInsert(lineHead, currentCommand->content, currentCommand->lineNumber, currentCommand->index);

    currentCommand->content = temp->content;
    delete temp;
}
//
// void ConsoleEditor::redo() {
//     if (redoStack.empty()) {
//         std::cout << "The stack is empty" << std::endl;
//         return;
//     }
//
//     textCommand *currentCommand = redoStack.top();
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