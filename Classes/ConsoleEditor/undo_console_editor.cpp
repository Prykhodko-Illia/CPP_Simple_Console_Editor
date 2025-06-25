#include "ConsoleEditor.h"

void ConsoleEditor::undo() {
    if (undoStack.empty()) {
        std::cout << "The stack is empty" << std::endl;
        return;
    }

    command *currentCommand = undoStack.top();

    Frame * currentFrame = frames[currentCommand->frameNumber - 1];

    switch (currentFrame->getScopeId()) {
        case 1:
            TextInformation::undo(
                *(dynamic_cast<TextInformation *>(currentFrame)),
                dynamic_cast<textCommand *>(currentCommand)
                );
            break;
        case 2:
            ContactInformation::undo(
            *(dynamic_cast<ContactInformation *>(currentFrame)),
                dynamic_cast<contactCommand *>(currentCommand)
            );
            break;
        case 3:
            CheckBox::undo(
            *(dynamic_cast<CheckBox *>(currentFrame)),
                dynamic_cast<checkBoxCommand *>(currentCommand)
            );
            break;
        default:
            break;
    }

    redoStack.push(currentCommand);
    undoStack.pop();
}