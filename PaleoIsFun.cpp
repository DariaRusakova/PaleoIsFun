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

using namespace std;


ostream& operator<<(ostream& o, Items& items) {
    for (const auto& item : items.get())
        o << item.first << "\t" << item.second << endl;
    return o;
}

void saveGame(Items& items)
{
    ofstream out;
    out.open("save.txt");
    if (out.is_open())
    {
        out << items << endl;
    }
    out.close();
}

void loadGame(Items& items)
{
    ifstream in;
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
    string location = "0";

    while (true)
    {
        if (location == "0")
        {
            system("cls");
            items.print();
            cout << "Welcome to the Base!" << endl;
            cout << "Choose your action" << endl;
            cout << "1. Shop" << endl;
            cout << "2. Museum" << endl;
            cout << "3. Expedition" << endl;
            cout << "4. Load Game" << endl;
            cout << "5. Exit" << endl;
            cout << ">> ";
            location = "";

            cin >> location;
        }

        if (location == "1")
        {
            string shopAction = "0";
            while (true)
            {
                system("cls");
                items.print();
                cout << "Welcome to the Shop!" << endl;
                cout << "Choose your action" << endl;
                cout << "1. Sell Items" << endl;
                cout << "2. Buy Items" << endl;
                cout << "3. Exit" << endl;
                cout << ">> ";

                cin >> shopAction;

                if (shopAction == "1") {
                    while (true)
                    {
                        system("cls");
                        items.print();
                        cout << "Welcome to the Shop!" << endl;
                        string itemId;
                        cout << "Sell Items: " << endl;
                        items.sellList();
                        cout << "0. Exit" << endl;
                        cout << ">> ";

                        cin.ignore();
                        cin >> itemId;

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
                        cout << "Welcome to the Shop!" << endl;
                        string itemId = "0";
                        cout << "Buy Items: " << endl;
                        items.buyList();
                        cout << "0. Exit" << endl;
                        cout << ">> ";

                        cin.ignore();
                        cin >> itemId;

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
                    cout << "See you later!!" << endl;
                    location = "0";
                    break;
                }
            }

        }

        if (location == "2")
        {
            system("cls");
            cout << "Welcome to " << museum.getName() << endl;
            museum.show();

            system("pause");
            location = "0";
        }

        if (location == "3")
        {
            string expId = "0";
            cout << "Choose your expedition!" << endl;
            cout << "1. Desert expedition" << endl;
            cout << "2. Swamp expedition" << endl;
            cout << "3. City expedition" << endl;
            cout << "4. Moon expedition" << endl;
            cout << ">> ";

            cin >> expId;

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
                    cout << "Out of Food!" << endl;
                    cout << "Go to base!" << endl;
                    system("pause");
                    location = "0";
                    museum.putOnShelf(items);
                    saveGame(items);
                    break;
                }

                string choice = "0";
                cout << "Start digging?" << endl;
                cout << "1. Dig" << endl;
                cout << "2. Go to base" << endl;
                cout << ">> ";
                cin >> choice;

                if (choice == "1")
                {
                    cout << "Choose your instrument!" << endl;
                    string instrument;
                    if (items.printInstruments() <= 0) {
                        cout << "Out of Instruments!" << endl;
                        cout << "Go to base!" << endl;
                        system("pause");
                        location = "0";
                        museum.putOnShelf(items);
                        saveGame(items);
                        break;
                    }
                    cout << ">> ";
                    cin.ignore();
                    cin >> instrument;
                    ItemName itemName = static_cast<ItemName>(stoi(instrument));
                    expedition->excavate(items, itemName);
                    system("pause");
                    choice = "0";
                }

                if (choice == "2")
                {
                    cout << "Go to base!" << endl;
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
            cout << "Game loaded!!" << endl;
            system("pause");
            location = "0";
        }

        if (location == "5")
        {
            cout << "See you later!!" << endl;
            break;
        }
    }

    return 0;

}
