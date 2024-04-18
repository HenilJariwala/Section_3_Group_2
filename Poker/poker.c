#define _CRT_SECURE_NO_WARNINGS
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"
#include "time.h"
#include <stdlib.h>
// Hand struct

 void StartGame(Player* p) {
	// deal cards
	int round = 1;
	int currentBet = 0;
	int pool = 50;
	int playerBet = 0;
	int choice;
	int botBet = 0;
	int roundRisk = 0;
	int roundChance = 10;
	int botFold = 0;
	int playerFold = 0;

	Card* deck = createDeck();
	shuffleDeck(deck);

	Card playerHand[7];
	Card computerHand[7];

	dealCards(deck, playerHand, computerHand);

	printf("Player Name: %s\n", getFirstName(*p));

	Player bot = CreatePlayer("Angry", "John");

	Card table[5];

	// hand starts with 2 cards

	int HandNum = 2;
	int tableNum = 3;


	// afterwards, three cards will be dealt to the table, inputing them into every players hand 
	for (int i = 0; i < 3; i++) {
		table[i] = dealTop(deck);
		playerHand[i + 2] = table[i];
		computerHand[i + 2] = table[i];
	}




	HandNum = 5;


	while (round < 4) {
		if (round == 2) {
			table[tableNum] = dealTop(deck);
			playerHand[HandNum] = table[tableNum];
			computerHand[HandNum] = table[tableNum];

			roundRisk += 5;
			roundChance = 30;
			HandNum++;
			tableNum++;
		}
		if (round == 3) {
			table[tableNum] = dealTop(deck);
			playerHand[HandNum] = table[tableNum];
			computerHand[HandNum] = table[tableNum];

			roundRisk += 5;
			roundChance = 50;
			tableNum++;
			HandNum++;
		}
		int checks = 0;
		printf("Round %d\n", round);

		while (checks < 2) {
			printf("Your hand: ");
			printHand(playerHand, 2);
			printf("\nThis is on the table: ");
			printHand(table, tableNum);
			printf("\n");

			printf("Your current funds: %f \n", getMoney(p));
			printf("Your current bet: %d\n", playerBet);
			printf("The current bet: %d\n", currentBet);
			printf("The current pool: %d\n", pool);
			int pass = 1;
			while (pass > 0) {
				printf("Would you like to 1. check? 2. Fold? 3. Raise? 4. Call?\n");



				scanf_s("%d", &choice);
				// will be switch contune later on

				if (choice < 0) {
					choice = 1;
				   printf("invalid input");
				   scanf_s("%d", &choice);
				}
				else {


					switch (choice) {
					case 1:
						if (currentBet > playerBet) {
							printf("Player bet must be equal or more than current bet\n");
							break;
						}
						else {
							checks++;
							pass--;
							break;
						}
					case 2:
						printf("Player fold, bot Wins\n");
						round = 10;
						checks = 10;
						playerFold = 1;
						pass--;
						p->Losses++;
						break;
					case 3:
						printf("Raise by how much?\n");
						scanf("%d", &choice);
						choice = choice + currentBet;
						if (choice > p->Money || choice < 0) {
							printf("Unable to process\n");
							break;
						}
						else {
							playerBet = playerBet + choice;
							pool = pool + choice;
							currentBet += choice;
							p->Money = p->Money - choice;
							pass--;
							break;
						}
					case 4:
						printf("Called, new bet is: %d\n", currentBet);
						p->Money -= currentBet;
						playerBet += currentBet;
						pool += currentBet;
						checks++;
						pass--;
						break;
					default:
						printf("Not available number\n");
						choice = 0;
					}
				}
			}
			if (playerFold == 1) {
				break;
			}

			printf("BOT TURN\n\n\n");

			int BotGuess = ValueHand(computerHand, HandNum);
			int BotChoice = rand() % BotGuess + 1;

			if (BotChoice > roundChance) {
				printf("Bot Raises by 50\n");
				botBet += 50;
				pool += 50;
				currentBet += 50;
				checks--;
			}
			else if (BotChoice < roundChance && BotChoice > roundRisk && botBet < currentBet) {
				printf("The bot calls\n");
				int difference = currentBet - botBet;
				botBet += difference;
				pool += difference;
				checks++;

			}
			else if (BotChoice < roundChance && BotChoice > roundRisk && botBet >= currentBet) {
				printf("The bot checks\n");
				checks++;
			}
			else {
				printf("The bot folds! Player wins!\n");
				p->Money += pool;
				p->Wins++;
				printf("New earnings: %f", p->Money);
				round = 10;
				botFold = 1;

				break;
			}


		}
		round++;


	}
	int BotValue = ValueHand(computerHand, HandNum);
	int playerValue = ValueHand(playerHand, HandNum);
	if (botFold == 1 || playerFold == 1) {
		printf("");
	}
	else {
		if (BotValue >= playerValue) {
			printf("Bot wins");
		}
		else {
			printf("Player wins");
			p->Money += pool;
		}
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
	int power = 0;
	// checking top up, so royal flush first
	if (isRoyalFlush(hand, size) == true) {
		//power = 90;
		return 90;
	}
	if (isStraightFlush(hand, size) == true) {
		//power += 80;
		return 80;
	}
	if (isFourKind(hand, size) == true) {
		//power += 70;
		return 70;
	}
	if (isFullHouse(hand, size) == true)
		return 60;
		//power += 60;
	if (isStraight(hand, size) == true)
		return 50;
		//power += 50;
	if (isFlush(hand, size) == true) {
		return 40;
		//power += 40;
	}
	if (isTriple(hand, size) == true)
		return 30;
		//power += 30;
	if (isDoublePair(hand, size) == true) {
		//power += 
			return 20;
	}
	if (isPair(hand, size) == true) {
		//power += 15;
		return 15;
	}
	 return 14;
	//return power;
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







