
#include "card.h"
#include "file.h"

int main() {
    // Creating the deck
    Card* deck = createDeck();

   /* 
   Printing the whole deck
   for (int i = 0;i < NUM_SUITS * NUM_RANKS;i++) {
        printf("%s \t %s \n", deck[i].suit, deck[i].rank);
    }*/


    //Shuffling the deck
    shuffleDeck(deck);


    /*
    Printing the whole deck after shuffling 
    printf("\nAfter Shuffling\n");
    for (int i = 0;i < NUM_SUITS*NUM_RANKS;i++) {       
            printf("%s,%s \n", deck[i].suit, deck[i].rank);
    }*/

    //Testing for File I/O
    file();

    
}