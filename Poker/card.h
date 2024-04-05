#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining constants for suits and ranks
#define NUM_SUITS 4
#define NUM_RANKS 13

// Defining number of card user will get in starting (Hands)
#define CARDS_IN_HAND 2

// Defining a struct to represent a playing card
typedef struct card{
    char* suit;
    char* rank;
} Card;

Card* createDeck();
void shuffleDeck(Card*);
void dealCards(Card* deck, Card* playerHand, Card* computerHand);

Card CreateCard(const char* suit, const char* rank);