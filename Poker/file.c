#include "card.h"
#include "poker.h"
#include "player.h"
#include "file.h"

bool saveGame(char playerName[20]) {
    FILE* game = fopen("game.txt", "w+");
    if (game != NULL) //if game doesn't exist
    {
        fprintf(game, "Player Name: %s", playerName);
        fclose(game);
        return true;
    }
    else
        return false;
}

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

