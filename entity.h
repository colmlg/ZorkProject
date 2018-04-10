#ifndef ENTITY_H
#define ENTITY_H


class Entity {
protected:
	int health;
	int attack;
public:
	virtual ~Entity();
	virtual int getAttack();
    int getHealth();
	void takeDamage(int amount);
	void heal(int amount);
};

#endif // ENTITY_H
