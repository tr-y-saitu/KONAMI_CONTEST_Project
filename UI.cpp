﻿#include "Game.h"
#include "Player.h"
#include "TreasureChest.h"
#include "Gem.h"
#include "GemManager.h"
#include "UI.h"



/// <summary>
/// コンストラクタ
/// </summary>
UI::UI()
	:	menuGraph			        (-1)
	,	getDirectionModelHandle	(-1)
	,	isHitGemToChest             (false)
    ,   getDirectionCount       (0)
{
	getDirectionModelHandle = MV1LoadModel("data/model/UI/GET!.mv1");
	MV1SetScale(getDirectionModelHandle, VGet(0.05f, 0.05f, 0.0f));
    MV1SetRotationXYZ(getDirectionModelHandle, VGet(0, 25.0f * DX_PI_F / 180.0f, 0));
}

/// <summary>
/// デストラクタ
/// </summary>
UI::~UI()
{
	// 3Dモデルハンドルの削除
	MV1DeleteModel(getDirectionModelHandle);
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
/// UIの描画
/// </summary>
/// <param name="gameState">現在のゲームステート</param>
/// <param name="score">ゲームスコア</param>
/// <param name="nowTimer">現在の経過時間</param>
/// <param name="gemWaveState">現在の宝石のウェーブステート</param>
void UI::Draw(int gameState, int gameScore, float nowTimer, int gemWaveState)
{
    char _timeCount[256];					// ゲームの経過時間
    // ステートごとに描画を変更
    switch (gameState)
    {
        // タイトル
    case STATE_MENU:

        // 文字を描画

        // タイトル背景の描画
        DrawGraph(0, 0, menuGraph, true);

        break;

        // ゲーム中
    case STATE_GAME:
        // 現在の経過時間を描画
        sprintf_s(_timeCount, "～～～%f秒経過～～～", nowTimer);
        DrawString(250, 400, _timeCount, UI_COLOR, true);

        // 「GET!」モデルのポジションを設定
        MV1SetPosition(getDirectionModelHandle, VGet(1, 3, 1));

        // 宝石獲得演出(宝石が当たっているかつ演出時間ないである)
        if (isHitGemToChest && getDirectionCount <= GET_DIRECTION_DRAW_TIME)
        {
            // 演出時間を経過
            getDirectionCount++;

            // 演出用モデルの描画
            MV1DrawModel(getDirectionModelHandle);
        }
        // 描画指定時間を越えたらゼロに戻す
        if (getDirectionCount >= GET_DIRECTION_DRAW_TIME)
        {
            getDirectionCount = 0;
            isHitGemToChest = false;
        }

        // 現在のWAVEステートの描画
        switch (gemWaveState)
        {
        case GemManager::WAVE_FIRST:
            DrawFormatString(100, 100, UI_COLOR, "WAVE_FIRST");
            break;

        case GemManager::WAVE_SECOND:
            DrawFormatString(100, 100, UI_COLOR, "WAVE_SECOND");
            break;

        case GemManager::WAVE_THIRD:
            DrawFormatString(100, 100, UI_COLOR, "WAVE_THIRD");
            break;

        default:
            break;
        }

        // スコアの描画
        DrawScore(VGet(0, 0, 0), 20, gameScore);


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

/// <summary>
/// スコアの描画
/// </summary>
/// <param name="pos">スコアを描画する座標</param>
/// <param name="fontSize">フォントサイズ</param>
/// <param name="score">スコア</param>
void UI::DrawScore(VECTOR pos, int fontSize,int score)
{
    // フォントサイズの変更
    SetFontSize(fontSize);

    // スコアの描画
    DrawFormatString(pos.x, pos.y, UI_COLOR, "SCORE : %d", score);
}
