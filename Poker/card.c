#define _CRT_SECURE_NO_WARNINGS
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"
#include <string.h>
#include <stdlib.h>
//#include <cstring>

#include <stdio.h>
Card* createDeck() {

    //Assigning dynmaic memory to store the deck of cards 
    Card* deck = (Card*)malloc(NUM_SUITS * NUM_RANKS * sizeof(Card));
    if (deck == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    //Creating arrays to store all the suits and rank 
    char* suits[NUM_SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    char* ranks[NUM_RANKS] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    //Here the index represent total cards so the last index will be 51 as it is starting from 0
    int index = 0;
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int rank = 0; rank < NUM_RANKS; rank++) {
            //deck[index].suit = suits[suit];
            //deck[index].rank = ranks[rank];
            deck[index] = CreateCard(suits[suit], ranks[rank]);
            index++;
        }
    } 

    return deck;
}
int cardsTaken =0;

char* getSuit(Card c) {
    return c.suit;
}

char* getRank(Card c) {
    return c.rank;
}

// Function to shuffle the deck of cards
void shuffleDeck(Card* deck) {
    srand(time(NULL)); // Seed the random number generator

    for (int i = NUM_SUITS * NUM_RANKS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to distribute cards 
void dealCards(Card* deck, Card* playerHand, Card* computerHand) {
     
    // Deal cards to the player
    for (int i = 0; i < CARDS_IN_HAND; ++i) {
        playerHand[i] = deck[NUM_SUITS * NUM_RANKS - 1 - i];
    }
    cardsTaken += 2;

    // Deal cards to the computer
    for (int i = 0; i < CARDS_IN_HAND; ++i) {
        computerHand[i] = deck[NUM_SUITS * NUM_RANKS   - cardsTaken - i];
    }
    cardsTaken += 2;
}

void sortHand(Card* hand, int size) {
    int i, j;
    Card temp;

    // Order of suits based on priority
    char* suitOrder[NUM_SUITS] = { "Spades", "Hearts", "Diamonds", "Clubs" };

    // Bubble sort: Comparing both suit and rank
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            // Compare suits first based on suitOrder
            int suitIndex1, suitIndex2;
            for (int k = 0; k < NUM_SUITS; k++) {
                if (strcmp(hand[j].suit, suitOrder[k]) == 0)
                    suitIndex1 = k;
                if (strcmp(hand[j + 1].suit, suitOrder[k]) == 0)
                    suitIndex2 = k;
            }
            // If suits are the same, compare ranks
            if (suitIndex1 == suitIndex2) {
                
                // Special handling for face cards
                if (strcmp(hand[j].rank, "Ace") == 0) {
                    if (strcmp(hand[j + 1].rank, "Ace") != 0) {  
                        temp = hand[j];
                        hand[j] = hand[j + 1];
                        hand[j + 1] = temp;
                    }
                }
                else if (strcmp(hand[j].rank, "King") == 0) {
                    if (strcmp(hand[j + 1].rank, "Ace") != 0 && strcmp(hand[j + 1].rank, "King") != 0) {  
                        temp = hand[j];
                        hand[j] = hand[j + 1];
                        hand[j + 1] = temp;
                    }
                }
                else if (strcmp(hand[j].rank, "Queen") == 0) {
                    if (strcmp(hand[j + 1].rank, "Ace") != 0 && strcmp(hand[j + 1].rank, "King") != 0 && strcmp(hand[j + 1].rank, "Queen") != 0) {  
                        temp = hand[j];
                        hand[j] = hand[j + 1];
                        hand[j + 1] = temp;
                    }
                }
                else if (strcmp(hand[j].rank, "Jack") == 0) {
                    if (strcmp(hand[j + 1].rank, "Ace") != 0 && strcmp(hand[j + 1].rank, "King") != 0 && strcmp(hand[j + 1].rank, "Queen") != 0 && strcmp(hand[j + 1].rank, "Jack") != 0) {  
                        temp = hand[j];
                        hand[j] = hand[j + 1];
                        hand[j + 1] = temp;
                    }
                }
                // Comparing ranks as strings
                else if (strcmp(hand[j].rank, hand[j + 1].rank) < 0) {
                    // Swaping if current card should come after next card
                    temp = hand[j];
                    hand[j] = hand[j + 1];
                    hand[j + 1] = temp;
                }
            }
            // If suits are different, swap if the current suit should come after the next suit
            else if (suitIndex1 > suitIndex2) {
                temp = hand[j];
                hand[j] = hand[j + 1];
                hand[j + 1] = temp;
            }
        }
    }
}

Card CreateCard(char* suit, char* rank) {
    Card newCard;
    strncpy(newCard.suit, suit, MAXNAME);
    strncpy(newCard.rank, rank, MAXNAME);
    return newCard;
}

void printHand(Card* hand, int size) {
    for (int i = 0; i < size; i++) {
        //printf("%s of %s\n", hand[i].rank, hand[i].suit);
        printCard(hand[i]);
    }
}

void printCard(Card c) {
    printf("%s of %s.  ", getRank(c), getSuit(c));
}

Card dealTop(Card* deck) {
    Card take = deck[NUM_RANKS * NUM_SUITS - cardsTaken -1];
    cardsTaken++;
    return take;
}
