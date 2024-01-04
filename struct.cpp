#include<string>
using namespace std;
//It stores Character Information
struct characterInfo {
	string characterName = "Default Player";
	string characterRank = "Warrior";
	int characterHealth = 100;
	int characterExp = 0;//Level exp points which will be reset in every level
	int exp = 0;//total Exp points
};


struct inventorySys {
	string weapons[5] = {};//Weapons that are unlocked
	string lockedWeapons[5] = { "Sword", "Golden Sword", "Arrow", "Gun", "One Shot Gun" };//Weapons which are locked

};


//Health of Level 1 Enemies
struct lvl1Enemy {
	int baby = 40;			//Enemy 1 baby dragon whose health is 40
	int adult = 50;			//Enemy 2 adult dragon whose health is 50
	int giant = 70;			//Enemy 3 giant dragon whose healht is 70
};


//Level
struct levels {
	short int lvl = 1;
};


//Health of level 2 Enemies
struct lvl2Enemy {
	int bennu = 50;			//Enemy 1 bennu phoneix whose health is 50 points 
	int fenghuang = 60;		//Enemy 2 fenghuang phoneix whose health is 60 points
	int fireBird = 65;		//Enemy 3 fireBird phoneix whose health is 65 points
	int huma = 75;			//Enemy 4 huma phoneix whose health is 75 points
};


//Health of level 3 Enemies
struct lvl3Enemy {
	int naga = 70;			//Enemy 1 naga whose health is 70 points
	int tBird = 90;			//Enemy 2 tBird whose health is 90 points
	int tengue = 100;		//Enemy 3 tengue whose health is 100 points
	int valkyrie = 120;		//Enemy 4 valkyrie whose health is 120 points
};



