#include "GameManager.h"
#include "Link.h"
#include "Grid.h"

using namespace std;



void GameManager::notify_move(Link l) { 
	int new_x = l.x;
	int new_y = l.y;
	int ori_x = 0;
	int ori_y = 0;
	int j = 0;
	int k = 1;
	
	
	
	for (int i = 0; i < 16; ++i) { 
		if (g->vl.at(i).name == l.name) {
			ori_x = g->vl.at(i).x;
			ori_y = g->vl.at(i).y;
			
				g->vl.at(i).x = new_x;
				g->vl.at(i).y = new_y;
			
		}

	}
	
	if (new_y > 7 || new_y < 0) {
		g->theDisplay.at(ori_x).at(ori_y) = '.';
	} 

	g->theDisplay.at(ori_x).at(ori_y) = '.';
	

	int p1_wall_size = p1->wall_xy.size();
	while (k < p1_wall_size) { // check if the previous cell has firewall or no
		if ((p1->wall_xy[j] == ori_x) && (p1->wall_xy[k] == ori_y)) {
			g->theDisplay.at(ori_x).at(ori_y) = 'w';
		}
		j += 2;
		k += 2;
	}
	j = 0;
	k = 1;

	int p2_wall_size = p2->wall_xy.size();
	while (k < p2_wall_size) { // check if the previous cell has firewall or no
		if ((p2->wall_xy[j] == ori_x) && (p2->wall_xy[k] == ori_y)) {
			g->theDisplay.at(ori_x).at(ori_y) = 'm';
		}
		j += 2;
		k += 2;
	}
	
		g->theDisplay.at(new_x).at(new_y) = l.name;
	
	
}


void GameManager::notify_battle_res(Link winner, Link loser) {
	for (int i = 0; i < 16; ++i) {
		if (g->vl.at(i).name == loser.name) {
			g->vl.at(i).is_revealed = 1;
			g->vl.at(i).is_alive = false;
			g->vl.at(i).x = 10;
			g->vl.at(i).y = 10;
		}
		if (g->vl.at(i).name == winner.name) {
			g->vl.at(i).is_revealed = 1;
		}

	}
	g->theDisplay.at(winner.x).at(winner.y) = winner.name;

}



void GameManager::notify_boost(Link l) {
	for (int i = 0; i < 16; ++i) {
		if (g->vl.at(i).name == l.name) {
			g->vl.at(i).is_boost++;
		}

	}
}

void GameManager::notify_firewall(int x, int y, bool p1_turn) {
	if (p1_turn) {
		g->theDisplay.at(x).at(y) = 'm';

	}
	else {
		g->theDisplay.at(x).at(y) = 'w';
	}
}

void GameManager::notify_download(Link l) { 
	int x;
	int y;
	int j = 0;
	int k = 1;
	for (int i = 0; i < 16; ++i) {
		if (g->vl.at(i).name == l.name) {
			g->vl.at(i).is_revealed = true;
			g->vl.at(i).is_alive = false;
			x = g->vl.at(i).x;
			y = g->vl.at(i).y;
			g->vl.at(i).x = 10;
			g->vl.at(i).y = 10;
		}

	}
	g->theDisplay.at(x).at(y) = '.';

	int p1_wall_size = p1->wall_xy.size();
	while (k < p1_wall_size) { // check if the current cell has firewall or no
		if ((p1->wall_xy[j] == x) && (p1->wall_xy[k] == y)) {
			g->theDisplay.at(x).at(y) = 'w';
		}
		j += 2;
		k += 2;
	}
	j = 0;
	k = 1;

	int p2_wall_size = p2->wall_xy.size();
	while (k < p2_wall_size) { // check if the current cell has firewall or no
		if ((p2->wall_xy[j] == x) && (p2->wall_xy[k] == y)) {
			g->theDisplay.at(x).at(y) = 'm';
		}
		j += 2;
		k += 2;
	}
}

void GameManager::notify_polarize(Link l) {
	for (int i = 0; i < 16; ++i) {
		if (g->vl.at(i).name == l.name) {
			if (g->vl.at(i).identity == "Virus") {
				g->vl.at(i).identity == "Data";
			}
			else {
				g->vl.at(i).identity == "Virus";
			}
		}

	}
	for (int i = 0; i < 8; ++i) {
		if (p1->links.at(i).name == l.name) {
			if (p1->links.at(i).identity == "Virus") {
				p1->links.at(i).identity == "Data";
			}
			else {
				p1->links.at(i).identity == "Virus";
			}
		}
	}
	for (int i = 0; i < 8; ++i) {
		if (p2->links.at(i).name == l.name) {
			if (p2->links.at(i).identity == "Virus") {
				p2->links.at(i).identity == "Data";
			}
			else {
				p2->links.at(i).identity == "Virus";
			}
		}
	}
}

void GameManager::notify_scan(Link l) {
	for (int i = 0; i < 16; ++i) {
		if (g->vl.at(i).name == l.name) {
			g->vl.at(i).is_revealed = true;
		}
	}
	for (int i = 0; i < 8; ++i) {
		if (p1->links.at(i).name == l.name) {
			p1->links.at(i).is_revealed = true;
		}
	}
	for (int i = 0; i < 8; ++i) {
		if (p2->links.at(i).name == l.name) {
			p2->links.at(i).is_revealed = true;
		}
	}
}

GameManager::~GameManager() {}
