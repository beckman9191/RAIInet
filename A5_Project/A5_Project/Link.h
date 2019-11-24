#ifndef LINK_H_
#define LINK_H_
#include "type.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Link {
public:
	string Identity;
	int strength;
	int x, y;
	string name;
	bool is_boost;
	bool is_alive;
	bool is_revealed;
	
/********* Method ************/
	Link();
	void move(string name, string dir);
	void battle(Link& rhs);


};










#endif
