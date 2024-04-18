#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
#include "../Poker/card.h"
#include "../Poker/poker.h"
#include "../Poker/file.h"
#include "../Poker/player.h"
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCardSystem
{
    TEST_CLASS(UnitTestCharacterCreationandSavingSystem)
    {
    public:

		TEST_METHOD(TC010) // Testing file()
		{
			bool expected = true;
			bool actual = file();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TC011) //Testing values with data for CreatePlayer() function
		{
			Player r;
			char* fName = "Ryan";
			char* lName = "Massey";
			double money = 500.00;
			int wins = 0;
			int losses = 0;
			strncpy(r.fName, fName, MAXNAME);
			strncpy(r.LName, lName, MAXNAME);
			r.Money = 500.00;
			r.Wins = 0;
			r.Losses = 0;

			Assert::AreEqual(r.fName, "Ryan");
			Assert::AreEqual(r.LName, "Massey");
			Assert::AreEqual(r.Money, money);
			Assert::AreEqual(r.Wins, wins);
			Assert::AreEqual(r.Losses, losses);
		}

		TEST_METHOD(TC012) // Testing loadGame()
		{
			bool expected = true;
			bool actual = loadGame();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TC013) // Testing deleteGame()
		{
			file();
			char fileName[20] = "test.txt";
			bool expected = true;
			bool actual = deleteGame(fileName);
			Assert::AreEqual(expected, actual);
		}
    };
}