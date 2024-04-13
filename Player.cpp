#include "Player.h"
#include "Random.h"
#include "Potion.h"

Player::Player(std::string playerName = "unknown")
	: m_name{ playerName}
{
	m_gold = Random::get(80, 120);
}

int Player::getGold() const
{
	return m_gold;
}

int Player::getInventory(Potion::Type type) const
{
	return m_inventory[type];
}

std::string Player::getName() const
{
	return m_name;
}

void Player::subtractGoldAmount(int gold)
{
	m_gold -= gold;
}

void Player::setInventoryItem(Potion::Type item)
{
	m_inventory[item] += 1;
}
