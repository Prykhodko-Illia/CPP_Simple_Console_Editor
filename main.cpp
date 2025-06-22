#include "Scopes/scopes.h"

int main() {
    int i = 0;
    while (true) {
        contactInformationScope();
        ++i;
        if (i == 10) break;
    }

    return 0;
}