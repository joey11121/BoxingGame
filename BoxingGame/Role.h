#pragma once
#ifndef ROLE_H_INCLUDED
#define ROLE_H_INCLUDED
#define MAX_ENERGY 100
#define Gravity 5
#include "global.h"
const int step = 27; // The distance that the role walks at one time.
const int jump = 200; // The height that the role jumps

class Role
{
public:
	Role(int _hp, int _atk, int _def, int _dir, string _name);
	~Role();
	//get the characteristic and position of the role; 
	int getATK();
	int getHP();
	int getEnergy();
	int getDefense();
	int getX();
	int getY();
	int getAnime();
	int getAnime_Time();
	int getStatus();
	int getWidth();
	int getHeight();

	//Let the role do actions. 
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
	void attack_enermy(Role* Enemy);
	void defense_enermy();
	void release_ability();

	//Allegro繪圖
	void draw();
	void destory();
	void process(ALLEGRO_EVENT);
	void update(); //�ΨӧP�_��������

	

private:
	int x1, x2, y1, y2, dir; //Position and direction of role, direction 0 means left, direction 1 is right;
	int HealthPoint, Defense, AttackPower, Energy; //角色數值
	int rolestatus; //0 idle; Defend 1 ；Attack 2； Ability 3 
	string Name; 
	int anime, anime_time;
	int width, height;
	ALLEGRO_BITMAP* action[13][2]; //13種動作 * 左右兩個
};

#endif