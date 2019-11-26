#include "Link.h"
#include <string>

using namespace std;



Link::Link(string identity, int strength, int x, int y, char name, bool is_boost,
	bool is_alive, bool is_revealed) :
	identity{ identity }, strength{ strength }, x{ x }, y{ y }, name{ name },
	is_boost{ is_boost }, is_alive{ is_alive }, is_revealed{ is_revealed } {}


// -1: invalid move
// 0: valid move
// 1: to the server oprt
// 2: off the opponent's edge

int Link::move(string dir, bool if_p1) { // handle link boost
	if (dir == "up") {
		if (is_boost) { // if the ability link boost is applied
			
			if (if_p1) { // if it is a p1 link
				if (y <= 1) { // if it is at pos y <= 1
					cout << "Invalid move: Out of edge!" << endl;
					return -1;
				}
				else if ((x == 3 && y == 2) || (x == 4 && y == 2)) { // goes to my server port
					cout << "Invalid move: Wrong Destination!" << endl;
					return -1;
				}
				else { // if it is at pos y > 1
					y -= 2;
					return 0;
				}
			}
			else { // if it is a p2 link
				if ((x == 3 && y == 2) || (x == 4 && y == 2)) { // goes to the opponent's server port
					y -= 2;
					is_alive = 0;
					return 1;
				}
				else if (y <= 1) { // goes off the opponent's edge
					y -= 2;
					is_alive = 0;
					return 2;
				}
				else { // if it is at pos y > 1
					y -= 2;
					return 0;
				}
			}
		}
		else { // if the ability link boost is not applied
			if (if_p1) { // if it is a p1 link
				if (y == 0) { // if it is at pos y == 0
					cout << "Invalid move: Out of edge!" << endl;
					return -1;
				}
				else if ((x == 3 && y == 1) || (x == 4 && y == 1)) { // goes to my server port
					cout << "Invalid move: Wrong Destination!" << endl;
					return -1;
				}
				else { // if it is at pos y != 0
					y--;
					return 0;
				}
			}
			else { // if it is a p2 link
				if ((x == 3 && y == 1) || (x == 4 && y == 1)) { // goes to the opponent's server port
					y--;
					is_alive = 0;
					return 1;
				}
				else if (y == 0) { // at the edge
					y--;
					is_alive = 0;
					return 2;
				}
				else { // not at the edge
					y--;
					return 0;
				}
			}
		}
	}
	else if (dir == "down") {

		if (is_boost) { // if the ability link boost is applied
			if (if_p1) { // if it is a p1 link
				if ((x == 3 && y == 5) || (x == 4 && y == 5)) { // goes to opponent's server port
					y += 2;
					is_alive = 0;
					return 1;
				}
				else if (y >= 6) { // if at the pos y >= 6
					y += 2;
					is_alive = 0;
					return 2;
				}
				else {
					y += 2;
					return 0;
				}

			}
			else { // if it is a p2 link
				if ((x == 3 && y == 5) || (x == 4 && y == 5)) { // goes to my server port
					cout << "Invalid move: Wrong Destination!" << endl;
					return -1;
				}
				else if (y >= 6) { // if at the pos y >= 6
					cout << "Invalid move: Out of edge!" << endl;
					return -1;
				}
				else {
					y += 2;
					return 0;
				}

			}

		}
		else { // if the abolity link boost is not applied
			if (if_p1) { // if it is a p1 link
				if ((x == 3 && y == 6) || (x == 4 && y == 6)) { // goes to the opponent's server port
					y++;
					is_alive = 0;
					return 1;
				}
				else if (y == 7) { // if at the pos y = 7
					y++;
					is_alive = 0;
					return 2;
				}
				else {
					y++;
					return 0;
				}
			}
			else { // if it is a p2 link
				if ((x == 3 && y == 6) || (x == 4 && y == 6)) { // goes to my server port
					cout << "Invalid move: Wrong Destination!" << endl;
					return -1;
				}
				else if (y == 7) { // if at the pos y = 7
					cout << "Invalid move: Out of edge!" << endl;
					return -1;
				}
				else { // if at the pos y != 7
					y++;
					return 0;
				}
			}

		}
		
	
		
	}
	else if (dir == "left") {
		
	if (is_boost) { // if link boost is applied
		if (x <= 1) { // if at the pos x <= 1
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		else {
			x -= 2;
			return 0;
		}
	}
	else { // if link boost is not applied
		if (x == 0) {
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		else {
			x--;
			return 0;
		}

	}
	}
	else if (dir == "right") {
	if (is_boost) { // if link boost is applied
		if (x >= 6) { // if at the pos x >= 6
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		else {
			x += 2;
			return 0;
		}
	}
	else { // if link boost is not applied
		if (x == 7) {
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		else {
			x++;
			return 0;
		}

	}
	}
	
}

bool Link::battle(Link& rhs) {
	if (strength >= rhs.strength) {
		rhs.x = 10;
		rhs.y = 10;
		rhs.is_alive = false;
		return true;
		// probably need to add something here
	}
	else {
		x = 10;
		y = 10;
		is_alive = false;
		return false;
		// probably need to add something here
	}
}
