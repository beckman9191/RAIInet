#include <iostream>
#include <string>
#include "Ability.h"
#include "GameManager.h"
#include "Grid.h"
#include "Link.h"
#include "Player.h"


using namespace std;

/*
 Test harness
*/


int main(int argc, char* argv[]) {
	/********* default link information for player 1*********/
	Link p1_V1{ "Virus", 1, 0, 0, 'a', 0, 1, 0 };
	Link p1_V2{ "Virus", 2, 1, 0, 'b', 0, 1, 0 };
	Link p1_V3{ "Virus", 3, 2, 0, 'c', 0, 1, 0 };
	Link p1_V4{ "Virus", 4, 3, 1, 'd', 0, 1, 0 };
	Link p1_D1{ "Data", 1, 4, 1, 'e', 0, 1, 0 };
	Link p1_D2{ "Data", 2, 5, 0, 'f', 0, 1, 0 };
	Link p1_D3{ "Data", 3, 6, 0, 'g', 0, 1, 0 };
	Link p1_D4{ "Data", 4, 7, 0, 'h', 0, 1, 0 };

	/********* default link information for player 2*********/
	Link p2_V1{ "Virus", 1, 0, 7, 'A', 0, 1, 0 };
	Link p2_V2{ "Virus", 2, 1, 7, 'B', 0, 1, 0 };
	Link p2_V3{ "Virus", 3, 2, 7, 'C', 0, 1, 0 };
	Link p2_V4{ "Virus", 4, 3, 6, 'D', 0, 1, 0 };
	Link p2_D1{ "Data", 1, 4, 6, 'E', 0, 1, 0 };
	Link p2_D2{ "Data", 2, 5, 7, 'F', 0, 1, 0 };
	Link p2_D3{ "Data", 3, 6, 7, 'G', 0, 1, 0 };
	Link p2_D4{ "Data", 4, 7, 7, 'H', 0, 1, 0 };

	/********* setup vector of links for p1 *********/
	vector<Link> p1_links;
	p1_links.push_back(p1_V1);
	p1_links.push_back(p1_V2);
	p1_links.push_back(p1_V3);
	p1_links.push_back(p1_V4);
	p1_links.push_back(p1_D1);
	p1_links.push_back(p1_D2);
	p1_links.push_back(p1_D3);
	p1_links.push_back(p1_D4);

	/********* setup vector of links for p2 *********/
	vector<Link> p2_links;
	p2_links.push_back(p2_V1);
	p2_links.push_back(p2_V2);
	p2_links.push_back(p2_V3);
	p2_links.push_back(p2_V4);
	p2_links.push_back(p2_D1);
	p2_links.push_back(p2_D2);
	p2_links.push_back(p2_D3);
	p2_links.push_back(p2_D4);

	/********* setup vector of links for p2 *********/
	

	if (argc == 1) {
		
	}
}