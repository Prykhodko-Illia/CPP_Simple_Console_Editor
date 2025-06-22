#include "ContactInformation.h"

void setInField(infoLine *line, const std::string &fieldName) {
    std::cout << "Write " << fieldName << " to set in: " << std::endl;

    start *value = convertStringToLinkedList(getInput(), 32);

    if (fieldName == "name") line->name = value;
    if (fieldName == "surname") line->surname = value;
    if (fieldName == "email") line->email = value;
}

void ContactInformation::setInfo() {
    infoLine *newLine = dynamic_cast<infoLine *>(
    getLine(infoLineHead, getNumber("Write the line number to set info in ")));

    setInField(newLine, "name");
    setInField(newLine, "surname");
    setInField(newLine, "email");
}

void ContactInformation::editInfo() {
    infoLine *newLine = dynamic_cast<infoLine *>(
        getLine(infoLineHead, getNumber("Write the line number to edit")));

    int fN = 0, fS = 0, fE = 0;
    std::cout << "Write 1 if you want to edit: Name/Surname/Email "
                 "(ex: 1 0 1) - sets all except surname" << std::endl;

    std::cin >> fN >> fS >> fE;
    if (fN == 1) setInField(newLine, "name");
    if (fS == 1) setInField(newLine, "surname");
    if (fE == 1) setInField(newLine, "email");
}

void ContactInformation::newLine() {
    infoLineHead->next = new infoLine;

    auto *newLine = dynamic_cast<infoLine *>(infoLineHead->next);
    infoLineInitialization(newLine, true);

    setInField(newLine, "name");
    setInField(newLine, "surname");
    setInField(newLine, "email");

    ++linesCount;
}