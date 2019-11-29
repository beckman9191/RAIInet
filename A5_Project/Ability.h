#ifndef ABILITY_H
#define ABILITY_H
#include <iostream>
#include <string>



class Link;

class Ability {

public:
	bool is_used = 0;
	virtual std::string get_name() = 0;
	Ability();
	virtual void apply(Link& l) = 0;
	
};

class LinkBoost : public Ability {
	
	
public:
	bool is_used = 0;
	static int p1_t;
	static int p2_t;
	std::string get_name() override;
	
	void apply(Link& l) override;
};

class Firewall : public Ability {
	
	
public:
	bool is_used = 0;
	static int p1_t;
	static int p2_t;
	std::string get_name() override;
	void apply(Link& l) override;

};

class Download : public Ability {
	
	
public:
	bool is_used = 0;
	static int p1_t;
	static int p2_t;
	std::string get_name() override;
	
	void apply(Link& l) override;
};

class Polarize : public Ability {
	
	
public:
	bool is_used = 0;
	static int p1_t;
	static int p2_t;
	std::string get_name() override;
	
	void apply(Link& l) override;
};

class Scan : public Ability {
	

public:
	bool is_used = 0;
	static int p1_t;
	static int p2_t;
	std::string get_name() override;
	
	void apply(Link& l) override;
};




#endif


