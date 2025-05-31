#include "TextEditor.h"

void TextEditor::insert_replacement() {
    std::cout << "Choose line and index" << std::endl;

    int lineIdx, charIdx;
    std::cin >> lineIdx >> charIdx;

    std::cout << std::endl;

    std::string input = getInput();
    start *first = convertStringToLinkedList(input, 32);

    int size = getSize(first);

    internalDelete(lineHead, nullptr, lineIdx, charIdx, size);
    internalInsert(lineHead, first, lineIdx, charIdx);
}