#include "ConsoleEditor.h"

void ConsoleEditor::createNewFrame()  {
    std::string frameName = getInput();

    if (frameName == "text") {
        frames.push_back(new TextInformation());
    } else if (frameName == "contact") {
        frames.push_back(new ContactInformation());
    } else if (frameName == "checkbox") {
        frames.push_back(new CheckBox());
    }
}