#include "Grid.h"
#include <string>

using namespace std;

Grid::Grid(int n, Player* p1, Player* p2) : gridsize{ n }, p1 { p1 }, p2{ p2 } {
	/********* setup for vector of Links**********/
	vl.clear(); 
	vl.reserve(16);
	for (int i = 0; i < 8; ++i) {
		vl.emplace_back(p1->links.at(i)); // push the links to our stack of links from player 1
	}
	for (int i = 0; i < 8; ++i) {
		vl.emplace_back(p2->links.at(i)); // push the links to our stack of links from player 2
	}



	/**********setup for textdisplay************/
	theDisplay.clear();
	theDisplay.resize(n + 3); // resize for number of rows
	
	for (int i = 0; i < n; ++i) {
		
		theDisplay.at(i).reserve(n + 3); // reserve n spaces for columns
		for (int j = 0; j < n; ++j) {
			if (i == 0 && j == 0) {
				theDisplay.at(i).emplace_back(vl.at(0).name);
			}
			else if (i == 1 && j == 0) {
				theDisplay.at(i).emplace_back(vl.at(1).name);
			}
			else if (i == 2 && j == 0) {
				theDisplay.at(i).emplace_back(vl.at(2).name);
			}
			else if (i == 3 && j == 0) {
				theDisplay.at(i).emplace_back('S');
			} 
			else if (i == 4 && j == 0) {
				theDisplay.at(i).emplace_back('S');
			}
			else if (i == 5 && j == 0) {
				theDisplay.at(i).emplace_back(vl.at(5).name);
			}
			else if (i == 6 && j == 0) {
				theDisplay.at(i).emplace_back(vl.at(6).name);
			}
			else if (i == 7 && j == 0) {
				theDisplay.at(i).emplace_back(vl.at(7).name);
			}
			else if (i == 3 && j == 1) {
				theDisplay.at(i).emplace_back(vl.at(3).name);
			}
			else if (i == 4 && j == 1) {
				theDisplay.at(i).emplace_back(vl.at(4).name);
			}
			else if (i == 0 && j == 7) {
				theDisplay.at(i).emplace_back(vl.at(8).name);
			}
			else if (i == 1 && j == 7) {
				theDisplay.at(i).emplace_back(vl.at(9).name);
			}
			else if (i == 2 && j == 7) {
				theDisplay.at(i).emplace_back(vl.at(10).name);
			}
			else if (i == 3 && j == 7) {
				theDisplay.at(i).emplace_back('S');
			}
			else if (i == 4 && j == 7) {
				theDisplay.at(i).emplace_back('S');
			}
			else if (i == 5 && j == 7) {
				theDisplay.at(i).emplace_back(vl.at(13).name);
			}
			else if (i == 6 && j == 7) {
				theDisplay.at(i).emplace_back(vl.at(14).name);
			}
			else if (i == 7 && j == 7) {
				theDisplay.at(i).emplace_back(vl.at(15).name);
			}
			else if (i == 3 && j == 6) {
				theDisplay.at(i).emplace_back(vl.at(11).name);
			}
			else if (i == 4 && j == 6) {
				theDisplay.at(i).emplace_back(vl.at(12).name);
			}
			else {
				theDisplay.at(i).emplace_back('.');
			}
		}
		
	}
	theDisplay.at(n).resize(n + 3);
	theDisplay.at(n + 1).resize(n + 3);
	theDisplay.at(n + 2).resize(n + 3);
	
}

Grid::~Grid() {
	
}



ostream& operator<<(ostream& out, const Grid& g) {
	cout << "========" << endl;
	for (int i = 0; i < g.gridsize; ++i) {
		for (int j = 0; j < g.gridsize; ++j) {
			
				out << g.theDisplay.at(j).at(i);
			
		}
		out << endl;
	}
	cout << "========" << endl;
	return out;
}

