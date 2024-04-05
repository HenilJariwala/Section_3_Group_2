
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"

int main() {
    // Implement your main logic here
    printf("Welcome to the Poker Game!\n");

    // Example usage of functions from different modules
    Card* deck = createDeck();
    shuffleDeck(deck);

    Card playerHand[CARDS_IN_HAND];
    Card computerHand[CARDS_IN_HAND];
    dealCards(deck, playerHand, computerHand);

   // sortHand(playerHand, CARDS_IN_HAND);
    //sortHand(computerHand, CARDS_IN_HAND);

    // Example usage of game system functions
    Player player = CreatePlayer("Ryan", "Witley");
    StartGame(player);

    // Example usage of file I/O functions
    if (file()) {
        printf("File operation successful!\n");
    }
    else {
        printf("File operation failed!\n");
    }

    return 0;
}