#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Ability.h"
#include "GameManager.h"
#include "Grid.h"
#include "Link.h"
#include "Player.h"


using namespace std;

/*
 Test harness
*/

int LinkBoost::p1_t = 1;
int LinkBoost::p2_t = 1;
int Firewall::p1_t = 1;
int Firewall::p2_t = 1;
int Download::p1_t = 1;
int Download::p2_t = 1;
int Polarize::p1_t = 1;
int Polarize::p2_t = 1;
int Scan::p1_t = 1;
int Scan::p2_t = 1;

int main(int argc, char* argv[]) {
	int num_argc = argc - 1;
	GameManager gm;
	/********* default link information for player 1*********/
	Link p1_V1{ "Virus", 1, 0, 0, 'a', 0, 1, 0 };
	Link p1_V2{ "Virus", 2, 1, 0, 'b', 0, 1, 0 };
	Link p1_V3{ "Virus", 3, 2, 0, 'c', 0, 1, 0 };
	Link p1_V4{ "Virus", 4, 3, 1, 'd', 0, 1, 0 };
	Link p1_D1{ "Data", 1, 4, 1, 'e', 0, 1, 0 };
	Link p1_D2{ "Data", 2, 5, 0, 'f', 0, 1, 0 };
	Link p1_D3{ "Data", 3, 6, 0, 'g', 0, 1, 0 };
	Link p1_D4{ "Data", 4, 7, 0, 'h', 0, 1, 0 };

	/********* default link information for player 2*********/
	Link p2_V1{ "Virus", 1, 0, 7, 'A', 0, 1, 0 };
	Link p2_V2{ "Virus", 2, 1, 7, 'B', 0, 1, 0 };
	Link p2_V3{ "Virus", 3, 2, 7, 'C', 0, 1, 0 };
	Link p2_V4{ "Virus", 4, 3, 6, 'D', 0, 1, 0 };
	Link p2_D1{ "Data", 1, 4, 6, 'E', 0, 1, 0 };
	Link p2_D2{ "Data", 2, 5, 7, 'F', 0, 1, 0 };
	Link p2_D3{ "Data", 3, 6, 7, 'G', 0, 1, 0 };
	Link p2_D4{ "Data", 4, 7, 7, 'H', 0, 1, 0 };

	/********* setup vector of links for p1 *********/
	vector<Link> p1_links;
	p1_links.emplace_back(p1_V1);
	p1_links.emplace_back(p1_V2);
	p1_links.emplace_back(p1_V3);
	p1_links.emplace_back(p1_V4);
	p1_links.emplace_back(p1_D1);
	p1_links.emplace_back(p1_D2);
	p1_links.emplace_back(p1_D3);
	p1_links.emplace_back(p1_D4);

	/********* setup vector of links for p2 *********/
	vector<Link> p2_links;
	p2_links.emplace_back(p2_V1);
	p2_links.emplace_back(p2_V2);
	p2_links.emplace_back(p2_V3);
	p2_links.emplace_back(p2_V4);
	p2_links.emplace_back(p2_D1);
	p2_links.emplace_back(p2_D2);
	p2_links.emplace_back(p2_D3);
	p2_links.emplace_back(p2_D4);

	/********* setup Ability *********/
	LinkBoost p1_l1;
	LinkBoost p2_l1;
	LinkBoost p1_l2;
	LinkBoost p2_l2;
	Firewall p1_f1;
	Firewall p2_f1;
	Firewall p1_f2;
	Firewall p2_f2;
	Download p1_d1;
	Download p2_d1;
	Download p1_d2;
	Download p2_d2;
	Polarize p1_p1;
	Polarize p2_p1;
	Polarize p1_p2;
	Polarize p2_p2;
	Scan p1_s1;
	Scan p2_s1;
	Scan p1_s2;
	Scan p2_s2;

	/********* setup vector of Abilities for p1 *********/
	vector<Ability*> p1_abilities;
	p1_abilities.emplace_back(&p1_l1);
	p1_abilities.emplace_back(&p1_f1);
	p1_abilities.emplace_back(&p1_d1);
	p1_abilities.emplace_back(&p1_s1);
	p1_abilities.emplace_back(&p1_p1);


	/********* setup vector of Abilities for p2 *********/
	vector<Ability*> p2_abilities;
	p2_abilities.emplace_back(&p2_l1);
	p2_abilities.emplace_back(&p2_f1);
	p2_abilities.emplace_back(&p2_d1);
	p2_abilities.emplace_back(&p2_s1);
	p2_abilities.emplace_back(&p2_p1);

	/********* setup vector of wall_xy for p1 *********/
	vector<int> wall_xy_p1;

	/********* setup vector of wall_xy for p2 *********/
	vector<int> wall_xy_p2;

	/********* setup for player 1 *********/
	Player p1{ p1_links, p1_abilities, wall_xy_p1, 0, 0, 5, gm };

	/********* setup for player 1 *********/
	Player p2{ p2_links, p2_abilities, wall_xy_p2, 0, 0, 5, gm }; //

	/************* attach each other *************/
	p1.set_opponent(&p2);
	p2.set_opponent(&p1);

	/************* setup grid *************/
	Grid g{ 8, &p1, &p2 };

	/************* setup GM *************/
	gm.g = &g;
	gm.p1 = &p1;
	gm.p2 = &p2;

	/************* Command Interface *************/

	for (int i = 1; i <= num_argc; ++i) {
		string which = argv[i];
		string order;
		if (which == "-graphics") {
			// need to be complete later
		}
		else if (which == "-ability1") { // if p1 set the ability order
			p1.abilities.clear();
			order = argv[i + 1];
			for (int i = 0; i < 5; ++i) {
				if (order[i] == 'L') {
					if (LinkBoost::p1_t == 1) {
						
						p1.abilities.push_back(&p1_l1);
						LinkBoost::p1_t++;
					}
					else if (LinkBoost::p1_t == 2) {
						
						p1.abilities.push_back(&p1_l2);
						LinkBoost::p1_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}

				}
				else if (order[i] == 'F') {
					if (Firewall::p1_t == 1) {
						
						p1.abilities.push_back(&p1_f1);
						Firewall::p1_t++;
					}
					else if (Firewall::p1_t == 2) {
						
						p1.abilities.push_back(&p1_f2);
						Firewall::p1_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
				else if (order[i] == 'D') {
					if (Download::p1_t == 1) {
						
						p1.abilities.push_back(&p1_d1);
						Download::p1_t++;
					}
					else if (Download::p1_t == 2) {
						
						p1.abilities.push_back(&p1_d2);
						Download::p1_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
				else if (order[i] == 'S') {
					if (Scan::p1_t == 1) {
						
						p1.abilities.push_back(&p1_s1);
						Scan::p1_t++;
					}
					else if (Scan::p1_t == 2) {
						
						p1.abilities.push_back(&p1_s2);
						Scan::p1_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
				else if (order[i] == 'P') {
					if (Polarize::p1_t == 1) {
						
						p1.abilities.push_back(&p1_p1);
						Polarize::p1_t++;
					}
					else if (Polarize::p1_t == 2) {
						
						p1.abilities.push_back(&p1_p2);
						Polarize::p1_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
			}
		}
		else if (which == "-ability2") { // if p2 set the ability order
			p2.abilities.clear();
			order = argv[i + 1];
			for (int i = 0; i < 5; ++i) {
				if (order[i] == 'L') {
					if (LinkBoost::p2_t == 1) {
						
						p2.abilities.push_back(&p2_l1);
						LinkBoost::p2_t++;
					}
					else if (LinkBoost::p2_t == 2) {
						
						p2.abilities.push_back(&p2_l2);
						LinkBoost::p2_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}

				}
				else if (order[i] == 'F') {
					if (Firewall::p2_t == 1) {
						
						p2.abilities.push_back(&p2_f1);
						Firewall::p2_t++;
					}
					else if (Firewall::p2_t == 2) {
						
						p2.abilities.push_back(&p2_f2);
						Firewall::p2_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
				else if (order[i] == 'D') {
					if (Download::p2_t == 1) {
						
						p2.abilities.push_back(&p2_d1);
						Download::p2_t++;
					}
					else if (Download::p2_t == 2) {
						
						p2.abilities.push_back(&p2_d2);
						Download::p2_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
				else if (order[i] == 'S') {
					if (Scan::p2_t == 1) {
						
						p2.abilities.push_back(&p2_s1);
						Scan::p2_t++;
					}
					else if (Scan::p2_t == 2) {
						
						p2.abilities.push_back(&p2_s2);
						Scan::p2_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
				else if (order[i] == 'P') {
					if (Polarize::p2_t == 1) {
						
						p2.abilities.push_back(&p2_p1);
						Polarize::p2_t++;
					}
					else if (Polarize::p2_t == 2) {
						
						p2.abilities.push_back(&p2_p2);
						Polarize::p2_t++;
					}
					else {
						cout << "You can only have two same abiility cards" << endl;
						return -1;
					}
				}
			}
		}
		else if (which == "-link1") { // if player 1 set order for link
			order = argv[i + 1];
			int m = 0;
			int n = 1;
			while (m <= 14) {
				if (order[m] == 'V') {
					p1.links.at(m / 2).identity = "Virus";
					p1.links.at(m / 2).strength = order[n] - 48;
				}
				else {
					p1.links.at(m / 2).identity = "Data";
					p1.links.at(m / 2).strength = order[n] - 48;
				}
				m += 2;
				n += 2;

			}
		}
		else if (which == "-link2") { // if player 2 set order for link
			order = argv[i + 1];
			int m = 0;
			int n = 1;
			while (m <= 14) {
				if (order[m] == 'V') {
					p2.links.at(m / 2).identity = "Virus";
					p2.links.at(m / 2).strength = order[n] - 48;
				}
				else {
					p2.links.at(m / 2).identity = "Data";
					p2.links.at(m / 2).strength = order[n] - 48;
				}
				m += 2;
				n += 2;

			}
		}

	}

	/************* Command Interpreter *************/
	Player::p1_turn = 1;
	string s;
	char which;
	string dir;
	cout << g;
	while (cin >> s) {
		if (s == "move") {
			cin >> which;
			cin >> dir;
			if (Player::p1_turn % 2 != 0) { // p1 turn
				
				if (!p1.move(which, dir)) {
					continue;
				}
				

				Player::p1_turn++;
				cout << g;
				// cout the board after move
				if (p1.win() || p2.lose()) {
					cout << "Player 1 wins!" << endl;
					return 0;
				}
				else if (p2.win() || p1.lose()) {
					cout << "Player 2 wins!" << endl;
					return 0;
				}
			}
			else { // p2 turn
				bool valid_move = 0;
				if (!p2.move(which, dir)) {
					continue;
				}
				
				Player::p1_turn++;
				cout << g;
				// cout the board after move
				if (p1.win() || p2.lose()) {
					cout << "Player 1 wins!" << endl;
					return 0;
				}
				else if (p2.win() || p1.lose()) {
					cout << "Player 2 wins!" << endl;
					return 0;
				}
			}
		}
		else if (s == "abilities") {
			if (Player::p1_turn % 2 != 0) { // p1 turn
				for (int i = 0; i < 5; ++i) {
					int n = i + 1;
					cout << n << ": " << p1.abilities.at(i)->get_name();
					if (p1.abilities.at(i)->is_used == 0) {
						cout << " not used";
					}
					else {
						cout << " used";
					}
					cout << endl;
				}

			}
			else { // p2 turn
				for (int i = 0; i < 5; ++i) {
					int n = i + 1;
					cout << n << ": " << p2.abilities.at(i)->get_name();
					if (p2.abilities.at(i)->is_used == 0) {
						cout << " not used";
					}
					else {
						cout << " used";
					}
					cout << endl;
				}
			}
		}

		else if (s == "ability") {
			int which;
			cin >> which;
			if (which >= 6 || which <= 0) {
				cout << "Invalid ID!" << endl;
				string invalid;
				getline(cin, invalid);
				continue;
			}
			if (Player::p1_turn % 2 != 0) { // p1 turn
				if (p1.abilities.at(which - 1)->get_name() == "Firewall") {
					int y;
					int x;
					cin >> y;
					cin >> x;
					p1.apply(which, x, y);
				}
				else {
					char which_on_board;
					cin >> which_on_board;
					p1.apply(which, which_on_board);
				}
			}
			else { // p2 turn
				if (p2.abilities.at(which - 1)->get_name() == "Firewall") {
					int y;
					int x;
					cin >> y;
					cin >> x;
					p2.apply(which, x, y);
				}
				else {
					char which_on_board;
					cin >> which_on_board;
					p2.apply(which, which_on_board);
				}
			}

		}
		else if (s == "board") {
			cout << "Player 1:" << endl;
			cout << "Downloaded: " << p1.dlData << "D, " << p1.dlVirus << "V" << endl;
			cout << "Abilities: " << p1.nAbility << endl;

			if (Player::p1_turn % 2 != 0) { // p1 turn
				for (int i = 0; i <= 3; ++i) { // cout the info for p1
					cout << p1.links.at(i).name << ": " << p1.links.at(i).identity[0] << p1.links.at(i).strength << "   ";
				}
				cout << endl;
				for (int i = 4; i < 8; i++) {
					cout << p1.links.at(i).name << ": " << p1.links.at(i).identity[0] << p1.links.at(i).strength << "   ";
				}
				cout << endl;
				cout << g;
				cout << "Player 2:" << endl;
				cout << "Downloaded: " << p2.dlData << "D, " << p2.dlVirus << "V" << endl;
				cout << "Abilities: " << p2.nAbility << endl;

				for (int j = 0; j <= 3; ++j) {
					cout << p2.links.at(j).name << ": ";
					if (p2.links.at(j).is_revealed == 1) {
						cout << p2.links.at(j).identity[0] << p2.links.at(j).strength << "   ";
					}
					else {
						cout << "?   ";
					}
				}
				cout << endl;
				for (int j = 4; j < 8; j++) {
					cout << p2.links.at(j).name << ": ";
					if (p2.links.at(j).is_revealed == 1) {
						cout << p2.links.at(j).identity[0] << p2.links.at(j).strength << "   ";
					}
					else {
						cout << "?   ";
					}
				}
			}
			else { // p2 turn
				for (int j = 0; j <= 3; ++j) {
					cout << p1.links.at(j).name << ": ";
					if (p1.links.at(j).is_revealed == 1) {
						cout << p1.links.at(j).identity[0] << p1.links.at(j).strength << "   ";
					}
					else {
						cout << "?   ";
					}
				}
				cout << endl;
				for (int j = 4; j < 8; j++) {
					cout << p1.links.at(j).name << ": ";
					if (p1.links.at(j).is_revealed == 1) {
						cout << p1.links.at(j).identity[0] << p1.links.at(j).strength << "   ";
					}
					else {
						cout << "?   ";
					}
				}
				cout << endl;

				cout << g;

				cout << "Player 2:" << endl;
				cout << "Downloaded: " << p2.dlData << "D, " << p2.dlVirus << "V" << endl;
				cout << "Abilities: " << p2.nAbility << endl;

				for (int i = 0; i <= 3; ++i) { // cout the info for p1
					cout << p2.links.at(i).name << ": " << p2.links.at(i).identity[0] << p2.links.at(i).strength << "   ";
				}
				cout << endl;
				for (int i = 4; i < 8; i++) {
					cout << p2.links.at(i).name << ": " << p2.links.at(i).identity[0] << p2.links.at(i).strength << "   ";
				}


			}
			cout << endl;

		}
		else if (s == "sequence") { // I hate this dude, seriously!!
			string content;

			string file_name;
			cin >> file_name;


			ifstream myfile{ file_name };
			while (getline(myfile, content)) {
				stringstream ss(content);
				string command;
				ss >> command;
				if (command == "move") {
					string w;
					string dir;
					ss >> w;
					ss >> dir;
					char which = w[0];
					if (Player::p1_turn % 2 != 0) { // p1 turn
						if (!p1.move(which, dir)) {
							continue;
						}
						
						Player::p1_turn++;
						// cout the board after move
						if (p1.win() || p2.lose()) {
							cout << "Player 1 wins!" << endl;
							return 0;
						}
						else if (p2.win() || p1.lose()) {
							cout << "Player 2 wins!" << endl;
							return 0;
						}
					}
					else { // p2 turn
						if (!p2.move(which, dir)) {
							continue;
						}
						
						Player::p1_turn++;
						// cout the board after move
						if (p1.win() || p2.lose()) {
							cout << "Player 1 wins!" << endl;
							return 0;
						}
						else if (p2.win() || p1.lose()) {
							cout << "Player 2 wins!" << endl;
							return 0;
						}
					}
				}
				else if (command == "abilities") {
					if (Player::p1_turn % 2 != 0) { // p1 turn
						for (int i = 0; i < 5; ++i) {
							int n = i + 1;
							cout << n << ": " << p1.abilities.at(i)->get_name();
							if (p1.abilities.at(i)->is_used == 0) {
								cout << " not used";
							}
							else {
								cout << " used";
							}
							cout << endl;
						}

					}
					else { // p2 turn
						for (int i = 0; i < 5; ++i) {
							int n = i + 1;
							cout << n << ": " << p2.abilities.at(i)->get_name();
							if (p2.abilities.at(i)->is_used == 0) {
								cout << " not used";
							}
							else {
								cout << " used";
							}
							cout << endl;
						}
					}
				}
				else if (command == "ability") {
					int which;
					ss >> which;
					if (which >= 6 || which <= 0) {
						cout << "Invalid ID!" << endl;
						string invalid;
						getline(cin, invalid);
						continue;
					}
					if (Player::p1_turn % 2 != 0) { // p1 turn
						if (p1.abilities.at(which - 1)->get_name() == "Firewall") {
							int y;
							int x;
							ss >> y;
							ss >> x;
							p1.apply(which, x, y);
						}
						else {

							char which_on_board;
							ss >> which_on_board;
							p1.apply(which_on_board, which);
						}
					}
					else { // p2 turn
						if (p2.abilities.at(which - 1)->get_name() == "Firewall") {
							int y;
							int x;
							ss >> y;
							ss >> x;
							p2.apply(which, x, y);
						}
						else {
							char which_on_board;
							ss >> which_on_board;
							p2.apply(which_on_board, which);
						}
					}
				}
				else if (command == "board") {
					cout << "Player 1:" << endl;
					cout << "Downloaded: " << p1.dlData << "D, " << p1.dlVirus << "V" << endl;
					cout << "Abilities: " << p1.nAbility << endl;

					if (Player::p1_turn % 2 != 0) { // p1 turn
						for (int i = 0; i <= 3; ++i) { // cout the info for p1
							cout << p1.links.at(i).name << ": " << p1.links.at(i).identity[0] << p1.links.at(i).strength << "   ";
						}
						cout << endl;
						for (int i = 4; i < 8; i++) {
							cout << p1.links.at(i).name << ": " << p1.links.at(i).identity[0] << p1.links.at(i).strength << "   ";
						}
						cout << endl;
						cout << g;
						cout << "Player 2:" << endl;
						cout << "Downloaded: " << p2.dlData << "D, " << p2.dlVirus << "V" << endl;
						cout << "Abilities: " << p2.nAbility << endl;

						for (int j = 0; j <= 3; ++j) {
							cout << p2.links.at(j).name << ": ";
							if (p2.links.at(j).is_revealed == 1) {
								cout << p2.links.at(j).identity[0] << p2.links.at(j).strength << "   ";
							}
							else {
								cout << "?   ";
							}
						}
						cout << endl;
						for (int j = 4; j < 8; j++) {
							cout << p2.links.at(j).name << ": ";
							if (p2.links.at(j).is_revealed == 1) {
								cout << p2.links.at(j).identity[0] << p2.links.at(j).strength << "   ";
							}
							else {
								cout << "?   ";
							}
						}
					}
					else { // p2 turn
						for (int j = 0; j <= 3; ++j) {
							cout << p1.links.at(j).name << ": ";
							if (p1.links.at(j).is_revealed == 1) {
								cout << p1.links.at(j).identity[0] << p1.links.at(j).strength << "   ";
							}
							else {
								cout << "?   ";
							}
						}
						cout << endl;
						for (int j = 4; j < 8; j++) {
							cout << p1.links.at(j).name << ": ";
							if (p1.links.at(j).is_revealed == 1) {
								cout << p1.links.at(j).identity[0] << p1.links.at(j).strength << "   ";
							}
							else {
								cout << "?   ";
							}
						}
						cout << endl;

						cout << g;

						cout << "Player 2:" << endl;
						cout << "Downloaded: " << p2.dlData << "D, " << p2.dlVirus << "V" << endl;
						cout << "Abilities: " << p2.nAbility << endl;

						for (int i = 0; i <= 3; ++i) { // cout the info for p1
							cout << p2.links.at(i).name << ": " << p2.links.at(i).identity[0] << p2.links.at(i).strength << "   ";
						}
						cout << endl;
						for (int i = 4; i < 8; i++) {
							cout << p2.links.at(i).name << ": " << p2.links.at(i).identity[0] << p2.links.at(i).strength << "   ";
						}


					}
					cout << endl;
				}
				else if (command == "quit") {
					return 0;
				}


			}




		}
		else if (s == "quit") {
			return 0;
		}
	}

}
