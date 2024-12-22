#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "item.h"
#include "museum.h"
#include "shop.h"
#include "DesertExcavation.h"
#include "MoonExcavation.h"
#include "CityExcavation.h"
#include "SwampExcavation.h"


using namespace ItemsStore;
using namespace PaleoMuseum;
using namespace PaleoShop;




std::ostream& operator<<(std::ostream& o, Items& items) {
    for (const auto& item : items.get())
        o << item.first << "\t" << item.second << std::endl;
    return o;
}

void saveGame(Items& items)
{
    std::ofstream out;
    out.open("save.txt");
    if (out.is_open())
    {
        out << items << std::endl;
    }
    out.close();
}

void loadGame(Items& items)
{
    std::ifstream in;
    in.open("save.txt");
    if (in.is_open())
    {
        int itemName, count;
        while (in >> itemName >> count)
        {
            items.set(static_cast<ItemName>(itemName), count);
        }
    }
    in.close();
}


int main()
{
    system("cls");
    Items items (1000);
    Museum museum ("Great Museum of Paleontology");
    Shop shop;

    // 0 - Base, 1 - Shop, 2 - Museum, 3 - Excavation
    std::string location = "0";

    while (true)
    {
        if (location == "0")
        {
            system("cls");
            items.print();
            std::cout << "Welcome to the Base!" << std::endl;
            std::cout << "Choose your action" << std::endl;
            std::cout << "1. Shop" << std::endl;
            std::cout << "2. Museum" << std::endl;
            std::cout << "3. Expedition" << std::endl;
            std::cout << "4. Load Game" << std::endl;
            std::cout << "5. Exit" << std::endl;
            std::cout << ">> ";
            location = "";

            std::cin >> location;
        }

        if (location == "1")
        {
            std::string shopAction = "0";
            while (true)
            {
                system("cls");
                items.print();
                std::cout << "Welcome to the Shop!" << std::endl;
                std::cout << "Choose your action" << std::endl;
                std::cout << "1. Sell Items" << std::endl;
                std::cout << "2. Buy Items" << std::endl;
                std::cout << "3. Exit" << std::endl;
                std::cout << ">> ";

                std::cin >> shopAction;

                if (shopAction == "1") {
                    while (true)
                    {
                        system("cls");
                        items.print();
                        std::cout << "Welcome to the Shop!" << std::endl;
                        std::string itemId;
                        std::cout << "Sell Items: " << std::endl;
                        items.sellList();
                        std::cout << "0. Exit" << std::endl;
                        std::cout << ">> ";

                        std::cin.ignore();
                        std::cin >> itemId;

                        if (itemId != "0")
                        {
                            ItemName itemName = static_cast<ItemName>(stoi(itemId));
                            shop.sellAll(items, itemName);
                        }

                        if (itemId == "0")
                        {
                            shopAction = "0";
                            break;
                        }
                    }
                }

                if (shopAction == "2") {
                    while (true)
                    {
                        system("cls");
                        items.print();
                        std::cout << "Welcome to the Shop!" << std::endl;
                        std::string itemId = "0";
                        std::cout << "Buy Items: " << std::endl;
                        items.buyList();
                        std::cout << "0. Exit" << std::endl;
                        std::cout << ">> ";

                        std::cin.ignore();
                        std::cin >> itemId;

                        if (itemId != "0")
                        {
                            ItemName itemName = static_cast<ItemName>(stoi(itemId));
                            shop.buy(items, itemName, 1);
                        }

                        if (itemId == "0")
                        {
                            shopAction = "0";
                            break;
                        }
                    }
                }

                if (shopAction == "3")
                {
                    std::cout << "See you later!!" << std::endl;
                    location = "0";
                    break;
                }
            }

        }

        if (location == "2")
        {
            system("cls");
            std::cout << "Welcome to " << museum.getName() << std::endl;
            museum.show();

            system("pause");
            location = "0";
        }

        if (location == "3")
        {
            std::string expId = "0";
            std::cout << "Choose your expedition!" << std::endl;
            std::cout << "1. Desert expedition" << std::endl;
            std::cout << "2. Swamp expedition" << std::endl;
            std::cout << "3. City expedition" << std::endl;
            std::cout << "4. Moon expedition" << std::endl;
            std::cout << ">> ";

            std::cin >> expId;

            Excavation* expedition = nullptr;

            if (expId == "1")
            {
                expedition = new DesertExcavation(items);
            }
            if (expId == "2")
            {
                expedition = new SwampExcavation(items);
            }
            if (expId == "3")
            {
                expedition = new CityExcavation(items);
            }
            if (expId == "4")
            {
                expedition = new MoonExcavation(items);
            }

            if (expedition == nullptr) {
                expedition = new DesertExcavation(items);
            }
            
            system("pause");

            while (true)
            {
                system("cls");
                items.print();

                if (!items.canSpend(ItemName::Food, 1)) {
                    std::cout << "Out of Food!" << std::endl;
                    std::cout << "Go to base!" << std::endl;
                    system("pause");
                    location = "0";
                    museum.putOnShelf(items);
                    saveGame(items);
                    break;
                }

                std::string choice = "0";
                std::cout << "Start digging?" << std::endl;
                std::cout << "1. Dig" << std::endl;
                std::cout << "2. Go to base" << std::endl;
                std::cout << ">> ";
                std::cin >> choice;

                if (choice == "1")
                {
                    std::cout << "Choose your instrument!" << std::endl;
                    std::string instrument;
                    if (items.printInstruments() <= 0) {
                        std::cout << "Out of Instruments!" << std::endl;
                        std::cout << "Go to base!" << std::endl;
                        system("pause");
                        location = "0";
                        museum.putOnShelf(items);
                        saveGame(items);
                        break;
                    }
                    std::cout << ">> ";
                    std::cin.ignore();
                    std::cin >> instrument;
                    ItemName itemName = static_cast<ItemName>(stoi(instrument));
                    expedition->excavate(items, itemName);
                    system("pause");
                    choice = "0";
                }

                if (choice == "2")
                {
                    std::cout << "Go to base!" << std::endl;
                    system("pause");
                    location = "0";
                    museum.putOnShelf(items);
                    saveGame(items);
                    break;
                }
            }
        }

        if (location == "4")
        {
            loadGame(items);
            std::cout << "Game loaded!!" << std::endl;
            system("pause");
            location = "0";
        }

        if (location == "5")
        {
            std::cout << "See you later!!" << std::endl;
            break;
        }
    }

    return 0;

}
