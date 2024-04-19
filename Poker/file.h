#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAX_NAME 20

bool file();

bool saveGame(char characterFirstName[MAX_NAME], char characterLastName[MAX_NAME], float characterEarnings, int characterWins, int characterLosses);

bool loadGame(char fileName[MAX_NAME]);

bool deleteGame(char fileName[MAX_NAME]);
