#ifndef UNITS_H
#define UNITS_H

class Units
{
private:
	int Attack;
	int Defense;

public:
	int Cost;

	Units(int argAttack, int argDefense, int Cost);
	~Units();
};

#endif