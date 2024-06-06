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

	/// <summary>
	/// プレイヤーとエネミーの当たり判定
	/// </summary>
	/// <param name="player">プレイヤークラス</param>
	/// <param name="enemy">エネミークラス</param>
	void HitPlayerToEnemy(Player& player, Enemy& enemy);

    /// <summary>
    /// プレイヤーと宝石との当たり判定
    /// </summary>
    /// <param name="player">プレイヤー</param>
    /// <param name="gem">宝石</param>
	void IsHitPlayerToGem(Player& player, Gem& gem);

    /// <summary>
    /// 宝石と宝箱の当たり判定
    /// </summary>
    /// <param name="gem">宝石</param>
    /// <param name="chest">宝箱</param>
	void IsHitGemToTreasureChest(Gem& gem, TreasureChest& chest);

    /// <summary>
    /// 宝石のいずれかと宝箱が当たったか
    /// </summary>
    /// <param name="gem">宝石</param>
    /// <param name="chest">宝箱</param>
    /// <returns>宝石と宝箱が接触したか</returns>
    bool IsHitGemToTreasureChestBool(Gem& gem, TreasureChest& chest);

    /// <summary>
    /// プレイヤーと宝石の2D当たり判定
    /// </summary>
    /// <param name="player">プレイヤークラス</param>
    /// <param name="gem">宝石クラス</param>
    void IsHit2DPlayerToGem(Player& player, Gem& gem);

    /// <summary>
    /// 宝石と宝箱の2D当たり判定
    /// </summary>
    /// <param name="gem">宝石</param>
    /// <param name="chest">宝箱</param>
    bool IsHit2DGemToTreasureChest(Gem& gem, TreasureChest& chest);

    /// <summary>
    /// オブジェクト同士の2DBOX当たり判定
    /// </summary>
    /// <param name="pos1">対象物１</param>
    /// <param name="pos2">対象物２</param>
    /// <param name="width1">対象物１の幅</param>
    /// <param name="height1">対象物１の高さ</param>
    /// <param name="width2">対象物２の幅</param>
    /// <param name="height2">対象物２の高さ</param>
    /// <returns>当たっているかどうか</returns>
    bool IsHitObject2DBOX(VECTOR pos1, VECTOR pos2, float width1,float height1,float width2,float height2);

    // 定数
	const float OBJECT_HIT_BUF = 0.5f;  // オブジェクトの当たり判定バフ値

private:


    //bool bb = collision->IsHit2DGemToTreasureChest(*gem[i], *treasureChest;
};







