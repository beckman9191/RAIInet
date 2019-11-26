#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Link.h"
#include "GameManager.h"




class Player {
	std::vector<Link> links;
	std::vector<ability> abilities;
	Player* p; // the opponent's player pointer
	int dlVirus; // # of downloaded viruses
	int dlData; // # of downloaded datas
	int nAbility; // # of abilities left
	bool isnext; // check if it's this player's turn at the moment
	bool p1_turn;
	GameManager gm;
	friend class Grid;
public:
	
	bool win();
	bool lose();
	void move(std::string name, std::string dir);
	void battle(Link& l1, Link& l2);
	void notify_gm_move(GameManager& gm, Link l);
	void notify_gm_battle_res(GameManager& gm, Link winner, Link loser);
	Player(std::vector<Link> links, std::vector<ability> abilities, Player* p2, int v, int d, int a, bool turn);
	~Player();
};



#endif
