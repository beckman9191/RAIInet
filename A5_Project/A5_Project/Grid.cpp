#include "Grid.h"
#include <string>

using namespace std;

Grid::Grid(int n) : gridsize{ n } {
	/********* setup for vector of Links**********/
	vl.clear();
	vl.reserve(16);
	for (int i = 0; i < 8; ++i) {
		vl.push_back(*p1->vlp.at(i)); // push the links to our stack of links from player 1
	}
	for (int i = 0; i < 8; ++i) {
		vl.push_back(*p2->vlp.at(i)); // push the links to our stack of links from player 2
	}



	/**********setup for textdisplay************/
	theDisplay.clear();
	theDisplay.resize(n); // resize for number of rows
	for (int i = 0; i < n; ++i) {
		theDisplay.at(i).reserve(n); // reserve n spaces for columns
		for (int j = 0; j < n; ++j) {
			if (i == 0 && j == 0) {
				theDisplay.at(i).at(j) = vl.at(8).name;
			}
			else if (i == 1 && j == 0) {
				theDisplay.at(i).at(j) = vl.at(9).name;
			}
			else if (i == 2 && j == 0) {
				theDisplay.at(i).at(j) = vl.at(10).name;
			}
			else if (i == 3 && j == 0) {
				theDisplay.at(i).at(j) = 'S';
			} 
			else if (i == 4 && j == 0) {
				theDisplay.at(i).at(j) = 'S';
			}
			else if (i == 5 && j == 0) {
				theDisplay.at(i).at(j) = vl.at(13).name;
			}
			else if (i == 6 && j == 0) {
				theDisplay.at(i).at(j) = vl.at(14).name;
			}
			else if (i == 7 && j == 0) {
				theDisplay.at(i).at(j) = vl.at(15).name;
			}
			else if (i == 3 && j == 1) {
				theDisplay.at(i).at(j) = vl.at(11).name;
			}
			else if (i == 4 && j == 1) {
				theDisplay.at(i).at(j) = vl.at(12).name;
			}
			else if (i == 0 && j == 7) {
				theDisplay.at(i).at(j) = vl.at(0).name;
			}
			else if (i == 1 && j == 7) {
				theDisplay.at(i).at(j) = vl.at(1).name;
			}
			else if (i == 2 && j == 7) {
				theDisplay.at(i).at(j) = vl.at(2).name;
			}
			else if (i == 3 && j == 7) {
				theDisplay.at(i).at(j) = 'S';
			}
			else if (i == 4 && j == 7) {
				theDisplay.at(i).at(j) = 'S';
			}
			else if (i == 5 && j == 7) {
				theDisplay.at(i).at(j) = vl.at(5).name;
			}
			else if (i == 6 && j == 7) {
				theDisplay.at(i).at(j) = vl.at(6).name;
			}
			else if (i == 7 && j == 7) {
				theDisplay.at(i).at(j) = vl.at(7).name;
			}
			else if (i == 3 && j == 6) {
				theDisplay.at(i).at(j) = vl.at(3).name;
			}
			else if (i == 4 && j == 6) {
				theDisplay.at(i).at(j) = vl.at(4).name;
			}
			else {
				theDisplay.at(i).at(j) = '.';
			}
		}
	}
}

Grid::~Grid() {
	delete p1;
	delete p2;
}



ostream& operator<<(ostream& out, const Grid& g) {
	for (int i = 0; i < g.gridsize; ++i) {
		for (int j = 0; j < g.gridsize; ++j) {
			out << g.theDisplay.at(i).at(j);
		}
		out << endl;
	}
	return out;
}
