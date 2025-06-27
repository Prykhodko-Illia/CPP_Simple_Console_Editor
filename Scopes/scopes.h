#ifndef SCOPES_H
#define SCOPES_H

#include "../Classes/classes.h"
#include "../Classes/ConsoleEditor/ConsoleEditor.h"

int textInformationScope(TextInformation &, std::stack<command *> &, int);
int contactInformationScope(ContactInformation &, std::stack<command *> &, int);
int checkBoxScope(CheckBox &, std::stack<command *> &, int);
int consoleEditorScope(ConsoleEditor&);

#endif //SCOPES_H
