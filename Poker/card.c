
#include "card.h"

Card* createDeck() {

    //Assigning dynamic memory to store the deck of cards
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
            deck[index].suit = suits[suit];
            deck[index].rank = ranks[rank];
            index++;
        }
    } 

    return deck;
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
