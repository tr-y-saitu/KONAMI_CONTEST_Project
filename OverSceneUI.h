#pragma once
#include "SceneUIBase.h"

/// <summary>
/// オーバーシーンUI
/// </summary>
class OverSceneUI : public SceneUIBase
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    OverSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~OverSceneUI();

    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:


};

