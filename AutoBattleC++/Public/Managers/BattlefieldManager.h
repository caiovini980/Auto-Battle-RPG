#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include "../BattlefieldCell.h"

class BattleFieldManager
{
public:
    BattleFieldManager(/* args */);
	BattleFieldManager(const int & x, const int & y);

    ~BattleFieldManager();

	void CreateBattlefield();
	void SetCellOccupation(BattlefieldCell& cell, bool isOccupied, bool isPlayer);
	void UpdateBattlefield(const char* PlayerIndicator, const char* OpponentIndicator);
	std::shared_ptr<BattlefieldCell> GetRandomCell();

private:
	int amountOfColumns{}; // X
	int amountOfLines{}; // Y

	std::vector<std::shared_ptr<BattlefieldCell>> battlefield{};
	std::vector<BattlefieldCell> freeCells{};
	std::vector<BattlefieldCell> occupiedCells{};

	void AddOnVector(const BattlefieldCell& cell, std::vector<BattlefieldCell> &vector);
	void RemoveFromVector(const BattlefieldCell& cell, std::vector<BattlefieldCell> &vector);
	void PrintVector(const std::vector<BattlefieldCell> &vector);

	// void AddFreeCell(const BattlefieldCell& cell);
	// void AddOccupiedCell(const BattlefieldCell& cell);
	// void RemoveFreeCell(const BattlefieldCell& cell);
	// void RemoveOccupiedCell(const BattlefieldCell& cell);
};

