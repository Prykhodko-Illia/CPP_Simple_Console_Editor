#include "TextInformation.h"

void TextInformation::printHelpInfo() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "1 - Append to the current position" << std::endl;
    std::cout << "2 - Start new line" << std::endl;
    std::cout << "3 - Insert at current position" << std::endl;
    std::cout << "4 - Searching string in the text" << std::endl;
    std::cout << "5 - Delete" << std::endl;
    std::cout << "6 - Cut" << std::endl;
    std::cout << "7 - Paste" << std::endl;
    std::cout << "8 - Copy" << std::endl;
    std::cout << "9 - Insert with replacement" <<std::endl;
    std::cout << "10 - Set cursor" << std::endl;
    std::cout << std::endl;
    std::cout << "0 - End execution" << std::endl;
    std::cout << std::endl;
}
