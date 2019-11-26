#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include "Link.h"
#include "Player.h"



class Grid {
public:
	std::vector<vector<char>> theDisplay;
	std::vector<Link> vl;
	const int gridsize;
	Player* p1;
	Player* p2;

public:
	Grid(int n);

	~Grid();

	friend std::ostream& operator<<(std::ostream& out, const Grid &g);

};


#endif
