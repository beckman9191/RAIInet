#include "Link.h"
#include "Player.h"
#include "Ability.h"
#include <iostream>


using namespace std;

int Player::p1_turn = 1;

Player::Player(vector<Link> links, vector<Ability*> abilities, vector<int> wall_xy, int v, int d, int a, GameManager &gm) :
	links{ links }, abilities{ abilities }, wall_xy{ wall_xy }, p{ nullptr }, dlVirus{ v }, dlData{ d }, nAbility{ a }, gm { gm } {}

	Player::~Player() {
		links.clear();
		abilities.clear();
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

	bool Player::apply(int n, char name) { // LinkBoost, Download, Polarize, Scan
		int num = n - 1;
		int size = links.size();
		bool turn = 0;
		bool is_used = abilities.at(num)->is_used;
		if (p1_turn % 2 == 1) {
			turn = 1;
		}
		
		if ((is_used) || (num > 4) || (num < 0)) {
			cout << "Ability is not available." << endl;
			return false;
		}
		int i = 0;
		for (; i < size; ++i) {
			if (name == links.at(i).name) {
				
				if (abilities.at(num)->get_name() == "Linkboost") {
					abilities.at(num)->apply(links.at(i));
					gm.notify_boost(links.at(i));
				}
				else if (abilities.at(num)->get_name() == "Download") {
					cout << "Can't download your own link." << endl;
					return false;
				}
				else if (abilities.at(num)->get_name() == "Polarize") {
					abilities.at(num)->apply(links.at(i));
					gm.notify_polarize(links.at(i));
				}
				else if (abilities.at(num)->get_name() == "Scan") {
					abilities.at(num)->apply(links.at(i));
					gm.notify_scan(links.at(i));
				}
			}
		}
		int j = 0;
		for (; j < size; ++j) {
			if (name == p->links.at(j).name) {
				
				if (abilities.at(num)->get_name() == "Linkboost") {
					cout << "Can't boost opponent's link." << endl;
					return false;
				}
				else if (abilities.at(num)->get_name() == "Download") {
					p->abilities.at(num)->apply(p->links.at(j));
					gm.notify_download(p->links.at(j));
				}
				else if (abilities.at(num)->get_name() == "Polarize") {
					p->abilities.at(num)->apply(p->links.at(j));
					gm.notify_polarize(p->links.at(j));
				}
				else if (abilities.at(num)->get_name() == "Scan") {
					p->abilities.at(num)->apply(p->links.at(j));
					gm.notify_scan(p->links.at(j));
				}
			}
		}
	abilities.at(num)->is_used = 1;
	--nAbility;
	return true;
	}

	bool Player::apply(int n, int x, int y) { // Firewall -- existing firewall? all links? out of grid? SS?
		int size = links.size();
		int num = n - 1;
		bool turn = 0;
		bool is_used = abilities.at(num)->is_used;
		if (p1_turn % 2 == 1) {
			turn = 1;
		}
		
		if ((is_used) || (num > 4) || (num < 0)) {
			cout << "Ability is not available." << endl;
			return false;
		}

		if ((x > 7) || (y > 7) || (x < 0) || (y < 0)) {
			cout << "Invalid firewall." << endl;
			return false;
		}
		if (((x == 3) && (y == 0)) || (x == 4) && (y == 0)) {
			cout << "Invalid firewall." << endl;
			return false;
		}
		if (((x == 3) && (y == 7)) || (x == 4) && (y == 7)) {
			cout << "Invalid firewall." << endl;
			return false;
		}
		for (int i = 0; i < size; ++i) {
			if ((x == links.at(i).x) && (y == links.at(i).y)) {
				cout << "Invalid firewall." << endl;
				return false;
			}
		}
		for (int j = 0; j < size; ++j) {
			if ((x == p->links.at(j).x) && (y == p->links.at(j).y)) {
				cout << "Invalid firewall." << endl;
				return false;
			}
		}
		int i = 0;
		int j = 1;
		size = wall_xy.size();
		while (j < size) {
			if ((x == wall_xy[i]) && (y == wall_xy[j])) {
				cout << "There is already a firewall." << endl;
				return false;
			}
			i += 2;
			j += 2;
		}
		i = 0;
		j = 1;
		size = p->wall_xy.size();
		while (j < size) {
			if ((x == p->wall_xy[i]) && (y == p->wall_xy[j])) {
				cout << "There is already a firewall." << endl;
				return false;
			}
			i += 2;
			j += 2;
		}
		(p->wall_xy).push_back(x);
		(p->wall_xy).push_back(y);
		--nAbility;	
		abilities.at(num)->is_used = 1;
		gm.notify_firewall(x, y, turn); // turn -> if it's p1's turn
		return true;
	}




	bool Player::move(char name, string dir) {
		Link l; // copy of the link
		int index = 0;
		int size = links.size();
		
		for (; index < size; ++index) {
			if (name == links.at(index).name) {
				l = links.at(index);
				break;
			}
		}
		if (index == 8) {
			cout << "Don't move other's links, you dumbass!" << endl;
			return false;
		}
		int step = l.is_boost + 1;
			if (dir == "left") {
				l.x -= step;
			}
			if (dir == "right") {
				l.x += step;
			}
			if (dir == "up") {
				l.y -= step;
			}
			if (dir == "down") {
				l.y += step;
			}
		
		for (int j = 0; j < size; ++j) { // check any owned links is already on pos(x,y)
			if (l.name != links.at(j).name) {
				if ((l.x == links.at(j).x) && (l.y == links.at(j).y)) {
					cout << "Invalid move: " << links.at(j).name
						<< "is already at pos(" << links.at(j).x << "," << links.at(j).y << ")!" << endl;
					return false;
				}
			}
		}
		for (int k = 0; k < size; ++k) {
			if ((l.x == p->links.at(k).x) && (l.y == p->links.at(k).y)) { // check any opponent's links is at pos
				links.at(index).move(dir, this->p1_turn);
				gm.notify_move(links.at(index));
				this->battle(links.at(index), p->links.at(k));
			}
		}
		int i = 0;
		int j = 1;

		


		size = p->wall_xy.size();
		while (j < size) {  // check if it is at firewall set by opponent
			if ((l.x == p->wall_xy[i]) && (l.y == p->wall_xy[j])) {
				if (links.at(index).identity == "Virus") {
					dlVirus += 1;
					gm.notify_scan(links.at(index));
					gm.notify_download(links.at(index));
				}
				else {
					gm.notify_scan(links.at(index));
				}
			}
			i += 2;
			j += 2;
		}

		
		

		int status = links.at(index).move(dir, this->p1_turn);
		if (links.at(index).identity == "Virus") {
			if (status == -1) {        //-1: invalid move
				return false;
			}
			else if (status == 0) { }   // 0: valid move
			else if (status == 1) {    // 1: gets to opponent's SS
				p->dlVirus += 1;
			}
			else if (status == 2) {    // 2: move off opponent's edge
				this->dlVirus += 1;
			}
		}
		
		
		else if (links.at(index).identity == "Data") {
			if (status == -1) {
				return false;
			}
			else if (status == 0) { }
			else if (status == 1) {
				p->dlData += 1;
			}
			else if (status == 2) {
				this->dlData += 1;
			}
			}
		
			gm.notify_move(links.at(index)); // ?????????????????????????????
			return true;
		}



	void Player::battle(Link &l1, Link& l2) {
		bool win = l1.battle(l2);
		if (win) {
			if (l1.identity == "Virus") {
				this->dlVirus += 1;
				gm.notify_battle_res(l1, l2);
			}
		else if (l1.identity == "Data") {
				this->dlData += 1;
				gm.notify_battle_res(l1, l2);
			}
		}
		else {
		 if (l1.identity == "Virus") {
			p->dlVirus += 1;
			gm.notify_battle_res(l2, l1);
		}
		else if (l1.identity == "Data") {
			p->dlData += 1;
			gm.notify_battle_res(l2, l1);
			}
		}

}



