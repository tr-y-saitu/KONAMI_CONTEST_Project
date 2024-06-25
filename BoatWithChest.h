#pragma once
#include "StageObjectBase.h"

/// <summary>
/// 宝箱が乗っているボート
/// </summary>
class BoatWithChest : public StageObjectBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    BoatWithChest();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~BoatWithChest();

    /// <summary>
    /// 更新
    /// </summary>
    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

private:

};


