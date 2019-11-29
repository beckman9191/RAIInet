#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <vector>

class Link;

class Grid;

class Player;


class GameManager {
public:
	Grid* g = nullptr;
	Player* p1 = nullptr;
	Player* p2 = nullptr;
	

public:

	
	

	void notify_move(Link l); // notify the move from the link
	
	void notify_battle_res(Link winner, Link loser); // notify the battle result from two links

	void notify_boost(Link l); // notify if the ability "Link Boost" is applied to specific link

	void notify_firewall(int x, int y, bool p1_turn); // notify if the ability "Firewall" is applied to specific link

	void notify_download(Link l); // notify if the ablity "Download" is applied to specific link

	void notify_polarize(Link l); // notify if the ablity "Polarize" is applied to specific link

	void notify_scan(Link l); // notify if the ablity "Scan" is applied to specific link

	~GameManager();

};


#endif
