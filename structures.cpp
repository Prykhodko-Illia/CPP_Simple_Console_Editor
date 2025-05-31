struct start {
    char value;
    start *ptr;
};

struct line {
    start *content;
    line *next;
};

struct command {
    int cmdNumber = 0;
    int lineNum = 0;
    int index = 0;
    int size = 0;
    start *ptr = nullptr;
};