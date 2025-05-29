#include <iostream>
#include "TextEditor.h"
#include "library.h"

void TextEditor::deleteContent() {
    std::cout << "Choose line, index and number of symbols" << std::endl;

    int lineNum, index, size, i = 0;
    std::cin >> lineNum >> index >> size;

    if (size == 0) return;

    start *indexPointer = getCharPointerByIndexes(lineHead, lineNum, index - 1);

    start *currentChar = nullptr, *previousChar = nullptr;

    // if (indexPointer->ptr == nullptr) return;
    if (index == 0) currentChar = indexPointer;
    else currentChar = indexPointer->ptr;

    while (currentChar != nullptr && i < size) {
        previousChar = currentChar;
        currentChar = currentChar->ptr;
        delete previousChar;
        i++;
    }

    if (index == 0) {
        line *currentLine = lineHead;
        int j = 0;

        while (currentLine->next != nullptr && j < (lineNum - 1)) {
            currentLine = currentLine->next;
            j++;
        }

        currentLine->content = currentChar;
    }
    else indexPointer->ptr = currentChar;
    // indexPointer->ptr = currentChar;

    std::cout << "Succesfully deleted" << std::endl;
}