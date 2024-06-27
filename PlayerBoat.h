#pragma once
#include "Common.h"

/// <summary>
/// プレイヤーの乗るボート
/// </summary>
class PlayerBoat
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayerBoat();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PlayerBoat();

    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="playerPosition">プレイヤーの座標</param>
    void Update(VECTOR playerPosition);

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:
    int modelHandle;
    VECTOR position;
    VECTOR scale;
};


