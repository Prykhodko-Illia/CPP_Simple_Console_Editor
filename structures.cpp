struct start {
    char value;
    start *ptr;
};


struct line {
    line *next = nullptr;

    // line * getNext() {
    //     return next;
    // }
    //
    // void setNext(line *nextLine) {
    //     next = nextLine;
    // }

    virtual ~line() {};
};

struct textLine : line {
    start *content;
};

struct infoLine : line{
    start *name, *surname;
    start *email;
};

struct command {
    int cmdNumber = 0;
    int lineNum = 0;
    int index = 0;
    int size = 0;
    start *ptr = nullptr;
};