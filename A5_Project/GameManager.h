#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Grid.h"

#include <vector>

class Link;



class GameManager {
public:
	Grid g;
	Player *p1;
	Player *p2;
	std::vector<Link> vec_link; // deletable

public:
	void notify_move(Link l, Grid& g);
	
	void notify_battle_res(Link winner, Link loser, Grid& g);

	~GameManager();

};


#endif
