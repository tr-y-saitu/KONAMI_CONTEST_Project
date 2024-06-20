#pragma once
#include "DxLib.h"
#include "SceneUIBase.h"

/// <summary>
/// クリアシーンUI
/// </summary>
class ClearSceneUI : public SceneUIBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    ClearSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ClearSceneUI();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw(int score,int highScore);


private:
    // 定数
    const int UI_COLOR = GetColor(200, 200, 200);

    // 変数
    int     clearUIGraph;       // クリアした時のUI画像
};


