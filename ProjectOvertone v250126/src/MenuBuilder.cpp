#include "Config.h"

#include "classes/Menu.h"
#include "classes/Entities.h"

using Overtone::cW, Overtone::cF, Overtone::cZ, Overtone::isTextOnMenu, Overtone::isMenuOpen;

char Switch(bool Switch) {
	if (Switch) {
		return 'I';
	}
	else {
		return 'O';
	}
}

void MenuHandler() {
	if (isTextOnMenu) {
		menu.MenuTextFiller();
	}
	else {
		//Negative worlds represent different type of menus
		switch (cW) {
		case -1:
			isMenuOpen = true;
			menu.MenuFiller(mainMenuOptions);
			break;
		case -2:
			isMenuOpen = true;
			menu.MenuFiller(configMenuOptions);
			menu.MenuCoordFiller(14, 2, Switch(Overtone::sound));
			menu.MenuCoordFiller(14, 4, Switch(Overtone::slowMode));
			break;
		case -3:
			menu.MenuFiller(BagMenuOptions);
			break;
		default:
			menu.MenuFiller(commandMenuOptions);
			break;
		}
	}
}

void MenuBuilder() {
	string menuFrame;

	MenuHandler();
	if (isMenuOpen) {
		menu.MenuNav();
	}

	menu.MenuGen(menuFrame);
}