#include "TextInformation.h"

void TextInformation::printHelpInfo() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "1 - append to the current position" << std::endl;
    std::cout << "2 - start new line" << std::endl;
    std::cout << "3 - insert at current position" << std::endl;
    std::cout << "4 - searching string in the text" << std::endl;
    std::cout << "5 - delete" << std::endl;
    std::cout << "6 - cut" << std::endl;
    std::cout << "7 - paste" << std::endl;
    std::cout << "8 - copy" << std::endl;
    std::cout << "9 - insert with replacement" <<std::endl;
    std::cout << "10 - set cursor" << std::endl;
    std::cout << std::endl;
    std::cout << "0 - end execution" << std::endl;
    std::cout << std::endl;
}
