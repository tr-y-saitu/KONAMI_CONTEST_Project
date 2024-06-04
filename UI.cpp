#include "Game.h"
#include "Player.h"
#include "TreasureChest.h"
#include "UI.h"



/// <summary>
/// コンストラクタ
/// </summary>
UI::UI()
	:	menuGraph			(-1)
	,	strGetModleHandel	(-1)
{
	strGetModleHandel = MV1LoadModel("data/model/UI/GET!.mv1");
	MV1SetScale(strGetModleHandel, VGet(0.05f, 0.05f, 0.0f));
}

/// <summary>
/// デストラクタ
/// </summary>
UI::~UI()
{
	// 3Dモデルハンドルの削除
	MV1DeleteModel(strGetModleHandel);
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
}



/// <summary>
/// 描画
/// </summary>
void UI::Draw(int state, Player& player, bool clearFlag,TreasureChest& chest)
{
	int _uiColor = GetColor(200, 200, 200);
	// ステートごとに描画を変更
	switch (state)
	{
		// タイトル
	case STATE_MENU:

		// 文字を描画

		// タイトル背景の描画
		DrawGraph(0, 0, menuGraph, true);

		break;

		// ゲーム中
	case STATE_GAME:
		
		// 「GET!」モデルを描画
		MV1SetPosition(strGetModleHandel, VGet(0,0,0));
		if (isHitGemToChest)
		{
			MV1DrawModel(strGetModleHandel);
		}


		break;

		// クリア画面
	case STATE_CLEAR:

		// クリア文字
		// 表示

		break;

		// ゲームオーバー
	case STATE_GAMEOVER:

		// ゲームオーバー文字
		// 表示
		break;

	default:
		break;
	}
}
