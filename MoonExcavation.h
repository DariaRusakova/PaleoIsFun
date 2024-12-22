#pragma once
#include "Excavation.h"

#include "item.h" 


using namespace ItemsStore;

class MoonExcavation :
	public Excavation
{
private:
	std::string name = "Excavation on the Lonely Moon";
	int cost = 100;
	std::vector<ItemName> findings = { 
		ItemName::Meteorite, 
		ItemName::Skull,
		ItemName::Ceramics,
		ItemName::GlassAnimals, 
		ItemName::Tailbone, 
		ItemName::FishSkeleton, 
		ItemName::MetalPipe,
		ItemName::BrokenMirror, 
		ItemName::MetalPlate, 
		ItemName::Ancientaxe 
	};

public:
	MoonExcavation(Items&);
	void excavate(Items&, ItemName);
	void effect();
	void printText() {
		std::cout << "Welcome to the secluded land of eternity " << std::endl;
	};
};

