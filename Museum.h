#pragma once
#include <string> 
#include <iostream> 
#include <vector>
#include "item.h" 


using namespace ItemsStore;

namespace PaleoMuseum
{
    class Museum
    {
    public:
        Museum(std::string);
        void putOnShelf(Items&);
        void show();
        std::string getName();

    private:
        std::vector<std::string> valuables;
        std::string name;
    };
}