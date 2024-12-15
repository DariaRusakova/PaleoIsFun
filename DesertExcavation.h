#pragma once
#include "Excavation.h"

#include "item.h" 

using namespace std;
using namespace ItemsStore;

class DesertExcavation :
    public Excavation
{
private:
	string name = "Excavation In The Goby Dessert";
	int cost = 80;
	vector<ItemName> findings = {
		ItemName::Ammonit, 
		ItemName::Skull,
		ItemName::Ceramics,
		ItemName::GlassAnimals, 
		ItemName::Tailbone, 
		ItemName::FishSkeleton, 
		ItemName::Painting,
		ItemName::BrokenMirror, 
		ItemName::MetalPlate, 
		ItemName::Ancientaxe
	};

public:
	DesertExcavation(Items&);
	void excavate(Items&, ItemName);
	void effect();
	void printText() {
		cout << "Welcome to deadly hot motherland of lizards!" << endl;
	};
};

