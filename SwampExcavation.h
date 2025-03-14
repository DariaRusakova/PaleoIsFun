#pragma once
#include "Excavation.h"

#include "item.h" 


using namespace ItemsStore;

class SwampExcavation :
	public Excavation
{
private:
	std::string name = "Excavation in the misty swamp";
	int cost = 70;
	std::vector<ItemName> findings = { 
		ItemName::Ammonit, 
		ItemName::Skull,
		ItemName::StudentsBook,
		ItemName::AnimeFigurine, 
		ItemName::AkiMafu, 
		ItemName::FishSkeleton, 
		ItemName::MetalPipe,
		ItemName::BrokenMirror, 
		ItemName::MetalPlate, 
		ItemName::Water 
	};

public:
	SwampExcavation(Items&);
	void excavate(Items&, ItemName);
	void effect();
	void printText() {
		std::cout << "Welcome to the sinister land of fog " << std::endl;
	};
};