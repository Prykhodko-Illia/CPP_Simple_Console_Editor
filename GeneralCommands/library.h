#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "structures.cpp"

line * getLastLine(line *);
line * getLine(line *, int);
textLine * loadFromFile(textLine *);

std::string getInput();

start * convertStringToLinkedList(const std::string &, int);
start * getCharPointerByIndexes(textLine *, int, int);

int getNumber(const std::string &);
int getSize(start *);
int searchInLine(start *, std::string);

void deleteString(start *);
void clearHeap(textLine *);
void printString(start *);

void internalAppend(textLine *, start *);
void internalNewLine(textLine *);
void internalDelete(textLine *, command*, int, int, int);
void internalInsert(textLine *, start *, int, int);


void infoLineInitialization(infoLine *, bool);

#endif //LIBRARY_H
