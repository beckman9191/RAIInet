#include "Link.h"
#include "Player.h"
#include "Ability.h"
#include <iostream>


using namespace std;

int Player::p1_turn = 1;

Player::Player(vector<Link> links, vector<Ability> abilities, vector<int> wall_xy, int v, int d, int a, GameManager gm) :
	links{ links }, abilities{ abilities }, wall_xy{ wall_xy }, p{ nullptr }, dlVirus{ v }, dlData{ d }, nAbility{ a }, gm{ gm } {}

	Player::~Player() {
		links.clear();
		abilities.clear();
		delete p;
	}

	vector<int> Player::getWall() {
		return wall_xy;
	}

	void Player::set_opponent(Player* p) {
		this->p = p;
	}

	bool Player::win() {
		return this->dlData == 4;
	}

	bool Player::lose() {
		return this->dlVirus == 4;
	}

	void Player::notify_gm_move(GameManager& gm, Link l) {
		gm.notify_move(l);
	}

	void Player::notify_gm_battle_res(GameManager& gm, Link winner, Link loser) {
		gm.notify_battle_res(winner, loser);
	}

	void Player::apply(int n, char name) { // LinkBoost, Download, Polarize, Scan
		int j;
		for (int i = 0; i < links.size(); ++i) {
			if (name == links.at[i].name) {
				abilities.at[n].apply(links.at[i]);
				j = i;
			}
		}
		if (abilities.at(n).get_name() == "Linkboost") {
			gm.notify_boost(links.at(j));
		}
		else if (abilities.at(n).get_name() == "Download") {
			gm.notify_download(links.at(j));
		}
		else if (abilities.at(n).get_name() == "Polarize") {
			gm.notify_polarize(links.at(j));
		}
		else if (abilities.at(n).get_name() == "Scan") {
			gm.notify_scan(links.at(j));
		}
	}

	void Player::apply(int n, int x, int y) { // Firewall -- existing firewall? all links? out of grid? SS?
		if ((x > 7) || (y > 7) || (x < 0) || (y < 0)) {
			cout << "Invalid firewall." << endl;
			return;
		}
		if (((x == 3) && (y == 0)) || (x == 4) && (y == 0)) {
			cout << "Invalid firewall." << endl;
			return;
		}
		if (((x == 3) && (y == 7)) || (x == 4) && (y == 7)) {
			cout << "Invalid firewall." << endl;
			return;
		}
		for (int i = 0; i < links.size(); ++i) {
			if ((x == links.at[i].x) && (y == links.at[i].y)) {
				cout << "Invalid firewall." << endl;
				return;
			}
		}
		for (int j = 0; j < p->links.size(); ++j) {
			if ((x == p->links.at[j].x) && (y == links.at[i].y)) {
				cout << "Invalid firewall." << endl;
				return;
			}
		}
		int i = 0;
		int j = 1;
		while (j < wall_xy.size()) {
			if ((x == wall_xy[i]) && (y == wall_xy[j])) {
				cout << "There is already a firewall." << endl;
				return;
			}
			i += 2;
			j += 2;
		}
		i = 0;
		j = 1;
		while (j < p->wall_xy.size()) {
			if ((x == p->wall_xy[i]) && (y == p->wall_xy[j])) {
				cout << "There is already a firewall." << endl;
				return;
			}
			i += 2;
			j += 2;
		}
		(p->wall_xy).push_back(x);
		(p->wall_xy).push_back(y);
		bool turn = 0;
		if (p1_turn % 2 == 1) {
			turn = 1;
		}
		gm.notify_firewall(x, y, turn); // turn -> if it's p1's turn
	}


	void Player::move(string name, string dir) {
		Link l; // copy of the link
		int index = 0;
		for (int i = 0; i < links.size(); ++index) {
			l = links.at[index];

			if (dir == "left") {
				l.x -= l.is_boost;
			}
			if (dir == "right") {
				l.x += l.is_boost;
			}
			if (dir == "up") {
				l.y -= l.is_boost;
			}
			if (dir == "down") {
				l.y += l.is_boost;
			}
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
				links.at[index].move(dir, this->p1_turn);
				notify_gm_move(gm, links.at[index]);
				this->battle(links.at[index], p->links.at[k]);
				return;
			}
		}
		int i = 0;
		int j = 1;
		while (j < p->wall_xy.size()) {  // check if it is at firewall set by opponent
			if ((l.x == p->wall_xy[i]) && (l.y == p->wall_xy[j])) {
				if (links.at[index].identity == "Virus") {
					dlVirus += 1;
					gm.notify_firewall(links.at[index]);   //
					gm.notify_download(links.at[index]);
				}
				else {
					gm.notify_firewall(links.at[index]);
				}
			}
			i += 2;
			j += 2;
		}
		int status = links.at[index].move(dir, this->p1_turn);
		if (links.at[index].identity == "Virus") {
			if (status == -1) {}       //-1: invalid move
			else if (status == 0) {}   // 0: valid move
			else if (status == 1) {    // 1: gets to opponent's SS
				p->dlVirus += 1;
			}
			else if (status == 2) {    // 2: move off opponent's edge
				this->dlVirus += 1;
			}
		}
		else if (links.at[index].identity == "Data") {
			if (status == -1) {}
			else if (status == 0) {}
			else if (status == 1) {
				p->dlData += 1;
			}
			else if (status == 2) {
				this->dlData += 1;
			}
		}
		notify_gm_move(gm, links.at[index]);
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



