#include "Player.h"

Player::Player() {
	m_hand = 0;
}

Player::~Player() {}

void Player::setName(std::string n) {
	name = n;
}

void Player::setHand(std::shared_ptr<unoCard> T) {
	hand.insert(T);
	m_hand++;
}

unsigned int Player::getNumOfCardsInHand() const {
	return m_hand;
}

std::shared_ptr<unoCard> Player::getCardinHand(unsigned int j) const {
	return hand.retrieve(j);
}

std::shared_ptr<unoCard> Player::removeCard(unsigned int j) {
	m_hand--;
	return hand.remove(j);
}

void Player::addToHand(std::shared_ptr<unoCard> T) {
	hand.insert(T);
}

std::string Player::getName() const {
	return name;
}

int Player::handComparison(std::shared_ptr<unoCard> G) {
	//Comparing by card number then by card card colour 
	for (unsigned int j = 1; j <= m_hand; j++) {
		if (hand.retrieve(j)->getRank() == G->getRank()) {
			return j;
		}
	}
	for (unsigned int j = 1; j <= m_hand; j++) {
		if (hand.retrieve(j)->getColor() == G->getColor()) {
			return j;
		}
	}
	return -1;
}
