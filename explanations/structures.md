# 📚 Structures
> Contained in the `structures.cpp` file
##  🔍 3 main structures:
### 1. Structure `start`
- Made as linked list to recreate **string** structure
- `char value` contains character
- `start *ptr` contains pointer to the next char
````c++
struct start {
    char value;
    start *ptr;
};
````
### 2. Structure `line`
- Made as linked list to recreate **lines** structure
- `start *content` contains pointer to the **structure** `start` (start of the string)
- `line *next` contains pointer to the next line

````c++
struct line {
    start *content;
    line *next;
};
````
### 3. Structure `command`
- Made for saving command that have been done to make undo and redo commands
- `int cmdNumber` - number of command that has been used
- `int lineNum, index` - number of line and index of the character
- `int size` - size of string that was appended or deleted
- `start *ptr` - pointer to the start of the string that was appended or deleted
> Some of that properties don't have to be used for some commands
````c++
struct command {
    int cmdNumber = 0;
    int lineNum = 0;
    int index = 0;
    int size = 0;
    start *ptr = nullptr;
};
````