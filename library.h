#ifndef LIBRARY_H
#define LIBRARY_H

#endif //LIBRARY_H

#include <iostream>

line * getLastLine(line *);
line * loadFromFile(line *);

std::string getInput();

start * convertStringToLinkedList(std::string , int);
start * getCharPointerByIndexes(line *, int, int);

int getSize(start *);
int searchInLine(start *, std::string);

void printString(start *);
void internalDelete(line *, command*, int, int, int);
void internalInsert(line *, command *, start *, int, int);