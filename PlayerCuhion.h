#pragma once
#include "Common.h"

/// <summary>
/// プレイヤーの持つクッション
/// </summary>
class PlayerCushion
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayerCushion();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PlayerCushion();

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


