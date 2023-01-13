#pragma once
#pragma once
#ifndef ROLE_H_INCLUDED
#define ROLE_H_INCLUDED
#define MAX_ENERGY 100
#include <string>

using namespace std;

const int step = 27; // The distance that the role walks at one time. 
const int jump = 200; // The height that the role jumps 


class Role
{
public:
	Role(int _hp, int _atk, int _def, int _dir, string _name);
	virtual ~Role();
	//取得生命值，攻擊力，怒氣值
	int getATK();
	int getHP();
	int getEnergy();
	int getDefense();

	//movement of the role:
	void move_right();
	void move_left();
	void jump_up();
	void squat_down(); 

	//Detect if the HP is 0 after substraction. 
	bool substractHP(int);

	//If the attack is hit successfully, the energy will increase. If the energy is 100, the role can release the ultimate ability. 
	//Detect if the energy is full to 100.
	bool increase_Energy();
	void reset_Energy();
	//Movement, x_move is to move on the x_axis, y_move is to move on the y_axis. 
	
	//攻擊對手、防禦對手、放技能
	void attack_enermy(Role *Enemy);
	void defense_enermy();
	void release_ability();
	
private:
	int HealthPoint, AttackPower, Energy, Defense; //角色數值 
	int x1, x2, y1, y2, dir; //Position and direction of role, direction 0 means left, direction 1 is right;
	string Name;
	int rolestatus; //0代表idle、1代表防禦狀態、2代表攻擊狀態、3放技能狀態
};

#endif