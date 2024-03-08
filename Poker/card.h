#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining constants for suits and ranks
#define NUM_SUITS 4
#define NUM_RANKS 13

// Defining a struct to represent a playing card
typedef struct card{
    char* suit;
    char* rank;
} Card;

Card* createDeck();