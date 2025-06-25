#include "scopes.h"

int checkBoxScope(CheckBox &check_box, std::stack<command *> &undoStack, int frameNumber) {
    while (true) {
        std::string command = getCommand();

        if (command[0] == '0') {
            break;
        }

        switch(command[0]) {
            case '1':
                check_box.setCheckBoxInfo(undoStack, frameNumber);
                break;
            case '2':
                check_box.setCheckBoxStatus(undoStack, frameNumber);
                break;
            case '3':
                check_box.newCheckLine(undoStack, frameNumber);
                break;
            case '4':
                check_box.deleteCheckLine(undoStack, frameNumber);
                break;
            case 'h':
                if (command[1] == 'e' & command[2] == 'l' & command[3] == 'p') CheckBox::printHelpInfo();
                break;
            default:
                std::cout << "The command is not implemented" << std::endl;
                break;
        }
    }

    return 0;
};
