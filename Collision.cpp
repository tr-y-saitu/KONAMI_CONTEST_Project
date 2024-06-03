#include <stdio.h>
#include "math.h"
#include "Calculation.h"
#include "TreasureChest.h"
#include "Player.h"
#include "Enemy.h"
#include "Gem.h"
#include "collision.h"


/// <summary>
/// コンストラクタ
/// </summary>
Collision::Collision()
{

}


/// <summary>
/// デストラクタ
/// </summary>
Collision::~Collision()
{

}




void Collision::HitPlayerToEnemy(Player& player, Enemy& enemy)
{
	// 当たったか、当たっていないか
	bool isHit = false;

	// 情報の取得
	VECTOR _playerPos = player.GetPos();		// プレイヤーの座標
	VECTOR _enemyPos = enemy.GetPos();			// エネミーの座標
	double _rPlayer = player.GetRadius();		// プレイヤーの当たり判定の半径
	double _rEnemy = enemy.GetRudius();			// エネミーの当たり判定の半径

	// プレイヤーとエネミーの当たり判定
	// エネミーが存在しているかの値だけもらう
	if (enemy.GetVisibleFlag() == true)
	{
		// プレイヤーからエネミーのベクトル
		VECTOR _difference = VSub(_playerPos, _enemyPos);

		// 絶対値計算
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// 距離を算出
		//double _d = sqrt((_playerPos.x * _enemyPos.x) + (_playerPos.y * _enemyPos.y) + (_playerPos.z * _enemyPos.z));
		// 当たる距離
		double _rSum = _rPlayer + _rEnemy;

		
		// 中心点との距離を求める
		double _PlayerToEnemy = sqrt(pow(_playerPos.x + _enemyPos.x, 2) + pow(_playerPos.y + _enemyPos.y, 2) + pow(_playerPos.z + _enemyPos.z, 2));


		// 半径との距離が2つの半径の合計よりも小さければ
		if ( distance <= _rSum)
		{
			isHit = true;
		}
	}
	// 当たっているか否か
	player.SetIsHitEnemy(isHit);
}


/// <summary>
/// プレイヤーと宝石との当たり判定
/// </summary>
/// <param name="player">プレイヤー</param>
/// <param name="gem">宝石</param>
void Collision::IsHitPlayerToGem(Player& player, Gem& gem)
{
	// 最初は当たっていないを代入
	bool isHit = false;

	// 情報の取得
	VECTOR _playerPos = player.GetPos();		// プレイヤー座標
	VECTOR _gemPos = gem.GetPos();				// 宝石座標
	double _rPlayer = player.GetRadius();		// プレイヤーの当たり判定の半径
	double _rGem = gem.GetRadius();				// 宝石の当たり判定の半径

	// プレイヤーとエネミーの当たり判定
	// エネミーが存在しているかの値だけもらう
	if (gem.GetVisibleFlag() == true)
	{
		// プレイヤーから宝石（ジェム）のベクトル
		VECTOR _difference = VSub(_playerPos, _gemPos);

		// 絶対値計算
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// 距離を算出
		//double _d = sqrt((_playerPos.x * _gemPos.x) + (_playerPos.y * _gemPos.y) + (_playerPos.z * _gemPos.z));
		// 当たる距離
		double _rSum = _rPlayer + _rGem;


		// 半径との距離が2つの半径の合計よりも小さければ
		if (distance <= _rSum)
		{
			isHit = true;
		}
	}
	// 当たっているか否か
	gem.SetIsHitPlayer(isHit);
	player.SetIsHitGem(isHit);
}

/// <summary>
/// 宝石と宝箱の当たり判定
/// </summary>
/// <param name="gem">宝石</param>
/// <param name="chest">宝箱</param>
void Collision::IsHitGemToTreasureChest(Gem& gem, TreasureChest& chest)
{
	// 最初は当たっていないを代入
	bool isHit = false;

	// 情報の取得
	VECTOR _gemPos = gem.GetPos();		// 宝石の座標
	VECTOR _chestPos = chest.GetPos();	// 宝箱の座標
	double _rGem = gem.GetRadius();		// 宝石の半径
	double _rChest = chest.GetRadius();	// 宝箱の半径

	// 宝石と宝箱の当たり判定
	// 宝石がが存在しているかの値だけもらう
	if (gem.GetVisibleFlag() == true)
	{
		// プレイヤーから宝石（ジェム）のベクトル
		VECTOR _difference = VSub(_gemPos, _chestPos);

		// 絶対値計算
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// 当たる距離
		double _rSum = _rGem + _rChest;

		// 半径との距離が2つの半径の合計よりも小さければ
		if (distance <= _rSum)
		{
			// 接触している
			isHit = true;
		}
	}
	// 当たっているか否か
	gem.SetIsHitChest(isHit);
	chest.SetIsHitGem(isHit);
 }


/// <summary>
/// 宝石のいずれかと宝箱が当たったか
/// </summary>
/// <param name="gem">宝石</param>
/// <param name="chest">宝箱</param>
/// <returns>宝石と宝箱が接触したか</returns>
bool Collision::IsHitGemToTreasureChestBool(Gem& gem, TreasureChest& chest)
{
	// 最初は当たっていないを代入
	bool isHit = false;

	// 情報の取得
	VECTOR _gemPos = gem.GetPos();		// 宝石の座標
	VECTOR _chestPos = chest.GetPos();	// 宝箱の座標
	double _rGem = gem.GetRadius();		// 宝石の半径
	double _rChest = chest.GetRadius();	// 宝箱の半径

	// 宝石と宝箱の当たり判定
	// 宝石がが存在しているかの値だけもらう
	if (gem.GetVisibleFlag() == true)
	{
		// プレイヤーから宝石（ジェム）のベクトル
		VECTOR _difference = VSub(_gemPos, _chestPos);

		// 絶対値計算
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// 当たる距離
		double _rSum = _rGem + _rChest;

		// 半径との距離が2つの半径の合計よりも小さければ
		if (distance <= _rSum)
		{
			// 接触している
			isHit = true;
		}
	}
	// 当たっているか否か
	gem.SetIsHitChest(isHit);
	chest.SetIsHitGem(isHit);
	
	return isHit;

}



