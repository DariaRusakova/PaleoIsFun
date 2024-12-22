#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "item.h"


using namespace ItemsStore;

class Excavation {
private:
	std::string name;  
	int cost; 
	std::vector<ItemName> findigs;

public:
	virtual void excavate(Items&, ItemName) = 0;
	virtual void printText() = 0;
	virtual void effect() = 0;

	int getRandomInt(int min, int max) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(min, max);

		return distr(gen);
	}
};
