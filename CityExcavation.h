#pragma once
#include "Excavation.h"

#include "item.h" 


using namespace ItemsStore;

class CityExcavation :
	public Excavation
{
private:
	std::string name = "Excavation in the Abandoned City";
	int cost = 60;
	std::vector<ItemName> findings = { 
		ItemName::PorkSoda, 
		ItemName::Skull,
		ItemName::Ceramics,
		ItemName::GlassAnimals, 
		ItemName::AnimeFigurine, 
		ItemName::AkiMafu, 
		ItemName::MetalPipe,
		ItemName::BrokenMirror, 
		ItemName::MetalPlate, 
		ItemName::StudentsBook 
	};

public:
	CityExcavation(Items&);
	void excavate(Items&, ItemName);
	void effect();
	void printText() {
		std::cout << "Welcome to the remainig ruins of society " << std::endl;
	};
};