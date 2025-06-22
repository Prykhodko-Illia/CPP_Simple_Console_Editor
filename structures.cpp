struct start {
    char value;
    start *ptr;
};

struct line {
    line *next = nullptr;
    virtual ~line() {};
};

struct textLine final : line {
    start *content;
};

struct infoLine final : line {
    start *name, *surname;
    start *email;
};

struct checkLine final : line {
    start *context;
    bool status = false;
};

struct command {
    int cmdNumber = 0;
    int lineNum = 0;
    int index = 0;
    int size = 0;
    start *ptr = nullptr;
};