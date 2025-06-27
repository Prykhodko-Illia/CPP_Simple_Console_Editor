#include "Scopes/scopes.h"
#include <vector>
#include "Classes/ConsoleEditor/ConsoleEditor.h"

void createTab() {

}

int main() {
    std::vector<ConsoleEditor *> tabs;

    while (true) {
        std::cout << std::endl;
        std::string command = getCommand();

        if (command[0] == '0') {
            break;
        }

        switch(command[0]) {
            case '1':
                tabs.push_back(new ConsoleEditor());
                break;
            case '2': {
                int tabNumber = getNumber("Write a number of frame you want to delete: ");
                if (tabNumber > tabs.size() || tabNumber < 1) {
                    std::cout << "Invalid number" << std::endl;
                } else {
                    tabs.erase(tabs.begin() + tabNumber);
                }
            } break;
            case '3': {
                int tabNumber = getNumber("Write number of frame to edit");

                if (tabNumber > tabs.size() || tabNumber < 1) {
                    std::cout << "Invalid number" << std::endl;
                } else {
                    consoleEditorScope(*tabs[tabNumber - 1]);
                }
            } break;
            case '4':
                std::cout << "You have " << tabs.size() << " number of tabs";
                break;
            case 'h':
                if (command[1] == 'e' & command[2] == 'l' & command[3] == 'p') {
                    std::cout << "Available commands:" << std::endl;
                    std::cout << "1 - Create new tab" << std::endl;
                    std::cout << "2 - Delete tab" << std::endl;
                    std::cout << "3 - Edit tab" << std::endl;
                    std::cout << "4 - Print number of tabs" << std::endl;
                } break;
            default: break;
        }
    }

    return 0;
}