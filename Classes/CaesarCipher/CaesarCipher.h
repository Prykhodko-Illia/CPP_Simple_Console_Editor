#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "../Frame/Frame.h"
#include <vector>

class CaesarCipher {
public:
    CaesarCipher() {};

    static void encrypt(std::vector<Frame *> &frames, const int key);
};



#endif //CAESARCIPHER_H
