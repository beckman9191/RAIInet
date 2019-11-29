#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include "Link.h"
#include "Player.h"



class Grid {
public:
	std::vector<std::vector<char>> theDisplay;
	std::vector<Link> vl;
	const int gridsize;
	Player* p1 = nullptr;
	Player* p2 = nullptr;

public:
	Grid(int n, Player* p1, Player* p2);

	~Grid();

	friend std::ostream& operator<<(std::ostream& out, const Grid &g);

};


#endif
