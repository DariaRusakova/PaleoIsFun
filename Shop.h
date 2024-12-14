#ifndef SHOP_H
#define SHOP_H

#include <map>
#include <string> 
#include <iostream> 

#include "item.h" 

using namespace std;
using namespace ItemsStore;

namespace PaleoShop
{
    class Shop
    {
    public:
        Shop();
        void sell(Items&, ItemName, unsigned);
        void sellAll(Items&, ItemName);
        void buy(Items&, ItemName, unsigned);
    private:
        map<ItemName, unsigned> priceList;
    };
}

#endif

