struct start {
    char value;
    start *ptr;
};

struct line {
    line *next = nullptr;
    virtual ~line() = default;
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
    int frameNumber = 0;
    int lineNumber = 0;

    virtual ~command() = default;
};

struct textCommand final : command {
    int index = 0;
    int size = 0;
    start *content = nullptr;
};

struct contactCommand final : command {
    start *name = nullptr;
    start *surname = nullptr;
    start *email = nullptr;

    bool del_first = false;
};

struct checkBoxCommand final : command {
    bool status = false;
    start *content = nullptr;

    bool del_first = false;
};