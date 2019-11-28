#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Link.h"
#include "GameManager.h"

class Ability;


class Player {
	
	Player* p; // the opponent's player pointer
	
	 
	GameManager gm;
	friend class Grid;

public:
	std::vector<Link> links;
	std::vector<Ability> abilities;
	std::vector<int> wall_xy; // the firewall coordinate opponent set on "me"
	int dlVirus; // # of downloaded viruses
	int dlData; // # of downloaded datas
	int nAbility; // # of abilities left
	static int p1_turn; // check if it's player 1's turn at the moment
	bool win();
	bool lose();
	
	void set_opponent(Player* p);
	
	void apply(int n, int x, int y);
	void apply(int n, char name);

	void move(char name, std::string dir);
	void battle(Link& l1, Link& l2);
	Player(std::vector<Link> links, std::vector<Ability> abilities, std::vector<int> wall_xy, int v, int d, int a, GameManager gm);
	~Player();
};



#endif
