#include "Role.h"

Role::Role(int _hp, int _atk, int _def, string _name) {
	HealthPoint = _hp;
	Defence = _def;
	AttackPower = _atk;
	Energy = 0;
	Name = _name;
}
void Role::Load_Attack() {

	return;
}
void Role::Load_Move() {
	return;
}
void Role::Load_Ult() {
	return;
}

//HP Control
bool Role::substract_HP(int harm_point) {
	HealthPoint -= (harm_point - Defence);
	return (HealthPoint <= 0);
}

//Energy Control
bool Role::increase_Energy() {
	Energy += 10;
	if (Energy == MAX_ENERGY)
		return true;
	return false;
}
void Role::reset_Energy() {
	Energy = 0;
	return;
}