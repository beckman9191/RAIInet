#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>

using namespace std;


class TextDisplay {
	vector<vector<char>> theDisplay;
	const int gridsize;
	

public:
	TextDisplay(int n);

	

	friend ostream& operator<<(ostream& out, const TextDisplay& td);

};





#endif
