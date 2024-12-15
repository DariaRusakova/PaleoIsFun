#include "SwampExcavation.h"
#include <iostream>

using namespace ItemsStore;
using namespace std;

SwampExcavation::SwampExcavation(Items& items) {
	printText();
	items.spend(ItemName::Gold, cost);
}
void SwampExcavation::effect() {
	cout << "Splash!!!" << endl;
}

void SwampExcavation::excavate(Items& items, ItemName instrument) {

	effect();
	if (items.get()[instrument] == 0) {
		cout << "Bad instrument!" << endl;
		return;
	}
	bool isInstumentBroken = false;
	if (instrument == ItemName::Shovel) {
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
		cout << "You have found " << items.getName(thing) << "! Lucky you..." << endl;
	}
	else {
		cout << "Your instrument got sucked under the ground. No findings today." << endl;
		items.spend(instrument, 1);
	}

	items.spend(ItemName::Food, 1);
}