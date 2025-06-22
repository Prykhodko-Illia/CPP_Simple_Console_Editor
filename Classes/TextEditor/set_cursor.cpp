#include "TextEditor.h"

void TextEditor::setCursor() {
    std::cout << "Choose line and index for cursor" << std::endl;

    int lineIdx, charIdx;
    std::cin >> lineIdx >> charIdx;

    start *first = getCharPointerByIndexes(lineHead, lineIdx, charIdx);

    cursorLine = lineIdx;
    cursorChar = charIdx;
}