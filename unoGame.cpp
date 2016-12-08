#include "unoGame.h"

unoGame::unoGame(unsigned int gameSize, unsigned int n) {
	//Welcoming the user to the game
	std::cout << "Welcome to Uno!" << std::endl;
	std::cout << "Start Game" << std::endl;
	m_container = new Player[n]; //Creating an array of the players
	m_players = n;
	std::string na;
	//Setting the user names
	for (unsigned int k = 0; k < n; k++) {
		std::cout << "Please enter Player " << k + 1 << "'s name: ";
		std::cin >> na;
		m_container[k].setName(na);
	}
	//Creating a bag of all the cards
	Bag<std::shared_ptr<unoCard>> bag(40);
	Color s[] = { Red,Blue,Green,Yellow };
	Rank d[] = { R1,R2,R3,R4,R5 };
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 10; j++) {
			bag.add(std::make_shared<unoCard>(s[i], d[j % 5]));
		}
	}
	//Adding the cards in the bag to the deck
	for (unsigned int i = 0; i < 40; i++) {
		deck.enqueue(bag.getOne());
	}
	//Setting the hand of all the players
	for (unsigned int k = 0; k < m_players; k++) {
		for (unsigned int j = 0; j < 7; j++) {
			m_container[k].setHand(deck.dequeue());
		}
	}
	//Adding the first card to the face up pile
	faceUpPile.push(deck.dequeue());
}

unoGame::~unoGame() {
	delete[] m_container;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Thank you for Playing" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
}

void unoGame::play() {
	//Printing out the card at the top of the face up pile
	std::cout << std::endl << "The card at the top is: " << *(faceUpPile.peek()) << std::endl << std::endl;
	unsigned int i = 0;
	while (1) {
		//Determing which player's turn 
		i = i % (m_players);
		//printing which player's turn it is
		std::cout << "It is Player " << i + 1 << ": " << m_container[i].getName() << "'s turn." << std::endl;
		//Determing whether any of the card's in the player's hand is the same as the top card in the face up pile
		unsigned int l = m_container[i].handComparison(faceUpPile.peek());
		//if the card is found, put it down on the face up pile, otherwise, draw a card
		if (l != -1)
		{
			std::cout << "Player " << i + 1 << " found a match! They played " << *(m_container[i].getCardinHand(l)) << "." << std::endl;
			faceUpPile.push(m_container[i].removeCard(l));
		}
		else {
			m_container[i].addToHand(deck.dequeue());
			std::cout << "Player " << i + 1 << " draws a card." << std::endl;
		}
		//Repopulate the array
		if (deck.size() == 0) {
			std::shared_ptr<unoCard> temp = faceUpPile.pop();
			for (int i = 0; i < faceUpPile.size() - 1; i++)
				deck.enqueue(faceUpPile.pop());
			faceUpPile.push(temp);
			std::cout << "The deck has been repopulated." << std::endl;
		}
		//Printing out uno if a user has 1 card left 
		if (m_container[i].getNumOfCardsInHand() == (unsigned int)1)
			std::cout << "Player " << i + 1 << ": " << m_container[i].getName() << " yells UNO!" << std::endl;
		//if a player has no cards left in their hand, priting out that they've won
		if (m_container[i].getNumOfCardsInHand() == (unsigned int)0) {
			std::cout << "Player " << i + 1 << ": " << m_container[i].getName() << " has crushed their enemies in UNO (not even close)!" << std::endl;
			break;
		}
		i++;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
	}
}
