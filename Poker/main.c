
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


    // Example usage of functions from different modules


    //sortHand(playerHand, CARDS_IN_HAND);
    //sortHand(computerHand, CARDS_IN_HAND);
   
    return 0;
}