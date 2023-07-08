#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include "../BattlefieldCell.h"

class BattleFieldManager
{
public:
    BattleFieldManager(/* args */);
	BattleFieldManager(int & x, int & y);

    ~BattleFieldManager();

	void CreateBattlefield();
	std::shared_ptr<BattlefieldCell> GetRandomCell();

private:
	int amountOfColumns{}; // X
	int amountOfLines{}; // Y

	std::vector<std::shared_ptr<BattlefieldCell>> battlefield{};
};

