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
            items.add(static_cast<ItemName>(itemName), count);
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
            system("cls");
            string shopAction = "0";
            while (true)
            {
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
                        cout << "Welcome to the Shop!" << endl;
                        string itemId;
                        cout << "Sell Items: " << endl;
                        items.sellList();
                        cout << "0. Exit" << endl;
                        cout << ">> ";

                        cin.ignore();
                        getline(cin, itemId);

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
                        cout << "Welcome to the Shop!" << endl;
                        string itemId;
                        cout << "Buy Items: " << endl;
                        items.buyList();
                        cout << "0. Exit" << endl;
                        cout << ">> ";

                        cin.ignore();
                        getline(cin, itemId);

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
                    string expId = "0";
                    cout << "Choose your expedition!" << endl;
                    cout << "1. Desert expedition" << endl;
                    cout << "2. Swamp expedition" << endl;
                    cout << "3. City expedition" << endl;
                    cout << "4. Moon expedition" << endl;
                    cout << ">> ";

                    cin >> expId;

                    Excavation* expedition;

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
                    if (expId == "2")
                    {
                        expedition = new MoonExcavation(items);
                    }

                    while (true)
                    {
                        system("cls");
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
                            items.printInstruments();
                            cout << ">> ";
                            cin.ignore();
                            getline(cin, instrument);
                            ItemName itemName = static_cast<ItemName>(stoi(instrument));
                            expedition->excavate(items, itemName);
                            choice = "0";
                        }

                        if (choice == "2")
                        {
                            cout << "Go to base!" << endl;
                            getchar();
                            location = "0";
                            museum.putOnShelf(items);
                            saveGame(items);
                            break;
                        }
                    }
                }
            }

        }

        if (location == "2")
        {
            system("cls");
            cout << "Welcome to " << museum.getName() << endl;
            museum.show();

            getchar();
            location = "0";
        }

        if (location == "3")
        {
            system("cls");
            cout << "Welcome to Expedition" << endl;

            getchar();
            location = "0";
        }

        if (location == "4")
        {
            loadGame(items);
            cout << "Game loaded!!" << endl;
            getchar();
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
