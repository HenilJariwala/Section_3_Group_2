#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"


Player CreatePlayer(char* fName, char* lName) {
	Player p;
	strncpy(p.fName, fName, MAXNAME);
	strncpy(p.LName, lName, MAXNAME);
	p.Money = 500.00;
	p.Wins = 0;
	p.Losses = 0;
	return p;
}

char* getFirstName(Player p) {
	return p.fName;
}

char* getLastName(Player p) {
	return p.LName;
}

double getMoney(Player p) {
	return p.Money;
}

void setMoney(Player p, int amount) {
	p.Money += amount;
}

int getWins(Player p) {
	return p.Wins;
}

void setWins(Player p) {
	p.Wins++;
}

int getLosses(Player p) {
	return p.Losses;
}

void setLosses(Player p) {
	p.Losses++;
}


