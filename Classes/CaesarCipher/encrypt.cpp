#include "CaesarCipher.h"
#include "../classes.h"
#include "../../GeneralCommands/library.h"

void inline encryptString(start *string, const int key) {
    if (string == nullptr) {
        std::cout << std::endl;
        return;
    }

    start * temp = string;
    while (temp->ptr != nullptr) {
        temp->value = static_cast<char>(static_cast<int>(temp->value) + key);
        temp = temp->ptr;
    }
}

void encryptFrame(line *lineHead, int scope, int key) {
    line *temp = lineHead;

    while (temp != nullptr) {
        switch (scope) {
            case 1:
                {
                    auto textContent = dynamic_cast<textLine *>(temp)->content;
                    if (textContent != nullptr) encryptString(textContent, key);
                }
                break;
            case 2:
                {
                    auto infoName = dynamic_cast<infoLine *>(temp)->name;
                    if (infoName != nullptr) encryptString(infoName, key);
                }
                {
                    auto infoSurname = dynamic_cast<infoLine *>(temp)->surname;
                    if (infoSurname != nullptr) encryptString(infoSurname, key);
                }
                {
                    auto infoEmail = dynamic_cast<infoLine *>(temp)->name;
                    if (infoEmail != nullptr) encryptString(infoEmail, key);
                }
                break;
            case 3:
                {
                    auto checkContext = dynamic_cast<checkLine *>(temp)->context;
                    if (checkContext != nullptr) encryptString(checkContext, key);
                }
                break;
            default:
                std::cout << "Frame can't be encrypted: wrong scope";
                break;
        }

        temp = temp->next;
    }
}

void CaesarCipher::encrypt(std::vector<Frame *> &frames, const int key) {
    for (auto &frame : frames) {
        if (frame->getScopeId() == 1) {
            encryptFrame(dynamic_cast<TextInformation *>(frame)->getLineHead(), frame->getScopeId(), key);
        }

        if (frame->getScopeId() == 2) {
            encryptFrame(dynamic_cast<ContactInformation *>(frame)->getLineHead(), frame->getScopeId(), key);
        }

        if (frame->getScopeId() == 3) {
            encryptFrame(dynamic_cast<CheckBox *>(frame)->getLineHead(), frame->getScopeId(), key);
        }
    }
}