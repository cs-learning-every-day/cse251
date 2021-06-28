#ifndef DISPLAY_H
#define DISPLAY_H

#include "file.h"

void DisplayMenu();
void DisplayEvents(Node *head);
void DisplayCurrentActiveEvents(Node *head);
void DeleteExpiredEvents(Node *head);
void PrintEventInfo(Event *event);
#endif