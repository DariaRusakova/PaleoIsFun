#pragma once
#include "Excavation.h"

#include "item.h" 

using namespace std;
using namespace ItemsStore;

class SwampExcavation :
	public Excavation
{
private:
	string name = "Excavation in the misty swamp";
	int cost = 70;
	vector<ItemName> findings = { 
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
		cout << "Welcome to the sinister land of fog " << endl;
	};
};