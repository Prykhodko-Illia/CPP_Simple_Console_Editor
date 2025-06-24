#ifndef SCOPES_H
#define SCOPES_H

#include "../Classes/classes.h"

int textInformationScope(TextInformation &, std::stack<command *> &, int);
int contactInformationScope(ContactInformation &, const std::stack<command *> &);
int checkBoxScope(CheckBox &, const std::stack<command *> &);
int consoleEditorScope();

#endif //SCOPES_H
