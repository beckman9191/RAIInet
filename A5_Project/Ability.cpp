#include <string>
#include "Ability.h"
#include "Link.h"
#include "GameManager.h"

using namespace std;



/******************* Ability *******************/
Ability::Ability() {}


/******************* Link Boost *******************/
string LinkBoost::get_name() {
	return "Linkboost";
}


void LinkBoost::apply(Link& l) {
	l.is_boost++;
	
	
}


/******************* FireWall *******************/
string Firewall::get_name() {
	return "Firewall";
}

void apply(Link& l) {
}



/******************* Download *******************/
string Download::get_name() {
	return "Download";
}



void Download::apply(Link& l) {
	l.is_revealed = 1;
	l.is_alive = 0;
	l.x = 10;
	l.y = 10;
	
}


/******************* Polarize *******************/
string Polarize::get_name() {
	return "Polarize";
}



void Polarize::apply(Link& l) {
	if (l.identity == "Virus") {
		l.identity = "Data";
	}
	else {
		l.identity = "Virus";
	}
	
}

/******************* Scan *******************/
string Scan::get_name() {
	return "Scan";
}



void Scan::apply(Link& l) {
	l.is_revealed = 1;
	
}
