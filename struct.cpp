#include<string>

using namespace std;

//It stores Character Information
struct characterInfo {
	string characterName = "Player";
	string characterRank = "Warrior";
	int characterHealth = 100;
	int characterExp = 0;//Level points
	int exp = 0;//Global Exp points
};


//It stores quests
struct quests {
	string questsGold[10] = { "Gold +10 gram","Gold +12 gram",
	"Gold +14 gram", "Gold +16 gram", "Gold +17 gram", "Gold +18 gram",
		"Gold +19 gram", "Gold +20 gram", "Gold +23 gram", "Gold +25 gram"
	};


};

struct inventorySys {
	string weapons[5] = { "Sword", "Golden Sword", "Arrow", "Gun", "One Shot Gun"};

};

struct lvl1Enemy {
	int baby = 40;
	int adult = 50;
	int giant = 70;
};

struct levels {
	int lvl = 1;
};

struct lvl2Enemy {
	//Phoneix = 75
	int bennu = 50;
	int fenghuang = 60;
	int fireBird = 65;
	int huma = 75;
};

struct lvl3Enemy {
	int medusa = 65;
	int centaur = 70;
	int sphnix = 80;
	int roc = 95;
};

struct lvl4Enemy {
	int naga = 70;
	int tBird = 90;
	int tengue = 100;
	int valkyrie = 120;
};



