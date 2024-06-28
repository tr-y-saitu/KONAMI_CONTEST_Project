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

    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw(int highScore);
        
private:
    const int UI_COLOR_WHITE = GetColor(255, 255, 255); // UIの色
    static const int UI_FONT_SIZE = 80;                 // UIのフォントサイズ

    int titileGraph;            // タイトル画像
};


