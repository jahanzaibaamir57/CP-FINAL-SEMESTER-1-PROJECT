#include<iostream>
#include<string>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include"struct.cpp" //struct.cpp stores all strutures of the program

#pragma comment(lib, "winmm.lib") //This library is for playing music



using namespace std;



//struct defined in struct.cpp
//struct datatypes
characterInfo character;
quests quest;
inventorySys invent;
levels level;
lvl1Enemy dragon;
lvl2Enemy phoneix;
lvl3Enemy lvl3E;
lvl4Enemy lvl4E;




void startGame();
void exitGame();
void character1();
void inventry();
void charInfo(int& hlth, int& exp, int&enehlth);
int classChar(string cls);
void selevel();

void lvl1();
void lvl1GDragon();
void lvl1ADragon();
void lvl1BDragon();

void lvl2();
void lvl2Bennu();
void lvl2feng();
void lvl2fire();
void lvl2huma();

void lvl3();
void lvl3medusa();
void lvl3centaur();
void lvl3sphinx();
void lvl3roc();

void lvl4();
void lvl4naga();
void lvl4tBird();
void lvl4tengue();
void lvl4valkyrie();


int main() {
	
	PlaySound(TEXT("back.wav"), NULL,  SND_ASYNC);
	
	string welcome = "\tWelcome to MythicVenture: A Hero's Quest\n";
	for (int i = 0; i < welcome.length(); i++){
		cout << welcome[i];
		Sleep(70);
	}
		
	
	startGame();
}

//Exit Game function
void exitGame() {
	cout << "\n\n\n\tGame Exited";

}

//Main menu
void startGame() {

	string mainMenuSelection;
	int clear = 0;
	
	do {
		if (clear == 1)
			system("cls");
		else
			clear = 1;

		cout << "\n\t\tMain Menu\n\t1. Start Game\n\t2. Inventry\n\t3. Characters\n\t4. Exit\n\tEnter your choice: ";
		cin >> mainMenuSelection;

		if (mainMenuSelection == "1") {
			selevel();
			break;
		}
		else if (mainMenuSelection == "2") {
			inventry();
			break;
		}
		else if (mainMenuSelection == "3") {
			character1();
			break;
		}
		else if (mainMenuSelection == "4") {
			exitGame();
			break;
		}

	} while (mainMenuSelection != "1" || mainMenuSelection != "2" || mainMenuSelection != "3" || mainMenuSelection != "4");

}


//This function is for making characters, view characters
void character1() {
	system("cls");
	string select;
	cout << "\n\t1. Create a character\n\t2. View Character\n\t3. Exit Game\n\t4. Main Menu\n\tYour choice: ";
	cin >> select;

	bool classCheck = true;
	string classCheckNum;
	

	

	if (select == "1")
	{
		
		cout << "\n\tEnter Character Name: ";
		cin >> character.characterName;
		
		
		while (classCheck)
		{
			cout << "\n\tEnter Character Class \n\t1.Warrior\t(Damage 1-15) \n\t2.Mage \t\t(Damage 16-20) \n\t3.Rogue\t\t(Damage 20-30)\n\tSelect Class: ";
			cin >> classCheckNum;
			
			if (classCheckNum == "1") {
				character.characterRank = "Warrior";
				
				break;
			}
			else if (classCheckNum == "2") {
				character.characterRank = "Mage";
				
				break;

			}
			else if (classCheckNum == "3") {
				character.characterRank = "Rogue";
				
				break;
			}
			else {
				cout << "\n\tYou have entered incorrect Class";
				classCheck = true;
			}
		}

		cout << "\n\tCharacter Name  :\t" << character.characterName;
		cout << "\n\tCharacter Class :\t" << character.characterRank << endl;

		cout << "\n\n\tCharacter Created\n\n";
		system("pause");
		character1();

	}
	else if (select == "2") {
		cout << "\n\tCharacter Name  :\t" << character.characterName;
		cout << "\n\tCharacter Class :\t" << character.characterRank << endl;
		system("pause");
		character1();
	}
	else if (select == "3") {
		exitGame();
	}
	else if (select == "4") {
		system("cls");
		startGame();
	}

	else {
		cout << "You have entered incorrect choice" << endl;
		character1();
	}

}

//Display Character Information
void charInfo(int& hlth, int& exp, int&eneHlth) {
	character.characterHealth -= hlth;

	if (character.characterHealth <= 0) character.characterHealth = 0;
	if (eneHlth <= 0) eneHlth = 0;
		
		string details= "\n\n\tPlayer Name:\t" + character.characterName + "\n\tPlayer Class:\t" + character.characterRank + "\n\tHealth:\t\t" + to_string(character.characterHealth) + "\n\tExp Points:\t" + to_string(character.characterExp) + "\n\n\tEnemy Health: " + to_string(eneHlth) ;
		for (int i = 0; i < details.length(); i++) {
			cout <<details[i];
			Sleep(30);
		}
}

//This function takes character class and return player attack points
int classChar(string cls) {

	int max, min;

	srand(time(0));

	
	if (cls == "Warrior") {
		//Attack max 15
		max = 15;
		min = 1;
		return rand() % (max - min + 1) + min;
	}
	else if (cls == "Mage") {
		//Attack max 20
		max = 20;
		min = 15;
		return rand() % (max - min + 1) + min;
	}
	else if (cls == "Rogue") {
		//Attack max 30
		max = 30;
		min = 20;
		return rand() % (max - min + 1) + min;
	}
}


//Inventry
void inventry() {
	system("cls");
	int select;
	cout << "\n\tHere are all weapons";
	for (int i = 0; i < size(invent.weapons); i++) {
		cout << "\n\tLocked " << i + 1 << " " << invent.weapons[i];
		cout << endl;
	}
	cout << "\n\t1. Main menu\n\t2. Exit Game\n\tEnter Option: ";
	cin >> select;

	if (select == 1) {
		system("cls");
		startGame();
	}
	else if (select == 2) {
		exitGame();
	}


}

//Select Level
void selevel() {
	string option;
	system("cls");
	do
	{
		cout << "\n\tSelect Level to start Game\n\n";
		for (int i = 1; i <= level.lvl; i++) {
			cout << "\n\t"<<i << ". level " << i << endl;
		}
		cout << "\n\t0.  Main Menu";
		cout << "\n\t99. Exit Game";
		cout << "\n\tChoose option: ";
		cin >> option;
		if (option == "0") { 
			system("cls");
			startGame(); 
		}
		else if (option == "99") { 
			 
			exitGame();
		}
		else if(level.lvl == 1){
				if (option == "1") lvl1();
	
				else {
					system("cls");
					cout << "\n\tInvalid Choice";
					continue;
				}
		}
		else if (level.lvl == 2) {
			if (option == "1") lvl1();
			else if (option == "2") lvl2();

			else {
				system("cls");
				cout << "\n\tInvalid Choice";
				continue;
			}

		}
		else if (level.lvl == 3) {
			if (option == "1") lvl1();
			else if (option == "2") lvl2();
			else if (option == "3") lvl3();
			else {
				system("cls");
				cout << "\n\tInvalid Choice";
				continue;
			}
		}
		else if (level.lvl == 4) {
			if (option == "1") lvl1();
			else if (option == "2") lvl2();
			else if (option == "3") lvl3();
			else if (option == "4") lvl4();
			else {
				system("cls");
				cout << "\n\tInvalid Choice";
				continue;
			}
		}
		break;
	} while (true);
	
}


//Level1 Dragon
void lvl1() {
	system("cls");
	string choose;
	srand(time(0));
	string startingMessage = "\n\tPlayer Name:\t" + character.characterName + " \n\tPlayer Class:\t"+character.characterRank+ "\n\tPlayer Health:\t" + to_string(character.characterHealth) + 
				"\n\tPlayer exp:\t"+to_string(character.characterExp) + 
				" \n\n\tGame Started\n\n\tIn the mystical land of Eldoria,\n\ta once-harmonious kingdom faces turmoil as an ancient curse unleashes mythical creatures"+
				"\n\tand dark forces upon the realm.\n\tAs chaos ensues, a valiant adventurer, recognized for their prowess, is called upon by the wise oracle.\n\n\tPress Enter to Continue Game...";

		for (int i = 0; i < startingMessage.length(); i++) {
			cout << startingMessage[i];
			Sleep(20);
		}
		cin.get();
		cin.ignore();
		string selectWays;
		do
		{
			cout << "\n\n\tThere are 3 Unknown ways\n\tSelect b/w 1 to 3: ";
			
			cin >> selectWays;
			if (selectWays == "1" || selectWays == "2" || selectWays == "3") {
				int randWay = rand() % 3 + 1;
				if (randWay == 1) {
					//Baby Dragon
					
					lvl1BDragon();
				}
				else if(randWay ==2){
					//Adult Dragon
					lvl1ADragon();
				}
				else {
					//Giant Dragon
					lvl1GDragon();

				}
				break;
			}
			else {
				system("cls");
				cout << "\n\tInvalid Selection";
			}
		} while (selectWays != "1" || selectWays != "2" || selectWays != "3");
		
}

// BabyDragon
void lvl1BDragon() {
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Baby Dragon";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {

			cout << "\n\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				dragon.baby = dragon.baby - b;
				cout << "\n\tYou attacked " << b << " points";
				a = 0;
				charInfo(a, b,dragon.baby);
				if (dragon.baby <= 0) {
					dragon.baby = 40;
					character.characterExp += 5;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					cout << "\n\n\tCongratulatoins\n\tBaby Dragon Died and you have earned 5 Exp points.\n";
					character.characterExp += 5;
					system("pause");
					system("cls");
					do
					{

						cout << "\n\n\tThere are 2 Unknown ways\n\tSelect b/w 1 to 2: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2") {
							int randWay = rand() % 2 + 1;
							if (randWay == 1) {
								//Adult Dragon
								lvl1ADragon();
							}
							else if (randWay == 2) {
								//Giant Dragon
								lvl1GDragon();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2");
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tBaby Dragon turn, Dragon is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 10 + 1;
			cout << "\n\tBaby Dragon attacked " << a << " points\n\t";

			charInfo(a, b,dragon.baby);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}

//Adult Dragon
void lvl1ADragon() {
	int a = 0, b = 0, i = 0;
	string choose;
	cout << "\n\tNow here is Adult Dragon";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				dragon.adult = dragon.adult - b;
				cout << "\n\tYou attacked " << b << " points";
				a = 0;
				charInfo(a, b,dragon.adult);
				if (dragon.adult <= 0) {
					dragon.adult = 50;
					character.characterExp += 8;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					cout << "\n\n\tCongratulatoins\n\tAdult Dragon Died.\n\tYou have earned 8 exp points\n";
					system("pause");
					lvl1GDragon();
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tAdult Dragon turn, Dragon is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 15 + 1;//Enemy Max attack points
			cout << "\n\tAdult Dragon attacked " << a << " points\n\t";

			charInfo(a, b,dragon.adult);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}

//Giant Dragon
void lvl1GDragon() {
	int a = 0, b = 0, i = 0;
	string choose;
	cout << "\n\tOh, Here is Giant Dragon";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {

			cout << "\n\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				dragon.giant = dragon.giant - b;
				cout << "\n\tYou attacked " << b << " points";
				a = 0;
				charInfo(a, b,dragon.giant);
				if (dragon.giant <= 0) {
					dragon.giant = 70;
					character.characterExp += 10;

					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					level.lvl++;
					cout << "\n\n\tCongratulatoins\n\tGiant Dragon Died\n\tYou have earned 10 Exp points\n\tyou have completed Level 1.\n";
					system("pause");
					selevel();
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tGiant Dragon turn, Dragon is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 25 + 1;//Enemy max attack points 25
			cout << "\n\tGiant Dragon attacked " << a << " points\n\t";

			charInfo(a, b,dragon.giant);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}


//Level2
void lvl2() {

	int a = 0, b = 0;
	character.characterHealth = 100;
	system("cls");
	srand(time(0));
	string startingMessage = "\n\tPlayer Name:\t" + character.characterName + " \n\tPlayer Class:\t" + character.characterRank + "\n\tPlayer Health:\t" + to_string(character.characterHealth) +
		"\n\tPlayer exp:\t" + to_string(character.characterExp) +
		" \n\n\tGame Started\n\n\tDisturbed by recent events, \nthe Crystal Wyvern flees to the Skyward Archipelago. \nMounted on a magical flying creature, the adventurer soars through the skies to confront the wyvern in its crystalline nest.\nAerial challenges and airborne adversaries test the adventurer's skill in retrieving the shard of the hidden crystal.\n\n\tPress Enter to Continue Game...";

	for (int i = 0; i < startingMessage.length(); i++) {
		cout << startingMessage[i];
		Sleep(20);
	}
	cin.get();
	cin.ignore();
	
	string selectWays;
	do
	{
		cout << "\n\n\tThere are 4 Unknown ways\n\tSelect b/w 1 to 4: ";

		cin >> selectWays;
		if (selectWays == "1" || selectWays == "2" || selectWays == "3" || selectWays == "4") {
			int randWay = rand() % 4 + 1;
			if (randWay == 1) {
				//Bennu Phoneix
				lvl2Bennu();
			}
			else if (randWay == 2) {
				//Feng Phoneix
				lvl2feng();
			}
			else if (randWay == 3) {
				//Fire Phoneix
				lvl2fire();
			}
			else {
				//Huma Phoneix
				lvl2huma();
			}
			break;
		}
		else {
			system("cls");
			cout << "\n\tInvalid Selection";
		}
	} while (selectWays != "1" || selectWays != "2" || selectWays != "3" || selectWays !="4");
}

void lvl2Bennu() {
	int a = 0, b = 0, i = 0;
	string choose,selectWays;
	cout << "\n\tHere is Bennu Phoneix";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.bennu -= b;
				cout << "\n\tYou attacked " << b << " points";
				a = 0;
				charInfo(a, b, phoneix.bennu);
				if (phoneix.bennu <= 0) {
					phoneix.bennu = 70;
					character.characterExp += 10;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					level.lvl++;
					cout << "\n\n\tCongratulatoins\n\tBennu Phoneix Died\n\tYou have earned 10 Exp Points.\n";
					system("pause");
					do
					{

						cout << "\n\n\tThere are 3 Unknown ways\n\tSelect b/w 1 to 3: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2" || selectWays == "3") {
							int randWay = rand() % 3 + 1;
							if (randWay == 1) {
								//Feng Phoneix
								lvl2feng();
							}
							else if (randWay == 2) {
								//Fire Phoneix
								lvl2fire();
							}
							else if (randWay == 3) {
								//Huma Phoneix
								lvl2huma();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2");
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tBennu Phoneix turn, Bennu is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 15 + 1; //Enemy attacked points, max 15
			cout << "\n\tBennu Phoneix attacked " << a << " points\n\t";

			charInfo(a, b,phoneix.bennu);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}
void lvl2feng() {
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Fenghung Phoneix";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			cin.ignore();
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.fenghuang -= b;
				cout << "\n\tYou attacked " << b << " points";
				charInfo(a, b,phoneix.fenghuang);
				if (phoneix.fenghuang <= 0) {
					phoneix.fenghuang = 60;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 12;
					cout << "\n\n\tCongratulatoins\n\tFenghung Phoneix Died\n\tYou have earned 12 Points\n";
					system("pause");
					do
					{

						cout << "\n\n\tThere are 2 Unknown ways\n\tSelect between 1 to 2: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2") {
							int randWay = rand() % 2 + 1;
							if (randWay == 1) {
								//Fire Phoneix
								lvl2fire();
							}
							else if (randWay == 2) {
								//Huma Phoneix
								lvl2huma();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2" );
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tFenghung Phoneix turn, Fenghung is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tFenghung Phoneix attacked " << a << " points\n\t";

			charInfo(a, b,phoneix.fenghuang);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}
void lvl2fire() {
	cout << "\n\tHere is Firebird Phoneix";
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.fireBird -= b;
				cout << "\n\tYou attacked " << b << " points";
				charInfo(a, b,phoneix.fireBird);
				if (phoneix.fireBird <= 0) {
					phoneix.fireBird = 65;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 13;
					cout << "\n\n\tCongratulatoins\n\tFireBird Phoneix Died\n\tYou have earned 13 Exp Points\n";
					system("pause");
					lvl2huma();
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tFenghung Phoneix turn, Fenghung is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tFenghung Phoneix attacked " << a << " points\n\t";

			charInfo(a, b,phoneix.fireBird);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}
void lvl2huma() {
	cout << "\n\tOpps, Here is Huma Phoneix";
	int a = 0, b = 0, i = 0;
	string choose;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.huma -= b;
				cout << "\n\tYou attacked " << b << " points";
				charInfo(a, b,phoneix.huma);
				if (phoneix.huma <= 0) {
					phoneix.huma = 75;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 15;
					level.lvl++;
					cout << "\n\n\tCongratulatoins\n\tHuma Phoneix Died\n\tYou have earned 15 Exp Points\n";
					system("pause");
					selevel();
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tHuma Phoneix turn, Huma is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tHuma Phoneix attacked " << a << " points\n\t";

			charInfo(a, b, phoneix.huma);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}

//Level3
void lvl3() {
	/*
		Route ** Medusa --> Centaur --> Sphinx --> Roc
		Medusa ------>
				|
				|
				|----> Centaur
				|
				|---->Sphinx
				|
				|__/->Roc
		void lvl3medusa();
		void lvl3centaur();
		void lvl3sphinx();
		void lvl3roc();
	*/
}

void lvl3medusa() {
	
}

void lvl3centaur(){
	
}

void lvl3sphinx(){
	
}

void lvl3roc(){
	
}



//Level4
void lvl4() {
	/*
		Route ** Naga --> ThunderBird --> Tengu --> Valkyrie


	*/
	int a = 0, b = 0;
	character.characterHealth = 100;
	system("cls");
	srand(time(0));
	string startingMessage = "\n\tPlayer Name:\t" + character.characterName + " \n\tPlayer Class:\t" + character.characterRank + "\n\tPlayer Health:\t" + to_string(character.characterHealth) +
		"\n\tPlayer exp:\t" + to_string(character.characterExp) +
		" \n\n\tGame Started\n\n\tA cosmic portal appears in the Enchanted Forest, leading to the Astral Nexus. The adventurer explores this dimension, solving celestial puzzles and gaining the favor of astral entities. Discovering the rogue sorcerers' plan to manipulate time, the adventurer must safeguard a cosmic artifact from falling into the wrong hands.\n\n\tPress Enter to Continue Game...";

	for (int i = 0; i < startingMessage.length(); i++) {
		cout << startingMessage[i];
		Sleep(20);
	}
	cin.get();
	cin.ignore();

	string selectWays;
	do
	{
		cout << "\n\n\tThere are 4 Unknown ways\n\tSelect b/w 1 to 4: ";

		cin >> selectWays;
		if (selectWays == "1" || selectWays == "2" || selectWays == "3" || selectWays == "4") {
			int randWay = rand() % 4 + 1;
			if (randWay == 1) {
				//Naga
				lvl4naga();
			}
			else if (randWay == 2) {
				//Thunder Bird
				lvl4tBird();
			}
			else if (randWay == 3) {
				//Tengue
				lvl4tengue();
			}
			else {
				//Valkyrie
				lvl4valkyrie();
			}
			break;
		}
		else {
			system("cls");
			cout << "\n\tInvalid Selection";
		}
	} while (selectWays != "1" || selectWays != "2" || selectWays != "3" || selectWays != "4");

	
}

void lvl4naga(){
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Naga";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl4E.naga -= b;
				cout << "\n\tYou attacked " << b << " points";
				a = 0;
				charInfo(a, b,lvl4E.naga);
				if (lvl4E.naga <= 0) {
					lvl4E.naga = 70;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 10;
					cout << "\n\n\tCongratulatoins\n\tNaga Died\n\tYou have earned 10 Exp Points.\n";
					system("pause");
					do
					{

						cout << "\n\n\tThere are 3 Unknown ways\n\tSelect between 1 to 3: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2" || selectWays == "3") {
							int randWay = rand() % 3 + 1;
							if (randWay == 1) {
								//Thunder Bird
								lvl4tBird();
							}
							else if (randWay == 2) {
								//Tengue
								lvl4tengue();
							}
							else if (randWay == 3) {
								//Valkyrie
								lvl4valkyrie();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2"||selectWays !="3");
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tNaga turn, Naga is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 15 + 1; //Enemy attacked points, max 15
			cout << "\n\tNaga attacked " << a << " points\n\t";

			charInfo(a, b, lvl4E.naga);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}
void lvl4tBird(){
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Thunder Bird";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			cin.ignore();
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl4E.tBird -= b;
				cout << "\n\tYou attacked " << b << " points";
				charInfo(a, b,lvl4E.tBird);
				if (lvl4E.tBird <= 0) {
					lvl4E.tBird = 90;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 12;
					cout << "\n\n\tCongratulatoins\n\tThunder Bird Died\n\tYou have earned 12 Points\n";
					system("pause");
					do
					{

						cout << "\n\n\tThere are 2 Unknown ways\n\tSelect between 1 to 2: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2") {
							int randWay = rand() % 2 + 1;
							if (randWay == 1) {
								//Tengue
								lvl4tengue();
							}
							else if (randWay == 2) {
								//Valkyrie
								lvl4valkyrie();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2");
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tThunder Bird turn, Thunder Bird is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tThunder Bird attacked " << a << " points\n\t";

			charInfo(a, b,lvl4E.tBird);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}
void lvl4tengue(){
	cout << "\n\tHere is Tengue";
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl4E.tengue -= b;
				cout << "\n\tYou attacked " << b << " points";
				charInfo(a, b, lvl4E.tengue);
				if (lvl4E.tengue <= 0) {
					lvl4E.tengue = 100;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 13;
					cout << "\n\n\tCongratulatoins\n\tTengue Died\n\tYou have earned 13 Exp Points\n";
					system("pause");
					lvl4valkyrie();
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tTengue turn, Tengue is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tTengue attacked " << a << " points\n\t";
			charInfo(a, b, lvl4E.tengue);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}
void lvl4valkyrie() {
	cout << "\n\tOpps, Here is Valkyrie The Most Dangerious Enemy.";
	int a = 0, b = 0, i = 0;
	string choose;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. MainMenu\n\t3. Exit Game\n\tChoose Optoin: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl4E.valkyrie -= b;
				cout << "\n\tYou attacked " << b << " points";
				charInfo(a, b,lvl4E.tengue);
				if (lvl4E.valkyrie <= 0) {
					lvl4E.valkyrie = 120;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 15;
					if(level.lvl != 5 || level.lvl <5) level.lvl++;
					cout << "\n\n\tValkyrie Died\n\tYou have Completed Game\n\tYou have earned 15 Exp Points\n";
					system("pause");
					startGame();
					break;
				}
			}
			else if (choose == "2") {
				system("cls");
				startGame();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tValkyrie turn, Valkyrie is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 30 + 1; // Enemy attacked points, max 30
			cout << "\n\tValkyrie attacked " << a << " points\n\t";

			charInfo(a, b, lvl4E.valkyrie);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				system("cls");
				startGame();
				break;
			}
		}
	}
}
