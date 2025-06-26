#include <iostream>
#include "ConsoleEditor.h"

char * getFilePath(char *filePath) {
    std::string fileName;
    std::cin >> fileName;

    int i = 0;
    while ((fileName[i] != '\n') || (fileName[i] != '\0')) {
        filePath[11 + i] = fileName[i];
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
    fputs("\u180e1\n", file);

    textLine *textLineHead = frame.getLineHead();
    textLine *currentLine = textLineHead;

    while (currentLine != nullptr) {
        writeString(file, currentLine->content);
        currentLine = dynamic_cast<textLine *>(currentLine->next);
    }
}

void writeContact(FILE *file, ContactInformation &frame) {
    fputs("\u180e2\n", file);

    infoLine *infoLineHead = frame.getLineHead();
    infoLine *currentLine = infoLineHead;

    while (currentLine != nullptr) {
        writeString(file, currentLine->name);
        writeString(file, currentLine->surname);
        writeString(file, currentLine->email);

        currentLine = dynamic_cast<infoLine *>(currentLine->next);
    }
}

void writeCheckBox(FILE *file, CheckBox &frame) {
    fputs("\u180e3\n", file);

    checkLine *checkLineHead = frame.getLineHead();
    checkLine *currentLine = checkLineHead;

    while (currentLine != nullptr) {
        if (currentLine->status) fputc('1', file);
        else fputc('0', file);

        writeString(file, currentLine->context);

        currentLine = dynamic_cast<checkLine *>(currentLine->next);
    }
}

int ConsoleEditor::saveToFile() {
    FILE *file = nullptr;

    char filePath[40] = "..//Files//";
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

    fclose(file);
    printf("Content were successfully saved to the file\n");

    return 0;
}

void loadText() {}
void loadContact() {}
void loadCheckBox() {}

int ConsoleEditor::loadFromFile() {
    FILE* file = nullptr;
    char fileContent[100];
    std::cout << "Enter the file name for loading:" << std::endl;

    char filePath[40] = "..//Files//";
    file = fopen(getFilePath(filePath), "r");

    if (file == nullptr) {
        std::cout << "Error opening file" << std::endl;
        fclose(file);
        return 1;
    }

    for (auto &frame : frames) {
        delete frame;
    }
    frames.clear();

    while (fgets(fileContent, 100, file)) {
        if (fileContent[0] != '᠎') {
            continue;
        }

        switch (fileContent[1]) {
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            default: break;
        }
    }

    fclose(file);
    printf("Content were successfully loaded from the file\n");

    return 0;
}


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
// }