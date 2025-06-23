#include "ConsoleEditor.h"

void ConsoleEditor::deleteFrame() {
    int frameNumber = getNumber("Write a number of frame you want to delete: ");
    if (frameNumber > frames.size() || frameNumber < 1) {
        std::cout << "Invalid number" << std::endl;
    } else {
        frames.erase(frames.begin() + frameNumber);
    }
}