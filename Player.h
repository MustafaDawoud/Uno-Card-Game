#pragma once
#include <iostream>
#include <time.h>
#include <memory>
#include "string.h"
#include "OrderedList.h"
#include "unoCard.h"
#include "Bag.h"
#include "List.h"
#include "Queue.h"
#include "Stack.h"

class Player {
private:
	OrderedList<std::shared_ptr<unoCard>, IsLessDeref> hand;
	unsigned int m_hand;
	std::string name;
public:
	Player();
	~Player();
	void setName(std::string n);
	void setHand(std::shared_ptr<unoCard> T);
	unsigned int getNumOfCardsInHand() const;
	std::shared_ptr<unoCard> getCardinHand(unsigned int j) const;
	std::shared_ptr<unoCard> Player::removeCard(unsigned int j);
	void addToHand(std::shared_ptr<unoCard>);
	std::string getName() const;
	int handComparison(std::shared_ptr<unoCard> G);
};