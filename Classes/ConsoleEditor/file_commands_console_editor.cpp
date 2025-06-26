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

    int currentFrame = 0;
    int j = 0;

    while (fgets(fileContent, 100, file)) {

        if (fileContent[0] == '\302' && fileContent[1] == '\247') {
            switch (fileContent[2]) {
                case '1':
                    currentFrame = 1;
                    frames.push_back(new TextInformation());
                    break;
                case '2':
                    currentFrame = 2;
                    frames.push_back(new ContactInformation());
                    break;
                case '3':
                    currentFrame = 3;
                    frames.push_back(new CheckBox());
                    break;
                default: currentFrame = 0;
            }
            continue;
        }

        switch (currentFrame) {

            case 1: {
                auto textFrame = dynamic_cast<TextInformation *>(frames.back());
                textLine *textLineHead = textFrame->getLineHead();
                auto currentTextLine = dynamic_cast<textLine *>(getLastLine(textLineHead));

                start *firstChar = nullptr;
                start *currentChar = nullptr;
                for (int i = 0; (fileContent[i] != '\0') && (i < 100); i++) {
                    if (fileContent[i] == '\n') {
                        currentTextLine->next = new textLine;
                        currentTextLine = dynamic_cast<textLine *>(currentTextLine->next);

                        currentTextLine->content = nullptr;
                        currentTextLine->next = nullptr;

                        firstChar == nullptr;
                        continue;
                    }

                    if (firstChar == nullptr) {
                        firstChar = new start;
                        firstChar->value = fileContent[i];
                        firstChar->ptr = nullptr;

                        currentTextLine->content = firstChar;
                    } else {
                        currentChar = new start;
                        currentChar->value = fileContent[i];
                        currentChar->ptr = nullptr;

                        firstChar->ptr = currentChar;
                        firstChar = firstChar->ptr;
                    }
                }
            }
                break;
            case 2: {
                auto contactFrame = dynamic_cast<ContactInformation *>(frames.back());
                infoLine *infoLineHead = contactFrame->getLineHead();
                auto currentInfoLine = dynamic_cast<infoLine *>(getLastLine(infoLineHead));

                start *firstChar = nullptr;
                start *currentChar = nullptr;
                
                for (int i = 1; (fileContent[i] != '\0') && (i < 100); ++i) {
                    if (fileContent[i] == '\n') {
                        currentInfoLine->next = new infoLine;
                        currentInfoLine = dynamic_cast<infoLine *>(currentInfoLine->next);

                        currentInfoLine->name = nullptr;
                        currentInfoLine->surname = nullptr;
                        currentInfoLine->email = nullptr;
                        currentInfoLine->next = nullptr;

                        firstChar == nullptr;

                        ++j;
                        continue;
                    }

                    if (firstChar == nullptr) {
                        firstChar = new start;
                        firstChar->value = fileContent[i];
                        firstChar->ptr = nullptr;

                        if (j % 3 == 1) currentInfoLine->name = firstChar;
                        if (j % 3 == 2) currentInfoLine->surname = firstChar;
                        if (j % 3 == 0) currentInfoLine->email = firstChar;

                    } else {
                        currentChar = new start;
                        currentChar->value = fileContent[i];
                        currentChar->ptr = nullptr;

                        firstChar->ptr = currentChar;
                        firstChar = firstChar->ptr;
                    }
                }
            }
                break;
            case 3: {
                auto checkBoxFrame = dynamic_cast<CheckBox *>(frames.back());
                checkLine *checkBoxHead = checkBoxFrame->getLineHead();
                auto currentCheckLine = dynamic_cast<checkLine *>(getLastLine(checkBoxHead));

                if (fileContent[0] == 0) currentCheckLine->status = false;
                else if (fileContent[0] == 1) currentCheckLine->status = true;

                start *firstChar = nullptr;
                start *currentChar = nullptr;
                for (int i = 1; (fileContent[i] != '\0') && (i < 100); i++) {
                    if (fileContent[i] == '\n' && i != 1) {
                        currentCheckLine->next = new checkLine;
                        currentCheckLine = dynamic_cast<checkLine *>(currentCheckLine->next);

                        currentCheckLine->context = nullptr;
                        currentCheckLine->status = false;
                        currentCheckLine->next = nullptr;

                        firstChar == nullptr;
                        continue;
                    }

                    if (firstChar == nullptr) {
                        firstChar = new start;
                        firstChar->value = fileContent[i];
                        firstChar->ptr = nullptr;

                        currentCheckLine->context = firstChar;
                    } else {
                        currentChar = new start;
                        currentChar->value = fileContent[i];
                        currentChar->ptr = nullptr;

                        firstChar->ptr = currentChar;
                        firstChar = firstChar->ptr;
                    }
                }
            }
                break;
            default: continue;
            }
        }
    fclose(file);
    printf("Content were successfully loaded from the file\n");
    return 0;
}