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

start * loadLine(const char *fileContent) {
    start *result = nullptr;
    start *currentChar = nullptr;
    start *lastChar = nullptr;

    for (int i = 0; (fileContent[i] != '\0') && (i < 100); i++) {
        if (fileContent[i] != '\n') {
            currentChar = new start;
            currentChar->value = fileContent[i];
            currentChar->ptr = nullptr;

            if (lastChar != nullptr) {
                lastChar->ptr = currentChar;
            }

            if (i == 0) {
                result = currentChar;
            }

            lastChar = currentChar;
        }
    }

    return result;
}

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
                default:
                    currentFrame = 0;
                    j = 0;
            }
            continue;
        }

        switch (currentFrame) {
            case 1: {
                auto frame = dynamic_cast<TextInformation *>(frames.back());

                if (frame->getLineHead()->content == nullptr) {
                    frame->getLineHead()->content = loadLine(fileContent);
                } else {
                    auto *newLine = new textLine;
                    newLine->content = loadLine(fileContent);
                    newLine->next = nullptr;

                    auto currentLine = dynamic_cast<textLine *>(getLastLine(frame->getLineHead()));
                    currentLine->next = newLine;
                }
            } break;
            case 2: {
                auto frame = dynamic_cast<ContactInformation *>(frames.back());

                if (frame->getLineHead()->email == nullptr && j < 3) {
                    if (j % 3 == 0) frame->getLineHead()->name = loadLine(fileContent);
                    if (j % 3 == 1) frame->getLineHead()->surname = loadLine(fileContent);
                    if (j % 3 == 2) frame->getLineHead()->email = loadLine(fileContent);
                } else {
                    if (j % 3 == 0) {
                        auto *newLine = new infoLine;
                        newLine->name = loadLine(fileContent);
                        newLine->next = nullptr;

                        auto currentLine = dynamic_cast<infoLine *>(getLastLine(frame->getLineHead()));
                        currentLine->next = newLine;
                        frame->incrementLinesCount();
                    }

                    if (j % 3 == 1)
                        dynamic_cast<infoLine *>(getLastLine(frame->getLineHead()))->surname = loadLine(fileContent);
                    if (j % 3 == 2)
                        dynamic_cast<infoLine *>(getLastLine(frame->getLineHead()))->email = loadLine(fileContent);
                }
                ++j;
            } break;
            case 3: {
                auto frame = dynamic_cast<CheckBox *>(frames.back());

                if (frame->getLineHead()->context == nullptr) {
                    frame->getLineHead()->context = loadLine(fileContent + 1);
                    if (fileContent[0] == '1') frame->getLineHead()->status = true;
                    else if (fileContent[0] == '0') frame->getLineHead()->status = false;

                } else {
                    auto *newLine = new checkLine;
                    newLine->context = loadLine(fileContent + 1);
                    if (fileContent[0] == '1') newLine->status = true;
                    else if (fileContent[0] == '0') newLine->status = false;

                    auto currentLine = dynamic_cast<checkLine *>(getLastLine(frame->getLineHead()));
                    currentLine->next = newLine;
                    frame->incrementLinesCount();
                }
            } break;
            default: continue;
        }
    }
    fclose(file);
    printf("Content were successfully loaded from the file\n");
    return 0;
}