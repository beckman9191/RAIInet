#include <string>
#include "Ability.h"
#include "Link.h"
#include "GameManager.h"

using namespace std;

int LinkBoost::times = 0;
int Firewall::times = 0;
int Download::times = 0;
int Polarize::times = 0;
int Scan::times = 0;

/******************* Ability *******************/
Ability::Ability(GameManager gm) : gm{ gm } {}


/******************* Link Boost *******************/
string LinkBoost::get_name() {
	return "Linkboost";
}

void LinkBoost::notify(Link l, GameManager& gm)  {
	gm.notify_boost(l);

}
void LinkBoost::apply(Link& l) {
	l.is_boost++;
	notify(l, gm);
	
}


/******************* FireWall *******************/
string Firewall::get_name() {
	return "Firewall";
}



/******************* Download *******************/
string Download::get_name() {
	return "Download";
}

void Download::notify(Link l, GameManager& gm) {
	gm.notify_download(l);

}

void Download::apply(Link& l) {
	l.is_alive = false;
	l.x = 10;
	l.y = 10;
	notify(l, gm);
}


/******************* Polarize *******************/
string Polarize::get_name() {
	return "Polarize";
}

void Polarize::notify(Link l, GameManager& gm) {
	gm.notify_polarize(l);

}

void Polarize::apply(Link& l) {
	if (l.identity == "Virus") {
		l.identity = "Data";
	}
	else {
		l.identity = "Virus";
	}
	notify(l, gm);
}

/******************* Scan *******************/
string Scan::get_name() {
	return "Scan";
}

void Scan::notify(Link l, GameManager& gm) {
	gm.notify_scan(l);

}

void Scan::apply(Link& l) {
	l.is_revealed = true;
	notify(l, gm);
}
