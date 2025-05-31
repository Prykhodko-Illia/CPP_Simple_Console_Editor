#include "TextEditor.h"

void TextEditor::insert_replacement() {
    std::cout << "Choose line and index" << std::endl;

    int lineIdx = 0, charIdx = 0;
    std::cin >> lineIdx >> charIdx;

    std::cout << std::endl;

    std::string input = getInput();
    start *first = convertStringToLinkedList(input, 32);
    int size = getSize(first);

    command* cmd = new command;
    cmd->cmdNumber = 14;
    cmd->lineNum = lineIdx;
    cmd->index = charIdx;
    cmd->size = size;

    internalDelete(lineHead, cmd, lineIdx, charIdx, size);
    internalInsert(lineHead, first, lineIdx, charIdx);

    undoStack.push(cmd);
}