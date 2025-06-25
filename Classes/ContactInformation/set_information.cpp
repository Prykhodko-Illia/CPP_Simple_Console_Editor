#include "ContactInformation.h"

void internalSetInField(infoLine *line, const std::string &fieldName, start *value, contactCommand *cmd) {
    if (fieldName == "name") {
        if (cmd != nullptr) cmd->name = line->name;
        deleteString(line->name);

        line->name = value;
    }

    if (fieldName == "surname") {
        if (cmd != nullptr) cmd->surname = line->surname;
        deleteString(line->surname);

        line->surname = value;
    }

    if (fieldName == "email") {
        if (cmd != nullptr) cmd->email = line->email;
        deleteString(line->email);

        line->email = value;
    }
}

void setInField(infoLine *line, const std::string &fieldName, contactCommand *cmd = nullptr) {
    std::cout << "Write " << fieldName << " to set in: " << std::endl;

    start *value = nullptr;

    {
        std::string input = getInput();
        value = convertStringToLinkedList(input, 32);
    }

    internalSetInField(line, fieldName, value, cmd);
}

void ContactInformation::setInfo(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the line number to set info in ");

    auto newLine = dynamic_cast<infoLine *>(getLine(infoLineHead, lineNumber));

    auto cmd = new contactCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 1;
    cmd->lineNumber = lineNumber;

    setInField(newLine, "name", cmd);
    setInField(newLine, "surname", cmd);
    setInField(newLine, "email", cmd);

    undoStack.push(cmd);
}

void ContactInformation::editInfo(std::stack<command *> &undoStack, int frameNumber) {
    int lineNumber = getNumber("Write the line number to edit");

    auto newLine = dynamic_cast<infoLine *>(getLine(infoLineHead, lineNumber));

    int fN = 0, fS = 0, fE = 0;
    std::cout << "Write 1 if you want to edit: Name/Surname/Email "
                 "(ex: 1 0 1) - sets all except surname" << std::endl;

    auto cmd = new contactCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 2;
    cmd->lineNumber = lineNumber;

    std::cin >> fN >> fS >> fE;
    if (fN == 1) setInField(newLine, "name", cmd);
    if (fS == 1) setInField(newLine, "surname", cmd);
    if (fE == 1) setInField(newLine, "email", cmd);

    undoStack.push(cmd);
}

void ContactInformation::newLine(std::stack<command *> &undoStack, int frameNumber) {
    auto lastLine = dynamic_cast<infoLine *>(getLastLine(infoLineHead));
    lastLine->next = new infoLine;

    auto newLine = dynamic_cast<infoLine *>(lastLine->next);
    infoLineInitialization(newLine, true);

    auto cmd = new contactCommand;
    cmd->frameNumber = frameNumber;
    cmd->cmdNumber = 3;

    setInField(newLine, "name");
    setInField(newLine, "surname");
    setInField(newLine, "email");

    ++linesCount;

    undoStack.push(cmd);
}