#define CRT_SECURE_NO_WARNGINS_
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"
// Hand struct

void StartGame(Player p) {
	// deal cards
	int round = 1;
	int currentBet = 50;
	int pool;
	int playerBet;
	int choice;

	printf("Player Name: %s\n", getFirstName(p));

	Player bot = CreatePlayer("Angry", "John");

	Card botHand[7];



	Card hand[7];
	Card table[5];

	// hand starts with 2 cards

	int HandNum = 2;
	int tableNum = 3;

	// this will be dealt, start with two random cards

	Card card1 = CreateCard("Diamonds", "5");
	Card card2 = CreateCard("Clubs", "6");
	hand[0] = card1;
	hand[1] = card2;

	// Then it will sort and value the cards given. This is so bots may value theyre hand and bet accordingly



	// afterwards, three cards will be dealt to the table, inputing them into every players hand 

	Card card3, card4, card5;
	//card3 = CreateCard("Diamonds", "8");
	//card4 = CreateCard("Clubs", "5");
	//card5 = CreateCard("Hearts", "Queen");

	//Card cardB1 = CreateCard("Hearts", "Ace");
	//Card cardB2 = CreateCard("Diamonds", "Ace");

	//botHand[0] = cardB1;
	//botHand[1] = cardB2;



	//hand[2] = card3;
	//hand[3] = card4;
	//hand[4] = card5;

	//table[0] = card3;
	//table[1] = card4;
	//table[2] = card5;

	//botHand[2] = card3;
	//botHand[3] = card4;
	//botHand[4] = card5;
	HandNum = 5;

	// these will be dealt soon enough
	// in reality, it will be much easier, as for each round, there will be a deal() function to randomly add
	//Card cardR2 = CreateCard("Spade", "Ace");
	//Card cardR3 = CreateCard("Hearts", "Two");


	// This will start betting process


	//int cardValue = ValueRank(getRank(card1));
	//printf("%d", cardValue);

	while (round < 4) {
		if (round == 2) {
			//table[3] = cardR2;
			//hand[5] = cardR2;
			//botHand[5] = cardR2;
			HandNum++;
			tableNum++;
		}
		if (round == 3) {
			//table[4] = cardR3;
			//hand[6] = cardR3;
			//botHand[6] = cardR3;
			tableNum++;
			HandNum++;
		}
		int checks = 0;
		printf("Round %d\n", round);

		while (checks < 3) {
			printf("Your hand: ");
			printHand(hand, 2);
			printf("\nThis is on the table: ");
			//printHand(table, tableNum);
			printf("\n");

			printf("Your current funds: 500\n");
			printf("The current bet: %d\n", currentBet);

			printf("Would you like to 1. check? 2. Fold? 3. Raise. 4 Call?\n");

			scanf_s("%d", &choice);
			// will be switch contune later on

			if (choice == 1) {
				// check to see if available, if it is pass the turn
				checks++;
			}
			else if (choice == 2) {
				// remove player from game
				printf("You lose");
				round = 10;
				checks = 10;
			}
			else if (choice == 3) {
				printf("What is your new bet? :");
				scanf_s("%d", &playerBet);
				currentBet = currentBet + playerBet;
			}
			else if (choice == 4) {
				playerBet = currentBet;
				printf("Player bet = %d", playerBet);
			}
			else {
				printf("not accetpable");
			}


			printf("BOT TURN\n\n\n");


		}
		round++;


	}
	int BotValue = ValueHand(botHand, HandNum);
	int playerValue = ValueHand(hand, HandNum);

	if (BotValue >= playerValue) {
		printf("Bot wins");
	}
	else {
		printf("Player wins");
	}

	// at the end, determine winner 
}

int ValueRank(char* rank) {
	if (strcmp(rank, "Ace") == 0) {
		return 14;
	}
	else if (strcmp(rank, "King") == 0) {
		return 13;
	}
	else if (strcmp(rank, "Queen") == 0) {
		return 12;
	}
	else if (strcmp(rank, "Jack") == 0) {
		return 11;
	}
	else {
		return atoi(rank);
	}
}

int ValueHand(Card* hand, int size) {
	// checking top up, so royal flush first
	if (isRoyalFlush(hand, size) == true) {
		return 90;
	}
	if (isStraightFlush(hand, size) == true) {
		return 80;
	}
	if (isFourKind(hand, size) == true) {
		return 70;
	}
	if (isFullHouse(hand, size) == true)
		return 60;
	if (isStraight(hand, size) == true)
		return 50;
	if (isFlush(hand, size) == true) {
		return 40;
	}
	if (isTriple(hand, size) == true)
		return 30;
	if (isDoublePair(hand, size) == true) {
		return 20;
	}
	if (isPair(hand, size) == true) {
		return 15;
	}
	return 14;

}


// Scoring hands, this will be 
// royal flush - 10,jack,queen,king and ace, all the same suit

bool isRoyalFlush(Card* hand, int size) {
	int flush = 0;
	int straight;
	bool isTen = false;
	bool isJack = false;
	bool  isQueen = false;
	bool isKing = false;
	bool isAce = false;
	// under pretense that cards will be sorted
	// first check if all cards are same suit
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (strcmp(hand[i].suit, hand[j].suit) == 0) {
				flush++;
			}
		}
		if (flush < 5) {
			flush = 0;
		}

	}
	for (int i = 0; i < size; i++) {
		switch (ValueRank(hand[i].rank)) {
		case 10: isTen = true; break;
		case 11: isJack = true; break;
		case 12: isQueen = true; break;
		case 13: isKing = true; break;
		case 14: isAce = true; break;
		default: break;
		}
	}
	return flush >= 5 && isTen && isJack && isQueen && isKing && isAce;
}



bool isStraightFlush(Card* hand, int size) {
	// just using the indiviudal fucntions for each a stragiht and flush

	return isStraight(hand, size) && isFlush(hand, size);

}

bool isStraight(Card* hand, int size) {
	int straight = 0;
	for (int i = 0; i < size; i++) {
		if (ValueRank(hand[i].rank) == ValueRank(hand[i - 1].rank) + 1) {
			straight++;
		}
	}
	return straight >= 4;
}

bool isFlush(Card* hand, int size) {
	int flush = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (strcmp(hand[i].suit, hand[j].suit) == 0) {
				flush++;
			}
		}
		if (flush < 5) {
			flush = 0;
		}

	}
	return flush >= 5;
}

bool isPair(Card* hand, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j != i) {
				if (ValueRank(hand[i].rank) == ValueRank(hand[j].rank)) {
					return true;
				}
			}
		}
	}
	return false;
}


bool isFourKind(Card* hand, int size) {
	int check = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ValueRank(hand[i].rank) == ValueRank(hand[j].rank)) {
				check++;
			}
		}
		if (check < 4) {
			check = 0;
		}
	}
	return check >= 4;
}

bool isTriple(Card* hand, int size) {
	int check = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ValueRank(hand[i].rank) == ValueRank(hand[j].rank)) {
				check++;
			}
		}
		if (check < 3) {
			check = 0;
		}
	}
	return check >= 3;
}

bool isDoublePair(Card* hand, int size) {
	int rankUsed = 0;
	int pair = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j != i) {
				if (ValueRank(hand[i].rank) == ValueRank(hand[j].rank)) {
					if (rankUsed != ValueRank(hand[i].rank)) {
						pair++;
						rankUsed = ValueRank(hand[i].rank);
					}
				}
			}
		}
	}
	return pair >= 2;
}
bool isFullHouse(Card* hand, int size) {
	int check = 0;
	int rankUsed = 0;
	int pair = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j != i) {
				if (ValueRank(hand[i].rank) == ValueRank(hand[j].rank)) {
					if (rankUsed != ValueRank(hand[i].rank)) {
						pair++;
						rankUsed = ValueRank(hand[i].rank);
					}
				}
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ValueRank(hand[i].rank) == ValueRank(hand[j].rank) && rankUsed != ValueRank(hand[i].rank)) {
				check++;
			}
		}
		if (check < 3) {
			check = 0;
		}
	}
	return pair >= 2 && check >= 3;
}







