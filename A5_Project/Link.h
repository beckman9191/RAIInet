#ifndef LINK_H_
#define LINK_H_
#include <string>
#include <iostream>
#include <vector>


class Link {
public:
	std::string identity; // "Virus" or "Data"
	int strength; // [1-4]
	int x, y; // position in 8x8 grid
	char name; // e.g. a, b, c, d, ...
	int is_boost; // if ability "link boost" applied
	bool is_alive; // if downloaded
	bool is_revealed; // if permanetly revealed
	
	/********* Method ************/
	Link(std::string identity = "Data", int strength = 1, int x = 0, int y = 0, char name = 'a', 
		int is_boost = 0, bool is_alive = 1, bool is_revealed = 0);

	int move(std::string dir, bool if_p1);

	bool battle(Link& rhs);

	Link& operator=(const Link& other);
	


};










#endif
