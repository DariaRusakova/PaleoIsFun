#include "item.h" 
#include "Museum.h" 
#include <iostream> 
#include <string> 

using namespace ItemsStore;
using namespace PaleoMuseum;
using namespace std;

Museum::Museum(string name) {
    this->name = name;
}

void Museum::putOnShelf(Items& items) {    
    for (const auto& item : items.get())
    {
        if (item.first < ItemNums::Findings) continue;
        string val = items.getName(item.first);

        if (find(valuables.begin(), valuables.end(), val) == valuables.end())
        {
            valuables.push_back(val);
        }
    }
}

string Museum::getName() {
    return name;
}

void Museum::show()
{
    for (const auto& item : valuables)
    {
        cout << item << endl;
    }

    if (valuables.size() == 0) {
        cout << "Museum is currently empty!" << endl;
    }
}
