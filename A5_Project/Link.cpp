#include "Link.h"
#include <string>

using namespace std;



Link::Link(string identity, int strength, int x, int y, char name, int is_boost,
	bool is_alive, bool is_revealed) :
	identity{ identity }, strength{ strength }, x{ x }, y{ y }, name{ name },
	is_boost{ is_boost }, is_alive{ is_alive }, is_revealed{ is_revealed } {}

Link& Link::operator=(const Link& other) {
	identity = other.identity;
	strength = other.strength;
	x = other.x;
	y = other.y;
	name = name;
	is_boost = other.is_boost;
	is_alive = other.is_alive;
	is_revealed = other.is_revealed;
	return *this;
}


// -1: invalid move
// 0: valid move
// 1: to the server oprt
// 2: off the opponent's edge

int Link::move(string dir, bool if_p1) { // handle link boost
	int n = is_boost;
	if (dir == "up") {
		if (is_boost) { // if the ability link boost is applied
			
			if (if_p1) { // if it is a p1 link
				if (y <= n) { // if it is at pos y <= n
					cout << "Invalid move: Out of edge!" << endl;
					return -1;
				}
				else if ((x == 3 && y == n + 1) || (x == 4 && y == n + 1)) { // goes to my server port
					cout << "Invalid move: Wrong Destination!" << endl;
					return -1;
				}
				else { // if it is at pos y > n
					y -= n + 1;
					return 0;
				}
			}
			else { // if it is a p2 link
				if ((x == 3 && y == n + 1) || (x == 4 && y == n + 1)) { // goes to the opponent's server port
					x = 9;
					y = 9;
					is_revealed = 1;
					is_alive = 0;
					return 1;
				}
				else if (y <= n) { // goes off the opponent's edge
					x = 9;
					y = 9;
					is_revealed = 1;
					is_alive = 0;
					return 2;
				}
				else { // if it is at pos y > n
					y -= n + 1;
					
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
					x = 9;
					y = 9;
					is_revealed = 1;
					is_alive = 0;
					return 1;
				}
				else if (y == 0) { // at the edge
					x = 9;
					y = 9;
					is_revealed = 1;
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
				if ((x == 3 && y == (7 - n - 1)) || (x == 4 && y == (7 - n - 1))) { // goes to opponent's server port
					x = 9;
					y = 9;
					is_revealed = 1;
					is_alive = 0;
					return 1;
				}
				else if (y >= (7 - n)) { // if at the pos y >= 7 - n, goes off the edge
					x = 9;
					y = 9;
					is_revealed = 1;
					is_alive = 0;
					return 2;
				}
				else {
					y += n + 1;
					return 0;
				}

			}
			else { // if it is a p2 link
				if ((x == 3 && y == (7 - n - 1)) || (x == 4 && y == (7 - n - 1))) { // goes to my server port
					cout << "Invalid move: Wrong Destination!" << endl;
					return -1;
				}
				else if (y >= (7 - n)) { // if at the pos y >= 6
					cout << "Invalid move: Out of edge!" << endl;
					return -1;
				}
				else {
					y += n + 1;
					return 0;
				}

			}

		}
		else { // if the abolity link boost is not applied
			if (if_p1) { // if it is a p1 link
				if ((x == 3 && y == 6) || (x == 4 && y == 6)) { // goes to the opponent's server port
					x = 9;
					y = 9;
					is_revealed = 1;
					is_alive = 0;
					return 1;
				}
				else if (y == 7) { // if at the pos y = 7
					x = 9;
					y = 9;
					is_revealed = 1;
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
		if (x <= n) { // if at the pos x >= 7 - n
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		if (if_p1) { // if it is p1 turn
			if ((x == (3 + n + 1) && y == 0) || (x == (4 + n + 1) && y == 0)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == (3 + n + 1) && y == 7) || (x == (4 + n + 1) && y == 7)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x -= n + 1;
			}

		}
		else { // if it is p2 turn
			if ((x == (3 + n + 1) && y == 7) || (x == (4 + n + 1) && y == 7)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == (3 + n + 1) && y == 0) || (x == (4 + n + 1) && y == 0)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x -= n + 1;
			}
		}
	}
	else { // if link boost is not applied
		if (x <= 0) { // if at the pos x >= 7 - n
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		if (if_p1) { // if it is p1 turn
			if ((x == 4 && y == 0) || (x == 5 && y == 0)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == 4 && y == 7) || (x == 5 && y == 7)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x--;
			}

		}
		else { // if it is p2 turn
			if ((x == 4 && y == 7) || (x == 5 && y == 7)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == 4 && y == 0) || (x == 5 && y == 0)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x--;
			}
		}

	}
	}
	else if (dir == "right") {
	if (is_boost) { // if link boost is applied
		if (x >= (7 - n)) { // if at the pos x >= 7 - n
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		if (if_p1) { // if it is p1 turn
			if ((x == (3 - n - 1) && y == 0) || (x == (4 - n - 1) && y == 0)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == (3 - n - 1) && y == 7) || (x == (4 - n - 1) && y == 7)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x += n + 1;
			}

		}
		else { // if it is p2 turn
			if ((x == (3 - n - 1) && y == 7) || (x == (4 - n - 1) && y == 7)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == (3 - n - 1) && y == 0) || (x == (4 - n - 1) && y == 0)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x += n + 1;
			}
		}
	}
	else { // if link boost is not applied
		if (x >= 7) { // if at the pos x >= 7 - n
			cout << "Invalid move: Out of edge!" << endl;
			return -1;
		}
		if (if_p1) { // if it is p1 turn
			if ((x == 2 && y == 0) || (x == 3 && y == 0)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == 2 && y == 7) || (x == 3 && y == 7)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x++;
			}

		}
		else { // if it is p2 turn
			if ((x == 2 && y == 7) || (x == 3 && y == 7)) { // goes to my server port
				cout << "Invalid move: Wrong Destination!" << endl;
				return -1;
			}
			else if ((x == 2 && y == 0) || (x == 3 && y == 0)) { // opponent's server port
				x = 9;
				y = 9;
				is_revealed = 1;
				is_alive = 0;
				return 1;
			}
			else {
				x++;
			}
		}

	}
	}
	
}

bool Link::battle(Link& rhs) {
	if (strength >= rhs.strength) {
		rhs.x = 10;
		rhs.y = 10;
		is_revealed = 1;
		rhs.is_alive = false;
		rhs.is_revealed = 1;
		return true;
		// probably need to add something here
	}
	else {
		x = 10;
		y = 10;
		is_revealed = 1;
		is_alive = false;
		rhs.is_revealed = 1;
		return false;
		// probably need to add something here
	}
}
