#include <conio.h>
#include <cstdlib>
#include <iostream>

#include "KeyCheck.h"

#include "Config.h"
#include "classes/Entities.h"
#include "classes/Screen.h"
#include "classes/Menu.h"

bool TextCheck() {
	if (Overtone::isTextOnMenu || Overtone::isTextOnScreen) return true;
	else return false;
}

void Debug() {
	//std::cout << MC.pos.X << std::endl;
	//std::cout << MC.pos.Y << std::endl;
	//std::cout << MC.oldPos.X << std::endl;
	//std::cout << MC.oldPos.Y << std::endl;
	//std::cout << MC.lastTile << std::endl;
	//std::cout << MC.currentTile << std::endl;
	std::cout << MC.nextTile << std::endl;
	std::cout << MC.canInteract << std::endl;
	std::cout << MC.currentWorldInt.size() << std::endl;
}

void CommandHelper() {
	if (TextCheck()) {
		std::cout << "< Continue >";
	} 
	else if (MC.canInteract) {
		std::cout << "< Interact >";
	}
	else {
		std::cout << "                                  ";
	}
}

void KeyCheck() {
	//Debug();
	CommandHelper();
	int specialKey = 0, key = _getch();
	if (key == 0 || key == 224) {
		specialKey = _getch();
	}
	if (!TextCheck()) {
		if (Overtone::isMenuOpen) {
			menu.MenuKeyChecks(key, specialKey);
		}
		else if(Overtone::cW < 0){
			screen.ScreenKeyChecks(key, specialKey);
		}
		else if (Overtone::cW >= 0) {
			MC.KeyChecks(key, specialKey, screen);
		}
	}
}