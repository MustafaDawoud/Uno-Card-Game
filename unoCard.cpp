#include "unoCard.h"

unoCard::unoCard(Color color, Rank rank): m_color(color), m_rank(rank){}

// destructor
unoCard::~unoCard(){}

char unoCard::toCharColor()
{
	if (m_color == Red)   return 'R';
	else if (m_color == Yellow)    return 'Y';
	else if (m_color == Blue)   return 'B';
	else                       return 'G';
}

char unoCard::toCharRank()
{
	if (m_rank == R1)	return '1';
	else if (m_rank == R2)	return '2';
	else if (m_rank == R3)	return '3';
	else if (m_rank == R4)	return '4';
	else if (m_rank == R5)	return '5';
}
std::ostream& operator<<(std::ostream& os, const unoCard &c) {
	int color = c.getColor();
	int rank = c.getRank();
	switch (color) {
	case 1:
		os << "Red-";
		break;
	case 2:
		os << "Yellow-";
		break;
	case 3:
		os << "Blue-";
		break;
	default:
		os << "Green-";
	}
	os << rank;
	return os;
}