#pragma once

#pragma once
#include "Card.h"
#define MAXNAME 20

typedef struct Player {
	char fName[MAXNAME];
	char LName[MAXNAME];
	double Money;
	int Wins;
	int Losses;
}Player;

Player CreatePlayer(char*, char*);

char* getFirstName(Player p);

char* getLastName(Player p);

double getMoney();

void setMoney(Player p, int amount);

int getWins(Player p);

void setWins(Player p);

int getLosses(Player p);

void setLosses(Player p);

Player CopyPlayer(Player p);

// Save/ Load Player

