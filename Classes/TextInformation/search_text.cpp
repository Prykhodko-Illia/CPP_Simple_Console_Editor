#include "TextInformation.h"

int searchInLine(start *head, std::string word) {
    start *currentChar = nullptr;
    currentChar = head;

    int i = 0;
    while (true) {
        if (word[i] == currentChar->value) {
            if ((word[i + 1] == '\n') || (word[i + 1] == '\0')) {
                return 1;
            }
            if (currentChar->ptr == nullptr) return -1;
            currentChar = currentChar->ptr;
            i++;
        } else {
            return 0;
        }
    }
}

void TextInformation::search() {
    std::cout << "Enter text to search:" << std::endl;

    std::string textForSearch;
    std::cin >> textForSearch;

    textLine *currentLine = nullptr;
    currentLine = lineHead;

    int lineCounter = 0;

    start *currentChar = nullptr;
    std::cout << "Was found on:" << std::endl;

    while (true) {
        lineCounter++;

        if (currentLine->content == nullptr) {
            currentLine = dynamic_cast<textLine *>(currentLine->next);
            continue;
        }

        int charCounter = 0;
        currentChar = currentLine->content;

        while (true) {
            charCounter++;

            int lineSearchValue = searchInLine(currentChar, textForSearch);
            if (lineSearchValue == 0) {
                if (currentChar->ptr == nullptr) break;
                currentChar = currentChar->ptr;
                continue;
            }

            if (lineSearchValue < 0){
                break;
            }
            std::cout << "line: " << lineCounter << ", char: " << charCounter << std::endl;

            if (currentChar->ptr == nullptr) break;
            currentChar = currentChar->ptr;
        }

        if (currentLine->next == nullptr) break;
        currentLine = dynamic_cast<textLine *>(currentLine->next);
    }
}