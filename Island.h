#pragma once
#include "Common.h"

/// <summary>
/// 島
/// </summary>
class Island
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Island();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Island();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:
    int     modelHandle;        // モデルハンドル
    VECTOR  position;           // 座標
    VECTOR  scale;              // スケール
};

