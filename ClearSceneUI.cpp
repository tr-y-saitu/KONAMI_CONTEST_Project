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
void ClearSceneUI::Draw(int score, int highScore)
{
    // クリアUI
    DrawGraph(0, 0, clearUIGraph, true);

    // クリア文字
    DrawFormatString(300, 200, UI_COLOR, "ゲームクリア！");
    DrawFormatString(300, 300, UI_COLOR, "SCORE : %d", score);
    DrawFormatString(300, 400, UI_COLOR, "HIGHSCORE : %d", highScore);



}
