#include "ConsoleEditor.h"
#include "../../Scopes/scopes.h"

void ConsoleEditor::editFrame() {
    int frameNumber = getNumber("Write number of frame to edit");

    if (frameNumber > frames.size() || frameNumber < 1) {
        std::cout << "Invalid number" << std::endl;
    } else {
        switch (frames[frameNumber]->getScopeId()) {
            case 1:
                textInformationScope(*(dynamic_cast<TextInformation *>(frames[frameNumber])));
                break;
            case 2:
                contactInformationScope(*(dynamic_cast<ContactInformation *>(frames[frameNumber])));
                break;
            case 3:
                checkBoxScope(*(dynamic_cast<CheckBox *>(frames[frameNumber])));
                break;
            default:
                std::cout << "Can't access to the frame" << std::endl;
        }
    }
}