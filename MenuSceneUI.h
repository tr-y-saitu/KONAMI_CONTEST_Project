#pragma once
#include "SceneUIBase.h"

/// <summary>
/// メニューシーンUI
/// </summary>
class MenuSceneUI : public SceneUIBase
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    MenuSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~MenuSceneUI();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:
    int titileGraph;            // タイトル画像
};


