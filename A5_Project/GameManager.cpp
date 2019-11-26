#include "GameManager.h"

using namespace std;

void GameManager::notify_move(Link l, Grid& g) {
	int new_x = l.x;
	int new_y = l.y;
	int ori_x;
	int ori_y;
	for (int i = 0; i < 16; ++i) {
		if (g.vl.at(i).name == l.name) {
			ori_x = g.vl.at(i).x;
			ori_y = g.vl.at(i).y;
			g.vl.at(i).x = new_x;
			g.vl.at(i).y = new_y;
		}
		if (vec_link.at(i).name == l.name) {
			vec_link.at(i).x = new_x;
			vec_link.at(i).y = new_y;
		} // need to be discussed
	}
	if (new_y > 7 || new_y < 0) {
		g.theDisplay.at(ori_x).at(ori_y) = '.';
	}

	g.theDisplay.at(ori_x).at(ori_y) = '.';
	g.theDisplay.at(new_x).at(new_y) = l.name;
	
}


void GameManager::notify_battle_res(Link winner, Link loser, Grid& g) {
	for (int i = 0; i < 16; ++i) {
		if (g.vl.at(i).name == loser.name) {
			g.vl.at(i).is_alive = false;
			g.vl.at(i).x = 10;
			g.vl.at(i).y = 10;
		}
		if (vec_link.at(i).name == loser.name) {
			vec_link.at(i).is_alive = false;
			vec_link.at(i).x = 10;
			vec_link.at(i).is_alive = 10;
		}
	}
	g.theDisplay.at(winner.x).at(winner.y) = winner.name;

}
