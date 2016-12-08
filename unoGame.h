#pragma once
#include <iostream>
#include <time.h>
#include <memory>
#include <string>
#include "OrderedList.h"
#include "unoCard.h"
#include "Bag.h"
#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include "Player.h"

class unoGame {
private:
	Queue<std::shared_ptr<unoCard>> deck;
	Stack<std::shared_ptr<unoCard>> faceUpPile;
	Player * m_container;
	unsigned int m_players;
public:
	unoGame(unsigned int gameSize = 40, unsigned int n = 3);
	~unoGame();
	void play();
};

