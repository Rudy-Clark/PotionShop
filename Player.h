#pragma once

#include "Potion.h"
#include <string>

class Player
{
public:
	Player(std::string playerName);

	int getGold() const;
	int getInventory(Potion::Type type) const;
	std::string getName() const;

	void subtractGoldAmount(int gold);
	void setInventoryItem(Potion::Type item);
private:
	std::string m_name{};
	int m_gold{};
	std::array<int, Potion::max_size> m_inventory{};
};

