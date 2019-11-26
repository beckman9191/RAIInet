#include "Link.h"
#include "Player.h"
#include <iostream>


using namespace std;

Player::Player(vector<Link> links, vector<ability> abilities, Player* p, int v, int d, int a, bool turn) :
	links{ links }, abilities{ abilities }, p{ p }, dlVirus{ v }, dlData{ d }, nAbility{ a }, isnext{ turn } {}

	Player::~Player() {
		links.clear();
		abilities.clear();
		delete p;
	}

	bool Player::win() {
		return this->dlData == 4;
	}

	bool Player::lose() {
		return this->dlVirus == 4;
	}

	void Player::notify_gm_move(GameManager& gm, Link l) {
		gm.notify_move(l, gm.g);
	}

	void Player::notify_gm_battle_res(GameManager& gm, Link winner, Link loser) {
		gm.notify_battle_res(winner, loser, gm.g);
	}



	void Player::move(string name, string dir) {
		Link l; // copy of the link
		int i = 0;
		for (; i < links.size(); ++i) {
			l = links.at[i];
		}
		if (dir == "left") {
			l.x -= 1;
		}
		if (dir == "right") {
			l.x += 1;
		}
		if (dir == "up") {
			l.y -= 1;
		}
		if (dir == "down") {
			l.y += 1;
		}
		for (int j = 0; j < links.size(); ++j) { // check any owned links is already on pos(x,y)
			if (l.name != links.at[j].name) {
				if ((l.x == links.at[j].x) && (l.y == links.at[j].y)) {
					cout << "Invalid move: " << links.at[j].name
						<< "is already at pos(" << links.at[j].x << "," << links.at[j].y << ")!" << endl;
					return;
				}
			}
		}
		for (int k = 0; k < p->links.size(); ++k) {
			if ((l.x == p->links.at[k].x) && (l.y == p->links.at[k].y)) { // check any opponent's links is at pos
				links.at[i].move(dir, this->p1_turn);
				notify_gm_move(gm, links.at[i]);
				this->battle(links.at[i], p->links.at[k]);
				return;
			}
		}
		int status = links.at[i].move(dir, this->p1_turn);
		if (links.at[i].identity == "Virus") {
			if (status == -1) {}       //-1: invalid move
			else if (status == 0) {}   // 0: valid move
			else if (status == 1) {    // 1: gets to opponent's SS
				p->dlVirus += 1;
			}
			else if (status == 2) {    // 2: move off opponent's edge
				this->dlVirus += 1;
			}
			else if (links.at[i].identity == "Data") {
				if (status == -1) {}
				else if (status == 0) {}
				else if (status == 1) {
					p->dlData += 1;
				}
				else if (status == 2) {
					this->dlData += 1;
				}
			}


			notify_gm_move(gm, links.at[i]);
		}
	}



	void Player::battle(Link &l1, Link& l2) {
		bool win = l1.battle(l2);
		if (win) {
			if (l1.identity == "Virus") {
				this->dlVirus += 1;
				notify_gm_battle_res(gm, l1, l2);
			}
		else if (l1.identity == "Data") {
				this->dlData += 1;
				notify_gm_battle_res(gm, l1, l2);
			}
		}
		else {
		 if (l1.identity == "Virus") {
			p->dlVirus += 1;
			notify_gm_battle_res(gm, l2, l1);
		}
		else if (l1.identity == "Data") {
			p->dlData += 1;
			notify_gm_battle_res(gm, l2, l1);
			}
		}

}



