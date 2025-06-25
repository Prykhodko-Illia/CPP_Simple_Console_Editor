#include "scopes.h"

int contactInformationScope(ContactInformation &contact_information, std::stack<command *> &undoStack, int frameNumber) {
    while (true) {
        std::string command = getCommand();

        if (command[0] == '0') {
            break;
        }

        switch(command[0]) {
            case '1':
                contact_information.setInfo(undoStack, frameNumber);
                break;
            case '2':
                contact_information.editInfo(undoStack, frameNumber);
                break;
            case '3':
                contact_information.newLine(undoStack, frameNumber);
                break;
            case '4':
                contact_information.deleteInfo(undoStack, frameNumber);
                break;
            case 'h':
                if (command[1] == 'e' & command[2] == 'l' & command[3] == 'p') ContactInformation::printHelpInfo();
                break;
            default:
                std::cout << "The command is not implemented" << std::endl;
                break;
        }
    }

    return 0;
};
