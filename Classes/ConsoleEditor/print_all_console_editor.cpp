#include "ConsoleEditor.h"

void ConsoleEditor::printAll() const{
    for (auto & frame : frames) {
        frame->printContent();
    }
}