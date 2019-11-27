#ifndef ABILITY_H
#define ABILITY_H
#include <iostream>
#include <string>

class GameManager;

class Link;

class Ability {
protected:
	GameManager gm;
public:
	virtual string get_name() = 0;
	Ability(GameManager gm);
	virtual void notify(Link l, GameManager& gm) = 0;
};

class LinkBoost : public Ability {
	static int times;
	
public:
	string get_name() override;
	void notify(Link l, GameManager& gm) override;
	void apply(Link& l);
};

class Firewall : public Ability {
	static int times;
	
public:
	string get_name() override;

};

class Download : public Ability {
	static int times;
	
public:
	string get_name() override;
	void notify(Link l, GameManager& gm) override;
	void apply(Link& l);
};

class Polarize : public Ability {
	static int times;
	
public:
	string get_name() override;
	void notify(Link l, GameManager& gm) override;
	void apply(Link& l);
};

class Scan : public Ability {
	static int times;

public:
	string get_name() override;
	void notify(Link l, GameManager& gm) override;
	void apply(Link& l);
};




#endif


