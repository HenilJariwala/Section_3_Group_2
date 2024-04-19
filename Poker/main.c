#define _CRT_SECURE_NO_WARNINGS
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"
#include "menu.h"

int main() {

    
        // Main menu
        Menu();
        int option;
        char firstName[MAXNAME];
        char lastName[MAXNAME];
        char fileName[MAXNAME];

        printf("select an option: ");

        scanf_s("%d", &option);

        switch (option)
        {
        case 1: // Create a new game of poker

            printf("Enter a first name: ");
            scanf_s("%s", firstName, MAXNAME);

            printf("\nEnter a last name: ");
            scanf_s("%s", lastName, MAXNAME);

            // Example usage of game system functions
            Player player = CreatePlayer(firstName, lastName);

            srand(time(NULL));
            if (saveGame(player.fName, player.LName, player.Money, player.Wins, player.Losses)) {
                printf("File operation successful!\n");
            }
            else {
                printf("File operation failed!\n");
            }

            StartGame(player);

            return 0;
            break;

        case 2: // Load a game of poker from a file
            printf("\nEnter the name of the file you wish to load\nFor example: yourFileName.txt\n:");
            scanf_s("%s", fileName, MAXNAME);
            loadGame(fileName);
            break;

        case 3: // Delete an existing game of poker
            printf("\nEnter the name of the file you wish to delete\nFor example: yourFileName.txt\n:");
            scanf_s("%s", fileName, MAXNAME);
            deleteGame(fileName);
            break;

        case 4: // Learn how to play poker
            Tutorial();
            break;

        case 5: //Quit game
            printf("Thank you for playing!");
            break;
        }


    // Implement your main logic here
    printf("Welcome to the Poker Game!\n");
    while (choice < 1) {
        printf("What would you like to do? 1: Create character. 2: Load Character, 3: Save Character, 4: Continue,  >4: Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            printf("Enter first and last name\n");
            scanf("%s", &firstName);
            scanf("%s", &lastName);
            Player player = CreatePlayer(firstName, lastName);
            choice = 0;
            StartGame(&player);
            break;
        case 2: 
            choice = 0;
            loadGame();
            break;
        case 3: 
            if (player.Money <-1000) {
                printf("No player loaded\n");
            }
            else {
                saveGame(getFirstName(player), getMoney(player), getWins(player), getLosses(player));
            }
                  choice = 0;
                 break;
        case 4:
              if (player.Losses <= 0 && player.Wins <= 0) {
                printf("No players loaded\n");
                choice = 0;
                break;
                }
            else if (player.Money < 0) {
                printf("Bankrupt! Game over! Please Create a new character\n");
                choice = 0;
                break;
            }
            else {
                StartGame(&player);
            }
        default:
            break;

       }

    // Example usage of functions from different modules


    //sortHand(playerHand, CARDS_IN_HAND);
    //sortHand(computerHand, CARDS_IN_HAND);
   
    return 0;
}