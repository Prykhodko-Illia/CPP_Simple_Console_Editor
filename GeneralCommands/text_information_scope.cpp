#include "../Classes/TextInformation/TextInformation.h"
#include "../scopes.h"

int textInformationScope() {
     TextInformation text_editor = TextInformation();

     while (true) {

         std::string command = getCommand();

         if (command[0] == '0') {
             break;
         }

         switch(command[0]) {
         case '1':
             switch (command[1]) {
                 case '\0':
                     text_editor.append();
                     break;
                 case '0':
                     text_editor.setCursor();
                     break;
             default:
                 break;
             }

             break;
         case '2':
             text_editor.newLine();
             break;
         case '3':
             text_editor.insert();
             break;
         case '4':
             text_editor.search();
             break;
         case '5':
             text_editor.deleteContent();
                 break;
         case '6':
             text_editor.cut();
             break;
         case '7':
             text_editor.paste();
             break;
         case '8':
             text_editor.copy();
             break;
         case '9':
             text_editor.insert_replacement();
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