#pragma once
#ifndef ITEMS_H
#define ITEMS_H

#include <map>
#include <string> 
#include <iostream> 

using namespace std;

namespace ItemsStore
{
    enum ItemNums {
        Common = 0,
        Instruments = 100,
        Findings = 200
    };

    enum ItemName
    {
        Gold = Common,
        Food,
        Axe = Instruments,
        Brush,
        Pickaxe,
        Shovel,
        Ammonit = Findings,
        Skull,
        Tailbone,
        Ancientaxe,
        FishSkeleton,
        Ceramics,
        MetalPlate,
        AnimeFigurine,
        MetalPipe,
        GlassAnimals,
        PorkSoda,
        Book,
        StudentsBook,
        BrokenMirror,
        Painting,
        AkiMafu,
        Water,
        Meteorite

    };

    using ItemsType = map<ItemName, unsigned>;



    class Items
    {
    public:
        Items(unsigned gold);
        void print(ItemName);
        void print();
        void sellList();
        void buyList();
        unsigned printInstruments();
        void add(ItemName, unsigned);
        void set(ItemName, unsigned);
        void spend(ItemName, unsigned);
        bool canSpend(ItemName, unsigned);
        ItemsType get();
        string getName(ItemName);
    private:
        ItemsType items;
    };
}



#endif