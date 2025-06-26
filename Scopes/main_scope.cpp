#include "scopes.h"
#include "../Classes/ConsoleEditor/ConsoleEditor.h"

int consoleEditorScope() {
    ConsoleEditor console_editor = ConsoleEditor();

    while (true) {
        std::string command = getCommand();

        if (command[0] == '0') {
            break;
        }

        switch(command[0]) {
            case '1':
                switch (command[1]) {
                case '\0':
                        console_editor.createNewFrame();
                        break;
                case '0':
                        console_editor.loadFromFile();
                        break;
                default:
                        break;
                }
            case '2':
                console_editor.deleteFrame();
                break;
            case '3':
                console_editor.editFrame();
                break;
            case '4':
                console_editor.printAll();
                break;
            case '5':
                console_editor.encryptAll();
                break;
            case '6':
                console_editor.decryptAll();
                break;
            case '7':
                console_editor.undo();
                break;
            case '8':
                console_editor.redo();
                break;
            case '9':
                console_editor.saveToFile();
                break;
            case 'h':
                if (command[1] == 'e' & command[2] == 'l' & command[3] == 'p') ConsoleEditor::printHelpInfo();
                break;
            default:
                std::cout << "The command is not implemented" << std::endl;
                break;
        }
    }

    return 0;
}