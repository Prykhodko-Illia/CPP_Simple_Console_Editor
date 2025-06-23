#include "scopes.h"

int textInformationScope(TextInformation &text_information) {
     while (true) {
         std::string command = getCommand();

         if (command[0] == '0') {
             break;
         }

         switch(command[0]) {
         case '1':
             switch (command[1]) {
                 case '\0':
                     text_information.append();
                     break;
                 case '0':
                     text_information.setCursor();
                     break;
             default:
                 break;
             }
             break;
         case '2':
             text_information.newLine();
             break;
         case '3':
             text_information.insert();
             break;
         case '4':
             text_information.search();
             break;
         case '5':
             text_information.deleteContent();
                 break;
         case '6':
             text_information.cut();
             break;
         case '7':
             text_information.paste();
             break;
         case '8':
             text_information.copy();
             break;
         case '9':
             text_information.insert_replacement();
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