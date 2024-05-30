#include "Game.h"
#include "Player.h"
#include "UI.h"



/// <summary>
/// コンストラクタ
/// </summary>
UI::UI()
	:	menuGraph			(-1)
	,	titleGraph			(-1)
	,	timeLimitGraph		(-1)
	,	frameGraph			(-1)
	,	distanceTraveled	(-1)
	,	menuSentenceGraph	(-1)
	,	clearGraph			(-1)
	,	overGraph			(-1)
	,	playSentenceGraph	(-1)
	,	greatGraph			(-1)
	,	bloodGraph			(-1)
	,	bloodPosY			(0)
	,	clearCount			(0)
	,	countMaxFlag		(false)
	
{
	// 処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
UI::~UI()
{
	// 処理なし
}


/// <summary>
/// 初期化
/// </summary>
void UI::Initialize()
{
	if (menuGraph < 0)
	{
		menuGraph = LoadGraph("data/texture/Menu/GemPiratesMenuGraph.png");
	}
	if (titleGraph < 0)
	{
		titleGraph = LoadGraph("data/texture/JUMP&JUMP.png");
	}
	if (menuSentenceGraph < 0)
	{
		menuSentenceGraph = LoadGraph("data/texture/SPACEでゲームスタート！.png");
	}
	if (clearGraph < 0)
	{
		clearGraph = LoadGraph("data/texture/GameClearImg.png");
	}
	if (overGraph < 0)
	{
		overGraph = LoadGraph("data/texture/GameOverImg.png");
	}
	if (playSentenceGraph < 0)
	{
		playSentenceGraph = LoadGraph("data/texture/説明枠.png");
	}
	if (greatGraph < 0)
	{
		greatGraph = LoadGraph("data/texture/GREAT.png");
	}
	if (bloodGraph < 0)
	{
		bloodGraph = LoadGraph("data/texture/blood1600x960.png");
	}

	distanceTraveled = 0;
	clearCount = 0;
}


/// <summary>
/// 描画
/// </summary>
void UI::Draw(int state, Player& player, bool clearFlag)
{

	int _uiColor = GetColor(200, 200, 200);
	// ステートごとに描画を変更
	switch (state)
	{
		// タイトル
	case STATE_MENU:

		// 文字を描画
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Menu", true);

		// タイトル背景の描画
		DrawGraph(0, 0, menuGraph, true);

		break;

		// ゲーム中
	case STATE_GAME:
		


		break;

		// クリア画面
	case STATE_CLEAR:

		// クリア文字
		DrawRotaGraph(800, 400, 1, 0, clearGraph, true);
		// 表示
		SetFontSize(100);
		DrawFormatString(300, 700, GetColor(255, 255, 255), "SPACEでメニューへ", true);

		break;

		// ゲームオーバー
	case STATE_GAMEOVER:

		// ゲームオーバー文字
		DrawRotaGraph(800, 400, 1, 0, overGraph, true);
		// 表示
		SetFontSize(100);
		DrawFormatString(300, 700, GetColor(255, 255, 255), "SPACEでメニューへ", true);
		break;

	default:
		break;
	}



}
