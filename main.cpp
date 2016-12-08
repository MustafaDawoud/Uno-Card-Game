#include <iostream>

#include <string>
#include "OrderedList.h"
#include "unoCard.h"
#include "unoGame.h"
#include "Bag.h"
#include "List.h"
#include <ctime>

using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	unoGame game(40, 3);
	game.play();
	return 0;
}
