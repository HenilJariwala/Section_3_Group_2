#pragma once
#pragma once
#include "Card.h"
#include "player.h"
#include <stdbool.h>

int ValueCard(Card* hand);

int ValueRank(char*);

int ValueHand(Card* hand, int num);

void StartGame(Player);

bool isPair(Card* hand, int size);

bool isTriple(Card* hand, int size);

bool isDoublePair(Card* hand, int size);

bool isFourKind(Card* hand, int size);

bool isStraight(Card* hand, int size);

bool isFlush(Card* hand, int size);

bool isStraightFlush(Card* hand, int size);

bool isRoyalFlush(Card* hand, int size);

bool isFullHouse(Card* hand, int size);