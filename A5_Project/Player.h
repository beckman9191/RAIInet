#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Link.h"
#include "GameManager.h"

class Ability;


class Player {
	std::vector<Link> links;
	std::vector<Ability> abilities;
	std::vector<int> wall_xy; // the firewall coordinate opponent set on "me"
	Player* p; // the opponent's player pointer
	int dlVirus; // # of downloaded viruses
	int dlData; // # of downloaded datas
	int nAbility; // # of abilities left
	static int p1_turn; // check if it's player 1's turn at the moment
	GameManager gm;
	friend class Grid;

public:
	bool win();
	bool lose();
	void set_opponent(Player* p);
	std::vector<int> getWall();
	void apply(int n, int x, int y);
	void apply(int n, char name);
	void notify_gm_move(GameManager& gm, Link l);
	void notify_gm_battle_res(GameManager& gm, Link winner, Link loser);
	void move(std::string name, std::string dir);
	void battle(Link& l1, Link& l2);
	Player(std::vector<Link> links, std::vector<Ability> abilities, std::vector<int> wall_xy, int v, int d, int a, GameManager gm);
	~Player();
};



#endif
