# 🚀 Class: `TextEditor`
## 🔐 Properties

### Private Fields
They are made private to kept internal data private from user

```c++
private:
    line *lineHead = nullptr;
    std::stack<command *> undoStack;
    std::stack<command *> redoStack;
    start *copyBuffer = nullptr;

    int cursorLine = 1;
    int cursorChar = 0;
```

1. lineHead - start of the line used to save text structure
2. undoStack - stack, made for saving undo commands
3. redoStack - stack, used for saving redo commands
4. copyBuffer - saving pointer to start character of the copied string
5. cursor pointers

---

### 🛠️ Public Methods

#### Constructor:
Initializing first line

```c++
TextEditor() {
    lineHead = new line;

    lineHead->content = nullptr;
    lineHead->next = nullptr;
}
```

#### Static command:
Made to print help independent of an instance

```c++
static void printHelpInfo();
```

#### Commands:
Main logic

```c++
void append();
void newLine();
int saveToFile();
...
void paste();
void copy();
void insert_replacement();
```

#### Destructor:
Uses implemented clearHeap procedure to delete based on structure

```c++
~TextEditor() {
    clearHeap(lineHead);
}
```
