#include "ConsoleEditor.h"

void ConsoleEditor::redo() {
    if (redoStack.empty()) {
        std::cout << "The stack is empty" << std::endl;
        return;
    }

    command *currentCommand = redoStack.top();

    Frame * currentFrame = frames[currentCommand->frameNumber - 1];

    switch (currentFrame->getScopeId()) {
        case 1:
            TextInformation::redo(
                *(dynamic_cast<TextInformation *>(currentFrame)),
                dynamic_cast<textCommand *>(currentCommand)
                );
            break;
        case 2:
            // ContactInformation::redo(
            // *(dynamic_cast<ContactInformation *>(currentFrame)),
            //     dynamic_cast<contactCommand *>(currentCommand)
            // );
            break;
        case 3:
            // CheckBox::redo(
            // *(dynamic_cast<CheckBox *>(currentFrame)),
            //     dynamic_cast<checkBoxCommand *>(currentCommand)
            // );
            // break;
        default:
            break;
    }

    redoStack.pop();
    undoStack.push(currentCommand);
}
