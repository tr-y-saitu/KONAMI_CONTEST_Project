#include "DxLib.h"
#include "MenuSceneUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
MenuSceneUI::MenuSceneUI()
{
    menuGraph = LoadGraph("data/texture/Menu/GemPiratesMenuGraph.png");
}

/// <summary>
/// デストラクタ
/// </summary>
MenuSceneUI::~MenuSceneUI()
{
    DeleteGraph(menuGraph);
}

/// <summary>
/// 描画
/// </summary>
void MenuSceneUI::Draw()
{
    // メニュー画像（タイトル画像の描画）
    DrawGraph(0, 0, menuGraph, true);
}


