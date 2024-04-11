#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20

// Defining constants for suits and ranks
#define NUM_SUITS 4
#define NUM_RANKS 13

// Defining number of card user will get in starting (Hands)
#define CARDS_IN_HAND 2

// Defining a struct to represent a playing card
typedef struct card{
    char suit[MAXSIZE];
    char rank[MAXSIZE];
} Card;

Card* createDeck();
void shuffleDeck(Card*);
void dealCards(Card* deck, Card* playerHand, Card* computerHand);
void sortHand(Card* hand, int size);
char* getSuit(Card c);

char* getRank(Card c);

Card CreateCard( char* suit, char* rank);

void printHand(Card* deck, int size);

void printCard(Card c);

Card dealTop(Card* deck);