#include "scopes.h"

int textInformationScope(TextInformation &text_information, std::stack<command *> &undoStack, int frameNumber) {
     while (true) {
         std::string command = getCommand();

         if (command[0] == '0') {
             break;
         }

         switch(command[0]) {
         case '1':
             switch (command[1]) {
                 case '\0':
                     text_information.append(undoStack, frameNumber);
                     break;
                 case '0':
                     text_information.setCursor();
                     break;
             default:
                 break;
             }
             break;
         case '2':
             text_information.newLine(undoStack, frameNumber);
             break;
         case '3':
             text_information.insert(undoStack, frameNumber);
             break;
         case '4':
             text_information.search();
             break;
         case '5':
             text_information.deleteContent(undoStack, frameNumber);
                 break;
         case '6':
             text_information.cut();
             break;
         case '7':
             text_information.paste(undoStack, frameNumber);
             break;
         case '8':
             text_information.copy();
             break;
         case '9':
             text_information.insert_replacement(undoStack, frameNumber);
             break;
         case 'h':
             if (command[1] == 'e' & command[2] == 'l' & command[3] == 'p') TextInformation::printHelpInfo();
             break;
         default:
             std::cout << "The command is not implemented" << std::endl;
             break;
         }
     }
     return 0;
}