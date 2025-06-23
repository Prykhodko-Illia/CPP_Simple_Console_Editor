#include "ConsoleEditor.h"
#include <windows.h>

typedef void (*encrypt_t)(std::vector<Frame *> &, int);

int encryption(std::vector<Frame *> &frames, bool enc) {
    HINSTANCE handle = LoadLibrary(TEXT("..//Classes//CaesarCipher//CaesarCipher.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE) {
        std::cout << "Lib not found" << std::endl;
        return 1;
    }

    auto encrypt = reinterpret_cast<encrypt_t>(GetProcAddress(handle, TEXT("encrypt")));
    if (encrypt == nullptr) {
        std::cout << "The function is not found";
        return 1;
    }

    const int key = getNumber("Write encryption key");

    if (enc) encrypt(frames, key);
    else encrypt(frames, -key);

    FreeLibrary(handle);

    return 0;
}

void ConsoleEditor::encryptAll() {
    encryption(frames, true);
}

void ConsoleEditor::decryptAll() {
    encryption(frames, false);
}