struct start {
    char value;
    start *ptr;
};


struct line {
    line *next;
};

struct textLine : line {
    start *content;
    textLine *next;
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