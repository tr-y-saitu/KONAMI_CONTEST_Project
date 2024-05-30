#pragma once
#include "DxLib.h"

class Player;
class Enemy;
class Gem;

class Collision
{
public:
	Collision();
	~Collision();
	
	void HitPlayerToEnemy(Player& player, Enemy& enemy);
	void IsHitPlayerToGem(Player& player, Gem& gem);

	const float OBJECT_HIT_BUF = 0.5f;

private:



};







