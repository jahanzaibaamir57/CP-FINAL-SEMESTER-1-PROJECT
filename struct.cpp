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
	int medusa = 50;
	int centaur = 60;
	int sphnix = 65;
	int roc = 75;
};


//
//struct Weapon {
//    string name;
//    string category;
//    int damage;
//    double fireRate;
//    int magazineSize;
//    Weapon(const string& n, const string& cat, int dmg, double rate, int magSize) : name(n), category(cat), damage(dmg), fireRate(rate), magazineSize(magSize) {}
//};
//int main() {
//    Weapon m416(" M416 ", " Assault Rifle", 41, 0.086, 30);
//    Weapon akm(" AKM ", " Assault Rifle", 49, 0.1, 30);
//    Weapon kar98k(" Kar98k ", " Sniper Rifle", 75, 1.9, 5);
//    Weapon pan(" Pan ", " Melee ", 80, 0, 0);
//    Weapon m762(" M762 ", " Assault Rifle ", 47, 0.086, 30);
//    Weapon awm(" AWM ", " Sniper Rifle ", 105, 1.85, 5);
//    Weapon s12k(" S12K ", " Shotgun ", 22, 0.25, 5);
//    Weapon ump45(" Ump45 ", " Smg ", 26, 0.045, 25);
//
//    vector<Weapon> pubgWeapons;
//    pubgWeapons.push_back(m416);
//    pubgWeapons.push_back(akm);
//    pubgWeapons.push_back(kar98k);
//    pubgWeapons.push_back(pan);
//    pubgWeapons.push_back(m762);
//    pubgWeapons.push_back(awm);
//    pubgWeapons.push_back(s12k);
//    pubgWeapons.push_back(ump45);
//}
