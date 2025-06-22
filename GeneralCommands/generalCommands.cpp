#include "library.h"

std::string getCommand() {
    std::string command;
    std::cout << "Choose the command:" << std::endl << ">";
    std::cin >> command;

    return command;
}

line * getLine(line *infoLineHead, int lineNum) {
    int i = 0;

    line *temp = infoLineHead;
    while (temp->next != nullptr && i < lineNum) {
        temp = dynamic_cast<infoLine *>(temp->next);
        ++i;
    }

    return temp;
}

line * getLastLine(line * firstLine) {
    line *temporary = nullptr;
    temporary = firstLine;

    int i = 0;
    while (temporary->next != nullptr) {
        temporary = temporary->next;
        i++;

        if (i > 1000) {
            std::cout << "Error in getting last line";
            break;
        }
    }

    return temporary;
}

std::string getInput() {
    std::cout << "Enter text to append: "  << std::endl;;

    std::string input;
    std::cin.ignore();

    std::getline(std::cin, input);

    return input;
}

int getNumber(const std::string &text) {
    int line = 0;

    std::cout << text << std::endl;
    std::cin >> line;

    return line;
}



start * convertStringToLinkedList(const std::string &input, int size) {
    start *head = nullptr;
    head = new start;
    head->value = input[0];
    head->ptr = nullptr;

    start *temp = nullptr;
    temp = head;

    for (int i = 1; (input[i] != '\n') && (i < size) && (input[i] != '\0'); i++) {
        start *nextChar = nullptr;
        nextChar = new start;
        nextChar->value = input[i];
        nextChar->ptr = nullptr;

        temp->ptr = nextChar;
        temp = nextChar;
    }

    return head;
}

int getSize(start *head) {
    int size = 0;
    while (head != nullptr) {
        head = head->ptr;
        size++;
    }

    return size;
}

void deleteString(start *first) {
    start *currentChar = first, *previousChar = nullptr;

    while (currentChar != nullptr) {
        previousChar = currentChar;
        currentChar = currentChar->ptr;
        delete previousChar;
    }
}

void printString(start *head, bool endLine) {
    start *temp = nullptr;
    temp = head;

    int i = 0;
    while ((temp->ptr != nullptr) && (i < 1000)) {
        std::cout << temp->value;
        temp = temp->ptr;
        i++;
    }

    std::cout << temp->value;

    if (endLine) std::cout << std::endl;
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

//Information Class
void infoLineInitialization(infoLine *linePointer, bool nextFlag) {
    linePointer->name = nullptr;
    linePointer->surname = nullptr;
    linePointer->email = nullptr;

    if (nextFlag) {
        linePointer->next = nullptr;
    }
}