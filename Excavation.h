#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "item.h"

using namespace std;
using namespace ItemsStore;

class Excavation {
private:
	string name;  
	int cost; 
	vector<ItemName> findigs;

public:
	virtual void excavate(Items&, ItemName) = 0;
	virtual void printText() = 0;
	virtual void effect() = 0;

	int getRandomInt(int min, int max) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(min, max);

		return distr(gen);
	}
};
