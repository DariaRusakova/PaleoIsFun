#pragma once
#include <string> 
#include <iostream> 
#include <vector>
#include "item.h" 

using namespace std;
using namespace ItemsStore;

namespace PaleoMuseum
{
    class Museum
    {
    public:
        Museum(string);
        void putOnShelf(Items&);
        void show();
        string getName();

    private:
        vector<string> valuables;
        string name;
    };
}