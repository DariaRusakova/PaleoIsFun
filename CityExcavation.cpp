#include "CityExcavation.h"
#include <iostream>

using namespace ItemsStore;


CityExcavation::CityExcavation(Items& items) {
	printText();
	items.spend(ItemName::Gold, cost);
}

void CityExcavation::effect() {
	std::cout << "Dang!!!" << std::endl;
}

void CityExcavation::excavate(Items& items, ItemName instrument) {

	effect();
	if (items.get()[instrument] == 0) {
		std::cout << "Bad instrument!" << std::endl;
		return;
	}
	bool isInstumentBroken = false;
	if (instrument == ItemName::Pickaxe) {
		isInstumentBroken = true;
	}
	else {
		int prob = getRandomInt(0, 10);
		if (prob > 7) {
			isInstumentBroken = true;
		}
	}

	if (!isInstumentBroken)
	{
		ItemName thing = findings[getRandomInt(0, findings.size() - 1)];
		items.add(thing, 1);
		std::cout << "You have found " << items.getName(thing) << "! Lucky you..." << std::endl;
	}
	else {
		std::cout << "Your instrument has got stuck in ruins. No findings today." << std::endl;
		items.spend(instrument, 1);
	}

	items.spend(ItemName::Food, 1);
}