// PotionShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Player.h"
#include "Potion.h"

#include <iostream>
#include <array>
#include <string>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charToInt(char c) {
    return c - '0';
}

void displayUserInventory(const Player& player) {
    std::cout << "Your inventory contains: " << "\n";
    for (auto item : Potion::types) {
        if (!player.getInventory(item)) continue;
        std::cout << player.getInventory(item) << "x potion of " << Potion::names[item] << "\n";
    }
}


Potion::Type getUserInput() {
    
    while (true) {
        char shopItem{};
        std::cin >> shopItem;

        // if user input is char of the symbol 'q' or 'Q'
        if (shopItem == 'q' || shopItem == 'Q') {
            return Potion::max_size;
        }

        if (charToInt(shopItem) >= static_cast<int>(Potion::max_size)) {
            std::cout << "That is an invalid input.  Try again:" << "\n";
            std::cin.clear();
            ignoreLine();
            
            continue;
        }

        if (!std::cin) {

            if (std::cin.eof()) // if the stream was closed
            {
                exit(0); // shut down the program now
            }

            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine();
            std::cout << "That is an invalid input.  Try again:";

            continue;
        }

        return static_cast<Potion::Type>(charToInt(shopItem));
    }
}

void shop(Player& player) {
    while (true) {
        std::cout << "Here is our selection for today: " << "\n";

        for (auto item : Potion::types) {
            std::cout << item << ") " << Potion::names[item] << " costs " << Potion::prices[item] << "\n";
        }

        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        Potion::Type index{ getUserInput() };

        // user entered q
        if (index == Potion::max_size) {
            break;
        }
        
        int price { Potion::prices[index] };
        
        if (price > player.getGold()) {
            std::cout << "You can not afford that." << "\n";
            continue;
        }

        player.subtractGoldAmount(price);
        player.setInventoryItem(index);

        std::cout << "You purchased a potion of " << Potion::names[index] << ".  You have " << player.getGold() << " gold left." << "\n";
    }
}



int main()
{
    std::cout << "Hello to Roscoe's potion emporium!" << "\n";
    std::cout << "Enter your name: " << "\n";

    std::string name{};
    std::cin >> name;
    
    Player player{ name };

    std::cout << "Hello, " << name << ", you have " << player.getGold() << " gold." << "\n";
    std::cout << "\n";
    
    shop(player);

    displayUserInventory(player);
    
    std::cout << "You escaped with " << player.getGold() << " gold remaining." << "\n";

    std::cout << "Thanks for shopping at Roscoe's potion emporium!" << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
