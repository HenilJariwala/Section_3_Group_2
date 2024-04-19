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
	TEST_CLASS(UnitTestCardSystem)
	{
	public:
		
		TEST_METHOD(UT001_CardDeckTest)
		{
            Card* deck = createDeck();

            // Checking if the deck is not NULL
            Assert::IsNotNull(deck);

            // Checking if the deck contains the correct number of cards
            long totalCardsExpected = static_cast<long>(NUM_RANKS) * NUM_SUITS;
            long totalCardActual = 0;
            for (int i = 0; i < NUM_SUITS * NUM_RANKS; ++i) {
                if (deck[i].suit != nullptr && deck[i].rank != nullptr) {
                    totalCardActual++;
                }
            }

            Assert::AreEqual(totalCardActual, totalCardsExpected);
            // Defining arrays with all possible suits and ranks
            char* suits[NUM_SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
            char* ranks[NUM_RANKS] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

            // Checking if each card in the deck has a valid suit and rank
            int index = 0;
            for (int suit = 0; suit < NUM_SUITS; suit++) {
                for (int rank = 0; rank < NUM_RANKS; rank++) {
                    Assert::AreEqual(deck[index].suit, suits[suit]);
                    Assert::AreEqual(deck[index].rank, ranks[rank]);
                    index++;
                }
            }

            // Free the memory allocated for the deck
            free(deck);
        }

        TEST_METHOD(UT002_ShuffleDeckTest)
        {
            
            int totalCards = NUM_SUITS * NUM_RANKS;

            // Creating an ordered deck
            Card* orderedDeck = createDeck();
            // Creating a copy of the ordered deck
            Card* originalDeck = (Card*)malloc(totalCards* sizeof(Card));
            memcpy(originalDeck, orderedDeck, totalCards * sizeof(Card));

            // Shuffling the deck
            shuffleDeck(orderedDeck);

            // Checking if the deck is not NULL
            Assert::IsNotNull(orderedDeck);

            // Checking if the shuffled deck has the same number of cards as the original deck
            Assert::AreNotEqual(memcmp(originalDeck, orderedDeck, totalCards * sizeof(Card)), 0);

            // Free the memory allocated for the decks
            free(originalDeck);
            free(orderedDeck);
        }

        TEST_METHOD(UT003_DealCardsTest)
        {
           
            const int totalCards = NUM_SUITS * NUM_RANKS;
           
            // Creating a deck
            Card* deck = createDeck();

            // Creating player and computer hands
            Card* playerHand = (Card*)malloc(CARDS_IN_HAND * sizeof(Card));
            Card* computerHand = (Card*)malloc(CARDS_IN_HAND * sizeof(Card));

            // Deal cards
            dealCards(deck, playerHand, computerHand);

            // Checking if the player hand is not NULL
            Assert::IsNotNull(playerHand);

            // Checking if the computer hand is not NULL
            Assert::IsNotNull(computerHand);

            // Count the number of cards in the player hand
            int playerCardsCount = 0;
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                if (playerHand[i].suit != nullptr && playerHand[i].rank != nullptr) {
                    playerCardsCount++;
                }
            }

            // Count the number of cards in the computer hand
            int computerCardsCount = 0;
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                if (computerHand[i].suit != nullptr && computerHand[i].rank != nullptr) {
                    computerCardsCount++;
                }
            }

            // Checking if the player hand has the correct number of cards
            Assert::AreEqual(CARDS_IN_HAND, playerCardsCount);

            // Checking if the computer hand has the correct number of cards
            Assert::AreEqual(CARDS_IN_HAND, computerCardsCount);

            // Free the memory allocated for the decks
            free(deck);
            free(playerHand);
            free(computerHand);
        }

        TEST_METHOD(UT004_SortHandTest)
        {// Unsorted hand 1
            Card unsortedHand1[CARDS_IN_HAND] = {
                {"Diamonds", "9"},
                {"Spades", "Ace"}
            };

            Card expectedSortedHand1[CARDS_IN_HAND] = {
                {"Spades", "Ace"},
                {"Diamonds", "9"}
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand1[CARDS_IN_HAND];
            memcpy(originalHand1, unsortedHand1, CARDS_IN_HAND * sizeof(Card));

            // Sorting the hand
            sortHand(unsortedHand1, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand1);

            // Comparing each card in the sorted hand with the expected sorted hand
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreEqual(expectedSortedHand1[i].suit, unsortedHand1[i].suit);
                Assert::AreEqual(expectedSortedHand1[i].rank, unsortedHand1[i].rank);
            }
        }

        TEST_METHOD(UT005_SortHandTest)
        {
            // Unsorted hand 
            Card unsortedHand[CARDS_IN_HAND] = {
                {"Clubs", "King"},
                {"Hearts", "10"}
            };

            Card expectedSortedHand[CARDS_IN_HAND] = {
                {"Hearts", "10"},
                {"Clubs", "King"}
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand2[CARDS_IN_HAND];
            memcpy(originalHand2, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sorting the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Comparing each card in the sorted hand with the expected sorted hand
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreEqual(expectedSortedHand[i].suit, unsortedHand[i].suit);
                Assert::AreEqual(expectedSortedHand[i].rank, unsortedHand[i].rank);
            }
        }

        TEST_METHOD(UT006_SortHandTest)
        {
            // Unsorted hand 
            Card unsortedHand[CARDS_IN_HAND] = {
                {"Spades", "Queen"},
                {"Spades", "Ace"}
            };

            Card expectedSortedHand[CARDS_IN_HAND] = {
                {"Spades", "Ace"},
                {"Spades", "Queen"}
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand2[CARDS_IN_HAND];
            memcpy(originalHand2, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Checking the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Comparing each card in the sorted hand with the expected sorted hand
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreEqual(expectedSortedHand[i].suit, unsortedHand[i].suit);
                Assert::AreNotEqual(expectedSortedHand[i].rank, unsortedHand[i].rank);
            }
        }

        TEST_METHOD(UT007_SortHandTest)
        {
             // Unsorted hand 
            Card unsortedHand[CARDS_IN_HAND] = {
                {"Hearts", "Ace"},
                {"Diamonds", "King"}
            };

            Card expectedSortedHand[CARDS_IN_HAND] = {
                {"Diamonds", "King"},
                {"Hearts", "Ace"}
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand4[CARDS_IN_HAND];
            memcpy(originalHand4, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sorting the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Ensure the hand is not sorted in the same order as the expected sorted hand
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreNotEqual(expectedSortedHand[i].suit, unsortedHand[i].suit);
                Assert::AreNotEqual(expectedSortedHand[i].rank, unsortedHand[i].rank);
            }
        }
        
        TEST_METHOD(UT008_SortHandTest)
        {
            // Unsorted hand 
            Card unsortedHand[CARDS_IN_HAND] = {
                {"Hearts", "Jack"},
                {"Clubs", "10"}             
            };

            Card expectedSortedHand[CARDS_IN_HAND] = {
                {"Clubs", "10"},
                 {"Hearts", "Jack"}
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand4[CARDS_IN_HAND];
            memcpy(originalHand4, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sorting the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Ensure the hand is not sorted in the same order as the expected sorted hand
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreNotEqual(expectedSortedHand[i].suit, unsortedHand[i].suit);
                Assert::AreNotEqual(expectedSortedHand[i].rank, unsortedHand[i].rank);
            }
        }

        TEST_METHOD(UT009_CreateCardTest)
        {
            // Define suit and rank for the test card
            char testSuit[] = "Hearts";
            char testRank[] = "Ace";

            // Creating a card using the CreateCard function
            Card testCard = CreateCard(testSuit, testRank);

            // Checking if the created card's suit and rank match the expected values
            Assert::AreEqual(testSuit, testCard.suit);
            Assert::AreEqual(testRank, testCard.rank);
        }

        //Integration Testing 
        TEST_METHOD(TC001_SortHandBySameSuitAndDifferentNumber)
        {
            // Unsorted hand 
            Card unsortedHand[CARDS_IN_HAND] = {
                {"Spades", "7"},
                {"Spades", "King"}

            };

            Card expectedSortedHand[CARDS_IN_HAND] = {
                 {"Spades", "King"},
                 {"Spades", "7"}
                 
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand2[CARDS_IN_HAND];
            memcpy(originalHand2, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sorting the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Comparing each card in the sorted hand with the expected sorted hand
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreEqual(expectedSortedHand[i].suit, unsortedHand[i].suit);
                Assert::AreEqual(expectedSortedHand[i].rank, unsortedHand[i].rank);
            }
        }

        TEST_METHOD(TC002_SortHandByDifferentSuitAndSameNumber)
        {
            // Define the unsorted poker hand
            Card unsortedHand[CARDS_IN_HAND] = {
                {"Hearts", "Ace"},
                {"Spades", "8"}
            };

            // Define the expected sorted hand
            Card expectedSortedHand[CARDS_IN_HAND] = {
                {"Spades", "8"},
                {"Hearts", "Ace"}
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand[CARDS_IN_HAND];
            memcpy(originalHand, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sorting the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Ensure the hand is sorted correctly
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreEqual(expectedSortedHand[i].suit, unsortedHand[i].suit);
                Assert::AreEqual(expectedSortedHand[i].rank, unsortedHand[i].rank);
            }
        }

        TEST_METHOD(TC003_SortHandByDifferentSuitAndDifferentNumber)
        {
            // Define the unsorted poker hand
            Card unsortedHand[CARDS_IN_HAND] = {
                {"Clubs", "Queen"},
                {"Diamonds", "Jack"}
            };

            // Define the expected sorted hand
            Card expectedSortedHand[CARDS_IN_HAND] = {
                {"Diamonds", "Jack"},
                {"Clubs", "Queen"}
            };

            // Making a copy of the unsorted hand for comparison
            Card originalHand[CARDS_IN_HAND];
            memcpy(originalHand, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sorting the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Checking if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Ensuring the hand is sorted correctly
            for (int i = 0; i < CARDS_IN_HAND; ++i) {
                Assert::AreEqual(expectedSortedHand[i].suit, unsortedHand[i].suit);
                Assert::AreEqual(expectedSortedHand[i].rank, unsortedHand[i].rank);
            }
        }

        TEST_METHOD(TC004_TestGameIntegration)
        {
            
            Card* deck = createDeck();

            // Checking if the deck is not NULL
            Assert::IsNotNull(deck);

            
            Card hand[] = {
                {"Spades", "Ace"},
                {"Hearts", "2"}
            };

            // Calculating the value of the hand
            int handValue = ValueHand(hand, sizeof(hand) / sizeof(hand[0]));

            // Expected hand value based on poker rules (mocked for simplicity)
            int expectedHandValue = 14; // Assuming a specific value for testing purposes

            // Checking if the calculated hand value matches the expected value
            Assert::AreEqual(expectedHandValue, handValue);

            Card playerHand[CARDS_IN_HAND];
            Card computerHand[CARDS_IN_HAND];

            dealCards(deck, playerHand, computerHand);

            // Checking if the player and computer hands are not NULL
            Assert::IsNotNull(playerHand);
            Assert::IsNotNull(computerHand);

            
        }

        TEST_METHOD(TC005_GameIntegrationTest)
        {
            // Step 1: Input player data into the system
            char firstName[MAX_NAME] = "Player1";
            char lastName[MAX_NAME] = "Lastname";
            float earnings = 150.0f;
            int wins = 5;
            int losses = 3;
            bool expected = true;

            // Step 2: Trigger the output of player data
            bool result = saveGame(firstName, lastName, earnings, wins, losses);

            // Step 3: Verifying that player data is correctly outputted
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TC006_DealCardsTest)
        {
            // Step 1: Input a deck of cards into the system using the createDeck function
            Card* deck = createDeck();

            // Checking if the deck is not NULL
            Assert::IsNotNull(deck);

            // Step 2: Trigger the distribution of cards to players using the dealCards function
            Card playerHand[CARDS_IN_HAND];
            Card computerHand[CARDS_IN_HAND];

            dealCards(deck, playerHand, computerHand);

            // Checking if the player and computer hands are not NULL
            Assert::IsNotNull(playerHand);
            Assert::IsNotNull(computerHand);
        }

        TEST_METHOD(TC007_SaveGameTest)
        {
            // Step 1: Simulating game data with player statistics
            char playerName[MAX_NAME] = "Player1";
            char playerLastName[MAX_NAME] = "Lastname";
            float playerEarnings = 100.0f;
            int playerWins = 4;
            int playerLosses = 8;

            // Step 2: Invoking the "saveGame" function to save the game data
            bool saved = saveGame(playerName, playerLastName, playerEarnings, playerWins, playerLosses);

            // Step 3: Checking if the game data is saved successfully
            Assert::IsTrue(saved);

            // Step 4: Verifying that the saved file exists
            FILE* savedFile = fopen("game.txt", "r");
            Assert::IsNotNull(savedFile);
            fclose(savedFile);
        }

        TEST_METHOD(TC008_CreateDeckTest)
        {
            // Step 1: Invoking the "createDeck" function to create a deck of cards
            Card* deck = createDeck();

            // Step 2: Verifying that the deck is not null
            Assert::IsNotNull(deck);

            // Step 3: Verifying that the deck contains the correct number of cards
            const int expectedNumCards = NUM_RANKS * NUM_SUITS;
            int actualNumCards = 0;
            for (int i = 0; i < NUM_SUITS * NUM_RANKS; ++i) {
                if (deck[i].suit != nullptr && deck[i].rank != nullptr) {
                    actualNumCards++;
                }
            }
            Assert::AreEqual(expectedNumCards, actualNumCards);

            // Step 4: Verifying that each card in the deck has a valid suit and rank
            for (int i = 0; i < NUM_SUITS * NUM_RANKS; ++i) {
                Assert::IsNotNull(deck[i].suit);
                Assert::IsNotNull(deck[i].rank);
            }          

            delete[] deck;
        }

        TEST_METHOD(TC009_LoadGameTest)
        {
            // Step 1: Simulating a previously saved game with player statistics
            std::string savedGameData = "Player Name: Player1\nEarnings: 100.000000\nWins: 4\nLosses: 8\n";

            // Step 2: Save the simulated game data to a file
            FILE* game = fopen("game.txt", "w+");
            if (game != nullptr)
            {
                fprintf(game, savedGameData.c_str());
                fclose(game);
            }

            // Step 3: Invoking the "loadGame" function to load the saved game data
            bool result = loadGame("game.txt");

            // Step 4: Verifying that the player statistics are correctly loaded
            Assert::IsTrue(result); // Assert that the loading operation was successful
        }


	};
}
