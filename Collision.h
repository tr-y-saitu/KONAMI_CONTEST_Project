#pragma once
#include "DxLib.h"

class Player;
class Enemy;
class Gem;
class TreasureChest;

class Collision
{
public:
	Collision();
	~Collision();
	
	void HitPlayerToEnemy(Player& player, Enemy& enemy);
	void IsHitPlayerToGem(Player& player, Gem& gem);
	void IsHitGemToTreasureChest(Gem& gem, TreasureChest& chest);
	bool IsHitGemToTreasureChestBool(Gem& gem, TreasureChest& chest);


	const float OBJECT_HIT_BUF = 0.5f;

private:



};







