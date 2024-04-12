#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAX_NAME 20

bool file();

bool saveGame(char characterName[MAX_NAME], float characterEarnings, int characterWins, int characterLosses);

bool loadGame();

bool deleteGame(char fileName[MAX_NAME]);
