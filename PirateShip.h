#pragma once
#include "StageObjectBase.h"

/// <summary>
/// 海賊船
/// </summary>
class PirateShip : public StageObjectBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PirateShip();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PirateShip();

    /// <summary>
    /// 更新
    /// </summary>
    void Update() override;

    // 描画
    void Draw() override;

private:

};


