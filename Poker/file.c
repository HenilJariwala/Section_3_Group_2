#define _CRT_SECURE_NO_WARNINGS
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"

bool file() // For testing
{
	FILE* file = fopen("test.txt", "w+");
	if (file != NULL)
	{
		fprintf(file, "Username: Ryan \nEarnings: $100 \nTotal Hands Won: 4\nTotal Hands Lost: 8\nResets: 1 \nWins: 3 \nLosses: 1 \nWin/Lose Ratio: 3:1");
		//fprintf(file, "Username: %s, Earnings: %f, Total Hands Won: %d, Total Hands Lost: %d, Resets: %d, Wins: %d, Losses: %d, Win/Lose Ratio: %d:%d", username, earnings, handsWon, handsLost, resets, wins, losses, wins, losses);
		fclose(file);
		return true;
	}
	else
		return false;

}

bool saveGame(char characterFirstName[MAX_NAME], char characterLastName[MAX_NAME], float characterEarnings, int characterWins, int characterLosses)
{
	FILE* game = fopen("game.txt", "w+");
	if (game != NULL) //if game does exist
	{
		fprintf(game, "Player First Name: %s\n", characterFirstName);
		fprintf(game, "Player First Name: %s\n", characterLastName);
		fprintf(game, "Earnings: %f\n", characterEarnings);
		fprintf(game, "Wins: %d\n", characterWins);
		fprintf(game, "Losses: %d\n", characterLosses);
		fclose(game);
		return true;
	}
	else
		return false;
}

bool loadGame(char fileName[MAX_NAME])
{
	FILE* game = fopen(fileName, "r");
	char fileContent[100];
	if (game != NULL) //if game does exist
	{
		while (fgets(fileContent, 100, game)) // reads every line of the file
		{
			printf("%s", fileContent); // print file content
		}
		fclose(game);
		return true;
	}
	else
		return false;
}

bool deleteGame(char fileName[MAX_NAME])
{

	if (remove(fileName) == 0)
	{
		printf("File deleted");
		return true;
	}
	else
	{
		printf("File couldn't be deleted");
		return false;
	}
}

