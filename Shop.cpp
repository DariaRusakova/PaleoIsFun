#include "item.h" 
#include "shop.h" 
#include <iostream> 
#include <string> 
#include <fstream>

using namespace ItemsStore;
using namespace PaleoShop;


Shop::Shop() {
    std::ifstream in;
    in.open("priceList.txt");
    if (in.is_open())
    {
        int itemName, price;
        while (in >> itemName >> price)
        {
            priceList[static_cast<ItemName>(itemName)] += price;
        }
    }
    in.close();
}

void Shop::sell(Items& items, ItemName name, unsigned value)
{
     unsigned price = priceList[name];
     if (price == 0) return;
     if (items.canSpend(name, value))
     {
       items.spend(name, value);
       items.add(ItemsStore::ItemName::Gold, price * value);
     } else {
         std::cout << "Not enough " << name << std::endl;
     }
}

void Shop::sellAll(Items& items, ItemName name)
{
    unsigned value = items.get()[name];
    Shop::sell(items, name, value);
}

void Shop::buy(Items& items, ItemName name, unsigned value)
{
    unsigned price = priceList[name];
    if (price == 0) return;
    unsigned cost = price * value;
    if (items.canSpend(ItemName::Gold, cost))
    {
        items.add(name, value);
        items.spend(ItemsStore::ItemName::Gold, cost);
    }
    else {
        std::cout << "No that much " << name << std::endl;
    }
}
#include "Shop.h"
