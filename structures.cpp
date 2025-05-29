struct start {
    char value;
    start *ptr;
};

struct line {
    start *content;
    line *next;
};
