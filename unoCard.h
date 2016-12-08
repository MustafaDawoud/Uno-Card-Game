#pragma once
#include <iostream>

// User defined Suit and Denomination types (user-defined integers) 
enum Color { Red = 1, Yellow = 2, Blue = 3, Green = 4 };
enum Rank { R1 = 1, R2 = 2, R3 = 3, R4 = 4, R5 = 5};

class unoCard 
{
public:
	unoCard(Color colour = Red, Rank rank = R1); // constructor with some default values
	~unoCard(); // destructor
	inline Color getColor(void) const { return m_color; }
	inline Rank getRank(void) const { return m_rank; }
	char toCharColor(void); // returns a char that "describes" card's suit
	char toCharRank(void); // returns a char that "describes" card's denomination
	friend std::ostream& operator<<(std::ostream& os, const unoCard &c);

private:
	Color m_color; // private storage of suit
	Rank m_rank; // private storage of denomination
};

// global operator functions comparing denominations of two cards
// The cards a and b are passed by reference

inline bool operator<(const unoCard& a, const unoCard& b) {
	if (a.getColor() == b.getColor()) return (a.getRank()<b.getRank());
	else                            return (a.getColor()<b.getColor());
}

inline bool operator>(const unoCard& a, const unoCard& b) {
	if (a.getColor() == b.getColor()) return (a.getRank()>b.getRank());
	else                            
		return (a.getColor()>b.getColor());
}

// checks equality of suits and denominations for two cards
inline bool operator==(unoCard& a, unoCard& b) { 
	return (a.getRank() == b.getRank() && a.getColor() == b.getColor()); 
}
