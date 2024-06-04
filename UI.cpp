#include "Game.h"
#include "Player.h"
#include "TreasureChest.h"
#include "UI.h"



/// <summary>
/// コンストラクタ
/// </summary>
UI::UI()
	: menuGraph(-1)
	, strGetModleHandel(-1)
	, isHitGemToChest(false)
	, strGetDrawCount(0)
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
	isHitGemToChest = false;
	strGetDrawCount = 0;
}


/// <summary>
/// UIの描画
/// </summary>
/// <param name="state">ゲームステート</param>
/// <param name="player">プレイヤークラス</param>
/// <param name="isDrawUIFlag">UIを描画する指示</param>
/// <param name="chest">宝箱クラス</param>
void UI::Draw(int state, Player& player, bool& isDrawUIFlag, TreasureChest& chest)
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

		// 「GET!」モデルの座標を設定
		MV1SetPosition(strGetModleHandel, VGet(0, 0, 0));

		// 宝石と宝箱が接触したら(描画指定時間を超えていなければ)
		if (isHitGemToChest && strGetDrawCount <= STRING_GET_DRAW_TIME)
		{
			// 「GET!」モデルを描画する時間を進める
			strGetDrawCount++;
			// 3Dモデル描画
			MV1DrawModel(strGetModleHandel);
		}
		// 描画指定時間を超えたらゼロに戻す
		if (strGetDrawCount >= STRING_GET_DRAW_TIME)
		{
			// UIを描画する指示をオフにする
			isDrawUIFlag = false;
			// 描画指定時間をゼロにする
			strGetDrawCount = 0;
			// 宝石と宝箱は当たっていない
			isHitGemToChest = false;
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
