#pragma once
#include "Common.h"

/// <summary>
/// ステージに配置するオブジェクトのベース
/// </summary>
class StageObjectBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    StageObjectBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~StageObjectBase();

    /// <summary>
    /// 更新
    /// </summary>
    virtual void Update() abstract;

    /// <summary>
    /// 描画
    /// </summary>
    virtual void Draw() abstract;

protected:
    int modelHandle;        // モデルハンドル
    VECTOR position;        // 座標
    VECTOR scale;           // 拡大率
};


