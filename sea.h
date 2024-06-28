#pragma once
#include "Common.h"
#include "StageObjectBase.h"

/// <summary>
/// 海
/// </summary>
class Sea : public StageObjectBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Sea();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Sea();

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

