#pragma once
#include "Excavation.h"

#include "item.h" 

using namespace std;
using namespace ItemsStore;

class MoonExcavation :
	public Excavation
{
private:
	string name = "Excavation on the Lonely Moon";
	int cost = 100;
	vector<ItemName> findings = { 
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
	void printText() {
		cout << "Welcome to the secluded land of eternity " << endl;
	};
};

