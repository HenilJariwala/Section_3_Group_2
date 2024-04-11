#define _CRT_SECURE_NO_WARNINGS
#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"

bool file()
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

bool saveGame(char characterName[MAX_NAME], float characterEarnings, int characterWins, int characterLosses)
{
	FILE* game = fopen("game.txt", "w+");
	if (game != NULL) //if game does exist
	{
		fprintf(game, "Player Name: %s\n", characterName);
		fprintf(game, "Earnings: %f\n", characterEarnings);
		fprintf(game, "Wins: %d\n", characterWins);
		fprintf(game, "Losses: %d\n", characterLosses);
		fclose(game);
		return true;
	}
	else
		return false;
}

bool loadGame()
{
	FILE* game = fopen("game.txt", "r");
	char fileContent[100];
	if (game != NULL) //if game does exist
	{
		while (fgets(fileContent, 100, game)) // reads every line of the file
		{
			printf("%s", fileContent); // print file content
			return true;
		}
		fclose(game);
	}
	else
		return false;
}

bool deleteGame(char fileName[MAX_NAME])
{
	printf("Enter the name of the file you want to delete: ");
	scanf_s("%s", &fileName);
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

