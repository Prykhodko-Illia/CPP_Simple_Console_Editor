#include "ConsoleEditor.h"

void ConsoleEditor::createNewFrame()  {
    std::string frameName = getInput();

    if (frameName == "text") {
        frames.push_back(new TextInformation());
        std::cout << "Text frame was created" << std::endl;
    } else if (frameName == "contact") {
        frames.push_back(new ContactInformation());
        std::cout << "contact frame was created" << std::endl;
    } else if (frameName == "checkbox") {
        frames.push_back(new CheckBox());
        std::cout << "checkbox frame was created" << std::endl;
    }
}