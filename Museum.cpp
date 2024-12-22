#include "item.h" 
#include "Museum.h" 
#include <iostream> 
#include <string> 

using namespace ItemsStore;
using namespace PaleoMuseum;


Museum::Museum(std::string name) {
    this->name = name;
}

void Museum::putOnShelf(Items& items) {    
    for (const auto& item : items.get())
    {
        if (item.first < ItemNums::Findings) continue;
        std::string val = items.getName(item.first);

        if (find(valuables.begin(), valuables.end(), val) == valuables.end())
        {
            valuables.push_back(val);
        }
    }
}

std::string Museum::getName() {
    return name;
}

void Museum::show()
{
    for (const auto& item : valuables)
    {
        std::cout << item << std::endl;
    }

    if (valuables.size() == 0) {
        std::cout << "Museum is currently empty!" << std::endl;
    }
}
