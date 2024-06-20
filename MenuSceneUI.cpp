#include "Common.h"
#include "MenuSceneUI.h"


/// <summary>
/// コンストラクタ
/// </summary>
MenuSceneUI::MenuSceneUI()
{
    titileGraph = LoadGraph("data/texture/Menu/GemPiratesMenuGraph.png");
}

/// <summary>
/// デストラクタ
/// </summary>
MenuSceneUI::~MenuSceneUI()
{
    DeleteGraph(titileGraph);
}

/// <summary>
/// 描画
/// </summary>
void MenuSceneUI::Draw(int highScore)
{
    // メニュー画像（タイトル画像の描画）
    DrawGraph(0, 0, titileGraph, true);

    // キー入力指示
    SetFontSize(90);
    DrawFormatString(200, SCREEN_SIZE_Y - 300, GetColor(255, 255, 255), "Press Any Button to Start");

    // スコア描画
    DrawFormatString(450, 500, UI_COLOR_WHITE, "HIGHSCORE : %d", highScore);
}


