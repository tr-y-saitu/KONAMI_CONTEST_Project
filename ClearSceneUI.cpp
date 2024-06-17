#include "DxLib.h"
#include "ClearSceneUI.h"


/// <summary>
/// コンストラクタ
/// </summary>
ClearSceneUI::ClearSceneUI()
{
    clearUIGraph = LoadGraph("data/texture/Clear/ClearUIGraph.png");
}

/// <summary>
/// デストラクタ
/// </summary>
ClearSceneUI::~ClearSceneUI()
{
}


/// <summary>
/// 描画
/// </summary>
void ClearSceneUI::Draw()
{
    // クリアUI
    DrawGraph(0, 0, clearUIGraph, true);

    // クリア文字
    DrawFormatString(100, 100, UI_COLOR, "CLEAR_STATE");
}
