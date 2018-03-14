#ifndef ENTITY_H
#define ENTITY_H


class Entity {
protected:
	int health;
	int attack;
public:
	int getAttack();
	int getHealth();
	void takeDamage(int amount);
	void heal(int amount);
	virtual int dealDamage() = 0;
};

#endif // ENTITY_H
