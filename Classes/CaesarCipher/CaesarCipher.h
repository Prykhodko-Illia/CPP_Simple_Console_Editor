#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "../Frame/Frame.h"
#include <vector>

class __declspec(dllexport) CaesarCipher {
public:
    CaesarCipher() = default;

    static void encrypt(std::vector<Frame *> &frames, const int key);
};

extern "C" __declspec(dllexport) void encrypt(std::vector<Frame *> &frames, const int key) {
    CaesarCipher::encrypt(frames, key);
}

#endif //CAESARCIPHER_H
