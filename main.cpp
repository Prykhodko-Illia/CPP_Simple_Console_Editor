#include "scopes.h"

int main() {
    int i = 0;
    while (true) {
        textInformationScope();
        ++i;
        if (i == 10) break;
    }

    return 0;
}