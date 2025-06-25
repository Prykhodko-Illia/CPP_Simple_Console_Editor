#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "structures.cpp"

line * getLastLine(line *);
line * getLine(line *, int);
textLine * loadFromFile(textLine *);

std::string getInput();
std::string getCommand();

start * convertStringToLinkedList(const std::string &, int);
start * getCharPointerByIndexes(textLine *, int, int);

int getNumber(const std::string &);
int getSize(start *);
int searchInLine(start *, std::string);

void deleteString(start *);
void clearHeap(textLine *);
void printString(start *, bool = true);

void internalAppend(textLine *, start *);
void internalNewLine(textLine *);
void internalDelete(textLine *, textCommand*, int, int, int);
void internalInsert(textLine *, start *, int, int);

void infoLineInitialization(infoLine *, bool);
void internalSetInField(infoLine *, const std::string &, start *, contactCommand * = nullptr);
void internalDeleteInfo(infoLine *&, int, contactCommand *, int &);

void checkLineInitialization(checkLine *, bool);
void internalSetCheckBoxInfo(checkLine *, start *, int, checkBoxCommand *);
void internalSetCheckBoxStatus(checkLine *, int, int, checkBoxCommand *);
void internalDeleteCheckLine(checkLine *&, int, checkBoxCommand *, int &);

#endif //LIBRARY_H
