#include "Link.h"
#include <string>

using namespace std;

Link::Link() : is_boost{ 0 }, is_alive{ 1 }, is_revealed{ 0 } {}

void Link::move(string name, string dir) {
	if (dir == "up") {
		y++;
	}
	else if (dir == "down") {
		y--;
	}
	else if (dir == "left") {
		x--;
	}
	else if (dir == "right") {
		x++;
	}
}

void Link::battle(Link& rhs) {
	if (strength >= rhs.strength) {
		rhs.is_alive = 0;
		// probably need to add something here
	}
	else {
		is_alive = 0;
		// probably need to add something here
	}
}