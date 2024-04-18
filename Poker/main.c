#define _CRT_SECURE_NO_WARNINGS
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"

int main() {
    int choice = 0 ;
    char firstName[20];
    char lastName[20];
    srand(time(NULL));
    if (file()) {
        printf("File operation successful!\n");
    }
    else {
        printf("File operation failed!\n");
    }

    Player player;
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



        
    }

    // Example usage of file I/O functions
   

    return 0;
}