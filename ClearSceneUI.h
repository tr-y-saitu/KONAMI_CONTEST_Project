#pragma once
#include "DxLib.h"

/// <summary>
/// クリアシーンUI
/// </summary>
class ClearSceneUI
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
    void Draw();


private:
    // 定数
    const int UI_COLOR = GetColor(200, 200, 200);

    // 変数
    int     clearUIGraph;       // クリアした時のUI画像

};


