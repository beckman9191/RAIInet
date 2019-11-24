#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include "Link.h"

using namespace std;

class Grid {
	vector<vector<char>> theDisplay;
	vector<Link> vl;
	const int gridsize;
	Player* p1;
	Player* p2;

public:
	Grid(int n);

	~Grid();

	friend ostream& operator<<(ostream& out, const Grid &g);

};


#endif
