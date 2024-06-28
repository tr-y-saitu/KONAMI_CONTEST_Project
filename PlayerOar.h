#pragma once
#include "Common.h"

/// <summary>
/// プレイヤーの持つオール
/// </summary>
class PlayerOar
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayerOar();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PlayerOar();

    /// <summary>
    /// 更新
    /// </summary>
    void Update(VECTOR playerPosition);

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    const int GetModelHandle() { return modelHandle; }
    const VECTOR GetPosition() { return position; }

    void SetPosition(const VECTOR set) { position = set; }

private:
    int modelHandle;
    VECTOR position;
    VECTOR scale;

};


