#pragma once
#ifndef ROLE_H_INCLUDED
#define ROLE_H_INCLUDED
#include "Object.h"
#include "Global.h"
#define MAX_ENERGY 100

const int step = 27; // The distance that the role walks at one time. 
const int jump = 300; // The height that the role jumps 


class Role : public Object
{
public:
	Role(int, int, int, string);
	virtual ~Role();
	//overide the virtual funciton Object::Draw()
	void Draw();
	void Load_Attack();
	void Load_Move();
	void Load_Ult();
	//Detect if it move to the edge of window.
	bool move();

	//Detect if the HP is 0 after substraction. 
	bool substract_HP(int); 

	//If the attack is hit successfully, the energy will increase. If the energy is 100, the role can release the ultimate ability. 
	//Detect if the energy is full to 100.
	bool increase_Energy(); 
	void reset_Energy();
protected:
	int HealthPoint, Defence, AttackPower, Energy; //角色數值 
	int x1, y1, x2, y2, dir; //Position and direction of role
	string Name;

private:

};

#endif
