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
	p.hand = NULL;
	return p;
}

char* getFirstName(Player p) {
	return p.fName;
}


