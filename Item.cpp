#include "item.h" 
#include <iostream> 
#include <string> 

using namespace ItemsStore;
using namespace std;

Items::Items(unsigned gold) {
    items[ItemName::Gold] = gold;
}

void Items::print(ItemName type)
{
    cout << items[type];
}
void Items::print()
{
    cout << "\t +Items" << endl;
    for (const auto& item : items)
        cout << getName(item.first) << "\t" << item.second << endl;
    cout << "\t -Items" << endl;
}

void Items::sellList()
{
    for (const auto& item : items)
    {
        if (item.first < ItemNums::Findings) {
            continue;
        }
        cout << item.first << ": " << getName(item.first) << "\t - count: " << item.second << endl;
    }
}

void Items::buyList()
{
    for (const auto& item : items)
    {
        if (item.first == ItemName::Gold or item.first >= ItemNums::Findings) {
            continue;
        }
        cout << item.first << ": " << getName(item.first) << "\t - count: " << item.second << endl;
    }
}

void Items::printInstruments()
{
    for (const auto& item : items)
    {
        if (item.first < ItemNums::Instruments or item.first >= ItemNums::Findings) {
            continue;
        }
        cout << item.first << ": " << getName(item.first) << "\t - count: " << item.second << endl;
    }
}

void Items::add(ItemName type, unsigned value)
{
    items[type] += value;
}
void Items::spend(ItemName type, unsigned value)
{
    items[type] -= value;
}

bool Items::canSpend(ItemName type, unsigned value)
{
    if (items[type] < value)
    {
        return false;
    }
    return true;
}

ItemsType Items::get()
{
    return items;
}

string Items::getName(ItemName name)
{
    switch (name)
    {
    case ItemName::Gold:
        return "Gold";
        break;
    case ItemName::Food:
        return "Food";
        break;
    case ItemName::Axe:
        return "Axe";
        break;
    case ItemName::Brush:
        return "Brush";
        break;
    case ItemName::Pickaxe:
        return "Pickaxe";
        break;
    case ItemName::Shovel:
        return "Shovel";
        break;
    case ItemName::Ammonit:
        return "Ammonite";
        break;
    case ItemName::Skull:
        return "Skull of unknown animal";
        break;
    case ItemName::Tailbone:
        return "Enormous dinosaurs tailbone";
        break;
    case ItemName::Ancientaxe:
        return "Ancient axe covered in gold";
        break;
    case ItemName::FishSkeleton:
        return "Skeleton of extinct Fish";
        break;
    case ItemName::Ceramics:
        return "Pieces of ceramic vase";
        break;
    case ItemName::MetalPlate:
        return "Plate of unknown metal";
        break;
    case ItemName::AnimeFigurine:
        return "Figurine of blue-haired girl";
        break;
    case ItemName::MetalPipe:
        return "Metal pipe";
        break;
    case ItemName::GlassAnimals:
        return "Melodicaly pleasing glass animals";
        break;
    case ItemName::PorkSoda:
        return "Can of pineapple soda";
        break;
    case ItemName::Book:
        return "Unrecognisable book";
        break;
    case ItemName::StudentsBook:
        return "Ege 2024 Computer Sience book";
        break;
    case ItemName::BrokenMirror:
        return "Reflecring piece of Glass";
        break;
    case ItemName::Painting:
        return "Torn renaissance painting";
        break;
    case ItemName::AkiMafu:
        return "Purple and Orange plush toys";
        break;
    case ItemName::Water:
        return "Dangerous still Water";
        break;
    case ItemName::Meteorite:
        return "Small lunar Meteorite";
        break;
    }
    return "Unknown Item";
}