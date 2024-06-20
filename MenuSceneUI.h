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
    void Draw(int highScore);
        
private:
    const int UI_COLOR_WHITE = GetColor(255, 255, 255);

    int titileGraph;            // タイトル画像
};


