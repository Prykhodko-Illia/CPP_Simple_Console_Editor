#include <iostream>
#include "TextEditor.h"

char * getFilePath(char *filePath) {
    std::string fileName;
    std::cin >> fileName;

    int i = 0;
    while ((fileName[i] != '\n') || (fileName[i] != '\0')) {
        filePath[4 + i] = fileName[i];
        i++;

        if (i > 15) break;
    }

    return filePath;
}

void clearHeap(textLine *lineHead) {
    textLine *previousLine = nullptr;
    while (lineHead != nullptr) {
        deleteString(lineHead->content);

        previousLine = lineHead;
        lineHead = dynamic_cast<textLine *>(lineHead->next);

        delete previousLine;
    }
}

int TextEditor::saveToFile() {
    FILE* file = nullptr;

    char filePath[30] = "..//";
    printf("Enter the file name for saving:\n");

    file = fopen(getFilePath(filePath), "w");

    if (file == nullptr) {
        printf("Error opening file.\n");
        fclose(file);
        return 1;
    }

    textLine *currentLine = nullptr;
    currentLine = lineHead;

    start *currentChar = nullptr;

    while (currentLine != nullptr) {
        currentChar = currentLine->content;

        while (currentChar != nullptr) {
            fputc(currentChar->value, file);
            currentChar = currentChar->ptr;
        }

        fputs("\n", file);
        currentLine = dynamic_cast<textLine *>(currentLine->next);
    }

    fclose(file);

    printf("Content were successfully written to the file\n");

    return 0;
}

textLine * loadFromFile(textLine *lineHead) {
    FILE* file = nullptr;

    char fileContent[100];
    std::cout << "Enter the file name for loading:" << std::endl;

    char filePath[30] = "..//";

    file = fopen(getFilePath(filePath), "r");

    if (file == nullptr) {
        std::cout << "Error opening file" << std::endl;
        fclose(file);
        return lineHead;
    }

    clearHeap(lineHead);

    lineHead = new textLine;
    lineHead->content = nullptr;
    lineHead->next = nullptr;

    textLine *currentLine = nullptr;
    currentLine = lineHead;

    while (fgets(fileContent, 100, file)) {

        start *firstChar = nullptr;
        start *currentChar = nullptr;

        for (int i = 0; (fileContent[i] != '\0') && (i < 100); i++) {
            if (fileContent[i] == '\n') {
                currentLine->next = new textLine;
                currentLine = dynamic_cast<textLine *>(currentLine->next);

                currentLine->content = nullptr;
                currentLine->next = nullptr;

                firstChar = nullptr;
                continue;
            }

            if (firstChar == nullptr) {
                firstChar = new start;
                firstChar->value = fileContent[i];
                firstChar->ptr = nullptr;

                currentLine->content = firstChar;
            } else {
                currentChar = new start;
                currentChar->value = fileContent[i];
                currentChar->ptr = nullptr;

                firstChar->ptr = currentChar;
                firstChar = firstChar->ptr;
            }
        }
    }
    fclose(file);

    return lineHead;
}