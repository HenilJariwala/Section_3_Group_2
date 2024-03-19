
#include "card.h"

int main() {
    // Creating the deck
    Card* deck = createDeck();

   /* 
   Printing the whole */
   for (int i = 0;i < NUM_SUITS * NUM_RANKS;i++) {
        printf("%s \t %s \n", deck[i].suit, deck[i].rank);
    }


    //Shuffling the deck
    shuffleDeck(deck);


    /*
    Printing the whole deck after shuffling */
    printf("\nAfter Shuffling\n");
    for (int i = 0;i < NUM_SUITS*NUM_RANKS;i++) {       
            printf("%s,%s \n", deck[i].suit, deck[i].rank);
    }

    // Distribute cards to players (for demonstration purposes, we'll deal to one player)
    Card playerHand[2];
    Card computerHand[2];
    dealCards(deck, playerHand, computerHand);

   

    // Sorting player's and computer's hands
    sortHand(playerHand, CARDS_IN_HAND);
    sortHand(computerHand, CARDS_IN_HAND);

    // Displaying the player's hand
    printf("Player's Hand:\n");
    for (int i = 0; i < CARDS_IN_HAND; ++i) {
        printf("%s of %s\n", playerHand[i].rank, playerHand[i].suit);
    }

    // Displaying the computer's hand
    printf("\nComputer's Hand:\n");
    for (int i = 0; i < CARDS_IN_HAND; ++i) {
        printf("%s of %s\n", computerHand[i].rank, computerHand[i].suit);
    }


    // Free dynamically allocated memory
    free(deck);
    
}