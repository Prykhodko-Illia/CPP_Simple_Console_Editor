#include "TextInformation.h"

void TextInformation::setCursor() {
    std::cout << "Choose line and index for cursor" << std::endl;

    int lineIdx, charIdx;
    std::cin >> lineIdx >> charIdx;

    cursorLine = lineIdx;
    cursorChar = charIdx;
}