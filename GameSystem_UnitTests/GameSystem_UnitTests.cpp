#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Poker/poker.h"
#include "../Poker/card.h"
#include "../Poker/player.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameSystemUnitTests
{
	TEST_CLASS(GameSystemUnitTests)
	{
	public:
		
		TEST_METHOD(TC0014)
		{
			Card test = CreateCard("Diamonds", "5");
			int expected = 5;
			int actual = ValueRank(test.rank);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TC0014_v2)
		{
			Card test = CreateCard("Diamonds", "10");
			int expected = 10;
			int actual = ValueRank(test.rank);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TC0014_v3)
		{
			Card test = CreateCard("Diamonds", "Queen");
			int expected = 12;
			int actual = ValueRank(test.rank);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TC0015)
		{
			Card test1 = CreateCard("Diamonds", "5");
			Card test2 = CreateCard("Diamonds", "6");
			Card test3 = CreateCard("Diamonds", "7");
			Card test4 = CreateCard("Diamonds", "8");
			Card test5 = CreateCard("Diamonds", "9");
			Card testHand[5];
			testHand[0] = test1;
			testHand[1] = test2;
			testHand[2] = test3;
			testHand[3] = test4;
			testHand[4] = test5;
			int expected = 80;
			int actual = ValueHand(testHand, 5);
			
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TC0016)
		{
			Player test = CreatePlayer("Test", "Guy");
			int before = test.Money;
			
			test.Money -= 50;
			int after = test.Money;
			// This shouldnt equal the same
			Assert::AreNotEqual(before, after);
		}
		TEST_METHOD(TC0017)
		{
			// testing the bot with a good hand 
			Card test1 = CreateCard("Diamonds", "5");
			Card test2 = CreateCard("Diamonds", "6");
			Card test3 = CreateCard("Diamonds", "7");
			Card test4 = CreateCard("Diamonds", "8");
			Card test5 = CreateCard("Diamonds", "9");
			Card testHand[5];
			testHand[0] = test1;
			testHand[1] = test2;
			testHand[2] = test3;
			testHand[3] = test4;
			testHand[4] = test5;
			int expected = 5;
			int actual = ValueHand(testHand, 5);
			int correct = 0;
			if (actual >= 60) {
				correct = 5;
			}
			else {
				correct = 1;
			}

			Assert::AreEqual(expected, correct);
		}
	};
}
