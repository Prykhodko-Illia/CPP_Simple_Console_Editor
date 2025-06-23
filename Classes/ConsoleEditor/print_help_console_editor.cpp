#include "ConsoleEditor.h"

void ConsoleEditor::printHelpInfo() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "1 - Create new frame" << std::endl;
    std::cout << "2 - Delete frame" << std::endl;
    std::cout << "3 - Edit frame" << std::endl;
    std::cout << "4 - Print Information" << std::endl;
    std::cout << "5 - Encrypt text" << std::endl;
    std::cout << "6 - Decrypt text" << std::endl;
    std::cout << std::endl;
    std::cout << "0 - End execution" << std::endl;
    std::cout << std::endl;
}
