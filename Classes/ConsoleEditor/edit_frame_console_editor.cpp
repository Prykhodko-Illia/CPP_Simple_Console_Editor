#include "ConsoleEditor.h"
#include "../../Scopes/scopes.h"

void ConsoleEditor::editFrame() {
    int frameNumber = getNumber("Write number of frame to edit");

    if (frameNumber > frames.size() || frameNumber < 1) {
        std::cout << "Invalid number" << std::endl;
    } else {
        switch (frames[frameNumber - 1]->getScopeId()) {
            case 1:
                std::cout << "You are in the text frame:" << std::endl;
                TextInformation::printHelpInfo();

                textInformationScope(*(dynamic_cast<TextInformation *>(frames[frameNumber - 1])));
                break;
            case 2:
                std::cout << "You are in the contact info frame:" << std::endl;
                ContactInformation::printHelpInfo();

                contactInformationScope(*(dynamic_cast<ContactInformation *>(frames[frameNumber - 1])));
                break;
            case 3:
                std::cout << "You are in the checkbox frame:" << std::endl;
                CheckBox::printHelpInfo();

                checkBoxScope(*(dynamic_cast<CheckBox *>(frames[frameNumber - 1])));
                break;
            default:
                std::cout << "Can't access to the frame" << std::endl;
        }
        std::cout << "You are back to the start" << std::endl;
    }
}