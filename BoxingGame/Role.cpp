#include "Role.h"
#include "GameWindow.h"

Role::Role(int _hp, int _atk, int _def, int _dir, string _name) {
	HealthPoint = _hp;
	AttackPower = _atk;
	Defense = _def;
	Energy = 0;
	dir = _dir; //player 1的角色朝右(=1)，player2的角色朝左(=0)
	rolestatus = 1; 
	Name = _name;
}

int Role::getHP() {
	return HealthPoint;
}
int Role::getATK() {
	return AttackPower;
}
int Role:: getEnergy() {
	return Energy;
}
int Role::getDefense() {
	return Defense;
}

int Role::getWidth(int x2, x1) {
	return x2 - x1; 
}

int Role::getHeight(int y2, y1) {
	return y2 - y1;
}

//HP Control
bool Role::substractHP(int Harm_point) {
	HealthPoint -= Harm_point;
	if (rolestatus == 0) {
		HealthPoint -= (Harm_point - Defense);
	}
	else {
		HealthPoint -= Harm_point;
	}
	return (HealthPoint <= 0);
}

//Anger Control, Once the role hit the enemy, add 10; once the anger is 100, release ultimate ability. 
bool Role::increase_Energy() {
	Energy += 5;
	return (Energy == MAX_ENERGY);
}
void Role::reset_Energy() {
	Energy = 0;
};

//movement of the role, 橫向move兩者會一起改變, 縱向move依據跳、蹲有不同的結果
void Role::move_right() {
	if (dir == 0) dir = 1;
	if (x2 + step > win_width) {
		x1 = win_width - (x2 - x1);
		x2 = win_width;
	}
	else  {
		x1 += step; x2 += step;
	}
}

void Role::move_left() {
	if (dir == 1) dir = 0;
	if (x1 - step < 0) {
		x2 = 0 + (x2 - x1);
		x1 = 0;
	}
	else {
		x1 -= step; x2 -= step;
	}
}

//需要物理引擎
void Role::jump_up() {
	if (y1 - jump < 0) {
		y2 = 0 + (y2 - y1);
		y1 = 0;
	}
	else {
		y1 -= jump;
		y2 -= jump;
	}
}

void Role::squat_down() {
	y1 += (y2 - y1) / 2;
}

//按下某鍵作出防禦狀態，並且作出防禦動作
void Role::defense_enermy() {
	if (rolestatus != 1)
		rolestatus = 1;
	//呼叫防禦動作特效
	//防禦結束要變回idle。
}

//按下某鍵作出普通攻擊姿勢
void Role::attack_enermy(Role* Enemy) {
	if (rolestatus != 2)
		rolestatus = 2;
	//呼叫攻擊特效
	//攻擊結束要變回idle。
}
//Release ability once the role has full Energy
void Role::release_ability() {
	if (rolestatus != 3) {
		rolestatus = 3;
	}
	if (/*放技能成功*/) {
		reset_Energy();
	}
	//放技能狀態結束後變回idle。
}

