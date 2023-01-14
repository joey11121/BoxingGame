#define ALLEGRO_NO_MAGIC_MAIN
#include<windows.h>
#include<allegro5/allegro.h>

//初始化鍵盤與滑鼠
bool al_install_mouse(void); 
bool al_install_keyboard(void);

//Create a display：
ALLEGRO_DISPLAY* al_create_display(int w, int h);
al_set_window_title(display, "Hello World")

//Select roles or scenes
selectedRole = menu->MouseIn(mouse_x, mouse_y);
selectedScenes = menu->MouseIn(mouse_x, mouse_y);

//儲存兩人的人物選擇、血量、怒氣
int role_index[2], choice[2]; 
int health[2] = { 0 };
int power[2] = { 0 }; 

//選擇腳色
#define Num_RoleType 5
#include "Menu.h"

const int ThumbWidth = 50;
const int ThumbHeight = 50;
const int gapX = 40, gapY = 30;
const int offsetX = 30 + field_width, offsetY = 150;

//
bool
Menu::isInRange(int point, int startPos, int length)
{
    if (point >= startPos && point <= startPos + length)
        return true;

    return false;
}

int Menu::RoleMouseIn(int mouse_x, int mouse_y)
{
    selectedRole = -1;
    for (int i = 0; i < Num_RoleType; i++)
    {
        int pos_x = offsetX + (ThumbWidth + gapX) * (i % 2);
        int pos_y = offsetY + (ThumbHeight + gapY) * (i / 2);

        if (isInRange(mouse_x, pos_x, ThumbWidth) && isInRange(mouse_y, pos_y, ThumbHeight))
        {
            selectedRole = i;
        }
    }
    return selectedRole;
}

//創建角色，Role class
Role role1; //玩家一的角色
Role role2; //玩家二的角色

//overide the virtual funciton Object::Draw()
void Draw();
void Load_Attack();
void Load_Move();
void Load_Ult();
void Role::Load_Attack() {
    return;
}
void Role::Load_Move() {
    return;
}
void Role::Load_Ult() {
    return;
}

//Detect if the role's attack is successful. 
if (/*成功攻擊到敵人*/) {
    Enemy->substractHP(AttackPower);
    increase_Energy();
}



//判定人物是否被碰觸
bool IsTouch()
{

    if (role1.r >= role2.l && role1.dir == 0 && role1.x < role2.x) return true;
    if (role2.r >= role1.l && role2.dir == 0 && role2.x < role1.x) return true;
    if (role1.l <= role2.r && role1.dir == 1 && role1.x > role2.x) return true;
    if (role2.l <= role1.r && role2.dir == 1 && role2.x > role1.x) return true;

    return false;
}

//setgamestats;
void SetGameStatus(int val)
{
	int i;
	gamestatus = val;
	switch (val)
	{
	case 0:

		break;
	case 1:
		bgdemo.index = 0;
		break;
	case 2:
		bg.index = bgdemo.index;
		choice[0] = choice[1] = -1;
		role_index[0] = role_index[1] = 2;
		for (i = 0; i < 5; i++)
		{
			role[i].set(10);
			role[i].set(width / 5 * i + width / 10, height / 2);
		}
		break;
	case 3:

		bg.index = bgdemo.index;
		role1 = role[role_index[0]];
		role2 = role[role_index[1]];

		role1.angry = role2.angry = 0;
		health[0] = health[1] = total_health;
		power[0] = power[1] = 0;
		role1.dir = 0;
		role2.dir = 1;
		role1.x = client.cx / 10;
		role2.x = client.cx * 4 / 5 + client.cx / 10;

		role1.set(10);
		role2.set(10);

		spec1.index = spec2.index = -1;
		spec1.num = spec2.num = 0;

		break;
	case 4:

		if (health[0] < 0)
		{
			role1.set(1);
			role2.set(10);
		}
		else
		{
			role1.set(10);
			role2.set(1);
		}
		ko.index = 0;
		break;
	default:
		break;
	}
}

//儲存人物的動作
ALLEGRO_BITMAP* hbm[13][2];

//KO sound
DeathSample = al_load_sample("./sound/ko.wav");//ko音效，KOF97
DeathSampleInstance = al_create_sample_instance(DeathSample);
al_set_sample_instance_playmode(DeathSampleInstance, ALLEGRO_PLAYMODE_ONCE);
al_attach_sample_instance_to_mixer(DeathSampleInstance, al_get_default_mixer());
// initialize the menu before entering the loop

//Game fighting sound
FightingSample = al_load_sample("./sound/fighting.mp3");//ko音效，KOF97
FightingSampleInstance = al_create_sample_instance(FightingSample);
al_set_sample_instance_playmode(FightingSampleInstance, ALLEGRO_PLAYMODE_ONCE);
al_attach_sample_instance_to_mixer(FightingSampleInstance, al_get_default_mixer());

