#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
    #include "../Poker/card.h"
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

            // Check if the deck is not NULL
            Assert::IsNotNull(deck);

            // Check if the deck contains the correct number of cards
            long totalCardsExpected = static_cast<long>(NUM_RANKS) * NUM_SUITS;
            long totalCardActual = 0;
            for (int i = 0; i < NUM_SUITS * NUM_RANKS; ++i) {
                if (deck[i].suit != nullptr && deck[i].rank != nullptr) {
                    totalCardActual++;
                }
            }

            Assert::AreEqual(totalCardActual, totalCardsExpected);
            // Define arrays with all possible suits and ranks
            char* suits[NUM_SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
            char* ranks[NUM_RANKS] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

            // Check if each card in the deck has a valid suit and rank
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

            // Create an ordered deck
            Card* orderedDeck = createDeck();
            // Create a copy of the ordered deck
            Card* originalDeck = (Card*)malloc(totalCards* sizeof(Card));
            memcpy(originalDeck, orderedDeck, totalCards * sizeof(Card));

            // Shuffle the deck
            shuffleDeck(orderedDeck);

            // Check if the deck is not NULL
            Assert::IsNotNull(orderedDeck);

            // Check if the shuffled deck has the same number of cards as the original deck
            Assert::AreNotEqual(memcmp(originalDeck, orderedDeck, totalCards * sizeof(Card)), 0);

            // Free the memory allocated for the decks
            free(originalDeck);
            free(orderedDeck);
        }

        TEST_METHOD(UT003_DealCardsTest)
        {
           
            const int totalCards = NUM_SUITS * NUM_RANKS;
           
            // Create a deck
            Card* deck = createDeck();

            // Create player and computer hands
            Card* playerHand = (Card*)malloc(CARDS_IN_HAND * sizeof(Card));
            Card* computerHand = (Card*)malloc(CARDS_IN_HAND * sizeof(Card));

            // Deal cards
            dealCards(deck, playerHand, computerHand);

            // Check if the player hand is not NULL
            Assert::IsNotNull(playerHand);

            // Check if the computer hand is not NULL
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

            // Check if the player hand has the correct number of cards
            Assert::AreEqual(CARDS_IN_HAND, playerCardsCount);

            // Check if the computer hand has the correct number of cards
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

            // Make a copy of the unsorted hand for comparison
            Card originalHand1[CARDS_IN_HAND];
            memcpy(originalHand1, unsortedHand1, CARDS_IN_HAND * sizeof(Card));

            // Sort the hand
            sortHand(unsortedHand1, CARDS_IN_HAND);

            // Check if the hand is not NULL
            Assert::IsNotNull(unsortedHand1);

            // Compare each card in the sorted hand with the expected sorted hand
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

            // Make a copy of the unsorted hand for comparison
            Card originalHand2[CARDS_IN_HAND];
            memcpy(originalHand2, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sort the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Check if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Compare each card in the sorted hand with the expected sorted hand
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
                {"Spades", "Queen"},
                {"Spades", "Ace"}
            };

            // Make a copy of the unsorted hand for comparison
            Card originalHand2[CARDS_IN_HAND];
            memcpy(originalHand2, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sort the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Check if the hand is not NULL
            Assert::IsNotNull(unsortedHand);

            // Compare each card in the sorted hand with the expected sorted hand
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

            // Make a copy of the unsorted hand for comparison
            Card originalHand4[CARDS_IN_HAND];
            memcpy(originalHand4, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sort the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Check if the hand is not NULL
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

            // Make a copy of the unsorted hand for comparison
            Card originalHand4[CARDS_IN_HAND];
            memcpy(originalHand4, unsortedHand, CARDS_IN_HAND * sizeof(Card));

            // Sort the hand
            sortHand(unsortedHand, CARDS_IN_HAND);

            // Check if the hand is not NULL
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

            // Create a card using the CreateCard function
            Card testCard = CreateCard(testSuit, testRank);

            // Check if the created card's suit and rank match the expected values
            Assert::AreEqual(testSuit, testCard.suit);
            Assert::AreEqual(testRank, testCard.rank);
        }

	};
}
