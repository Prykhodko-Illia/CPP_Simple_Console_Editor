#include <iostream>
#include "ConsoleEditor.h"

char * getFilePath(char *filePath) {
    std::string fileName;
    std::cin >> fileName;

    int i = 0;
    while ((fileName[i] != '\n') || (fileName[i] != '\0')) {
        filePath[13 + i] = fileName[i];
        i++;

        if (i > 15) break;
    }

    return filePath;
}

void writeString(FILE *file, start *currentChar) {
     while (currentChar != nullptr) {
         fputc(currentChar->value, file);
         currentChar = currentChar->ptr;
     }

     fputc('\n', file);
}

void writeText(FILE *file, TextInformation &frame) {
    fputs("\u180e1", file);
}

void writeContact(FILE *file, ContactInformation &frame) {
    fputs("\u180e2", file);
}

void writeCheckBox(FILE *file, CheckBox &frame) {
    fputs("\u180e3", file);
}

int ConsoleEditor::saveToFile() {
    FILE *file = nullptr;

    char filePath[30] = "..//..//Files";
    printf("Enter the file name for saving:\n");

    file = fopen(getFilePath(filePath), "w");

    if (file == nullptr) {
        printf("Error opening file.\n");
        fclose(file);
        return 1;
    }

    for (auto &frame : frames) {
        switch(frame->getScopeId()) {
            case 1:
                writeText(file, *(dynamic_cast<TextInformation *>(frame)));
                break;
            case 2:
                writeContact(file, *(dynamic_cast<ContactInformation *>(frame)));
                break;
            case 3:
                writeCheckBox(file, *(dynamic_cast<CheckBox *>(frame)));
                break;
            default: break;
        }
    }

    // textLine *currentLine = nullptr;
    // currentLine = lineHead;

    // start *currentChar = nullptr;
    //
    // while (currentLine != nullptr) {
    //     currentChar = currentLine->content;

    //     currentLine = dynamic_cast<textLine *>(currentLine->next);
    // }

    fclose(file);

    printf("Content were successfully written to the file\n");

    return 0;
}
//
// textLine * loadFromFile(textLine *lineHead) {
//     FILE* file = nullptr;
//
//     char fileContent[100];
//     std::cout << "Enter the file name for loading:" << std::endl;
//
//     char filePath[30] = "..//";
//
//     file = fopen(getFilePath(filePath), "r");
//
//     if (file == nullptr) {
//         std::cout << "Error opening file" << std::endl;
//         fclose(file);
//         return lineHead;
//     }
//
//     clearHeap(lineHead);
//
//     lineHead = new textLine;
//     lineHead->content = nullptr;
//     lineHead->next = nullptr;
//
//     textLine *currentLine = nullptr;
//     currentLine = lineHead;
//
//     while (fgets(fileContent, 100, file)) {
//
//         start *firstChar = nullptr;
//         start *currentChar = nullptr;
//
//         for (int i = 0; (fileContent[i] != '\0') && (i < 100); i++) {
//             if (fileContent[i] == '\n') {
//                 currentLine->next = new textLine;
//                 currentLine = dynamic_cast<textLine *>(currentLine->next);
//
//                 currentLine->content = nullptr;
//                 currentLine->next = nullptr;
//
//                 firstChar = nullptr;
//                 continue;
//             }
//
//             if (firstChar == nullptr) {
//                 firstChar = new start;
//                 firstChar->value = fileContent[i];
//                 firstChar->ptr = nullptr;
//
//                 currentLine->content = firstChar;
//             } else {
//                 currentChar = new start;
//                 currentChar->value = fileContent[i];
//                 currentChar->ptr = nullptr;
//
//                 firstChar->ptr = currentChar;
//                 firstChar = firstChar->ptr;
//             }
//         }
//     }
//     fclose(file);
//
//     return lineHead;
// }