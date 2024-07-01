#include <stdio.h>
#include "math.h"
#include "Calculation.h"
#include "TreasureChest.h"
#include "Player.h"
#include "Enemy.h"
#include "Gem.h"
#include "collision.h"
#include "EffectManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
Collision::Collision()
{
    // 処理なし
}


/// <summary>
/// デストラクタ
/// </summary>
Collision::~Collision()
{
    // 処理なし
}

/// <summary>
/// プレイヤーと宝石の2D当たり判定
/// </summary>
/// <param name="player">プレイヤークラス</param>
/// <param name="gem">宝石クラス</param>
bool Collision::IsHit2DPlayerToGem(Player& player, Gem& gem)
{
    // 当たったか、当たっていないか
    bool isHit = false;

    // プレイヤーと宝石の当たり判定
    // エネミーが存在しているかの値だけもらう
    if (gem.GetVisibleFlag() == true)
    {
        VECTOR playerPos = player.GetPos();
        float playerWidth = player.GetWidth();
        float playerHeight = player.GetHeight();
        VECTOR gemPos = gem.GetPos();
        float gemWidth = gem.GetWidth();
        float gemHeight = gem.GetHeight();

        // プレイヤーのクッションに当たり判定を持たせるので位置調整
        playerPos = VAdd(playerPos, player.GetPlayerCushionOffSetPosition());

        // 2Dの当たり判定
        isHit = IsHitObject2DBOX(playerPos, gemPos, playerWidth, playerHeight, gemWidth, gemHeight);
    }
    // 当たっているか否か
    player.SetIsHitGem(isHit);
    gem.SetIsHitPlayer(isHit);

    return isHit;
}


/// <summary>
/// 宝石と宝箱の2D当たり判定
/// </summary>
/// <param name="gem">宝石</param>
/// <param name="chest">宝箱</param>
/// <returns>宝石と宝箱が当たったかどうか</returns>
bool Collision::IsHit2DGemToTreasureChest(Gem& gem, TreasureChest& chest)
{
    // 当たったか、当たっていないか
    bool isHit = false;

    // プレイヤーと宝石の当たり判定
    // エネミーが存在しているかの値だけもらう
    if (gem.GetVisibleFlag() == true)
    {
        VECTOR gemPos = gem.GetPos();
        float gemWidth = gem.GetWidth();
        float gemHeight = gem.GetHeight();
        VECTOR chestPos = chest.GetPos();
        float chestWidth = chest.GetWidth();
        float chestHeight = chest.GetHeight();

        // 2D当たり判定
        isHit = IsHitObject2DBOX(gemPos, chestPos, gemWidth, gemHeight, chestWidth, chestHeight);
    }
    // 当たっているか否か
    chest.SetIsHitGem(isHit);
    gem.SetIsHitChest(isHit);

    if (isHit)
    {
        // 当たった宝石の種類を知る
        chest.SetHitGemType(gem.GetGemType());
    }

    return isHit;
}


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
bool Collision::IsHitObject2DBOX(VECTOR pos1, VECTOR pos2, float width1, float height1, float width2, float height2)
{
    // 当たったか、当たっていないか
    bool isHit = false;

    // オブジェクト同士の当たり判定
    // バフ分の当たり判定をわかりやすくする
    // 対象物１
    VECTOR	obj1Pos = pos1;
    float	obj1Width = width1;
    float	obj1Height = height1;
    float chestLeft = obj1Pos.x - obj1Width * OBJECT_HIT_BUF;
    float chestRight = obj1Pos.x + obj1Width * OBJECT_HIT_BUF;
    float chestTop = obj1Pos.y - obj1Height * OBJECT_HIT_BUF;
    float chestBottom = obj1Pos.y + obj1Height * OBJECT_HIT_BUF;
    // 宝石
    VECTOR	obj2Pos = pos2;
    int		obj2Width = width2;
    int		obj2Height = height2;
    float gemLeft = obj2Pos.x - obj2Width * OBJECT_HIT_BUF;
    float gemRight = obj2Pos.x + obj2Width * OBJECT_HIT_BUF;
    float gemTop = obj2Pos.y - obj2Height * OBJECT_HIT_BUF;
    float gemBottom = obj2Pos.y + obj2Height * OBJECT_HIT_BUF;

    // 当たり判定
    if (((gemLeft <= chestLeft && chestLeft < gemRight) ||
        (gemLeft > chestLeft && gemLeft < chestRight)) &&
        ((gemTop <= chestTop && chestTop < gemBottom) ||
            (gemTop > chestTop && gemTop < chestBottom)))
    {
        // 当たっている
        isHit = true;
    }

    // 当たっているか否か
    return isHit;

}



