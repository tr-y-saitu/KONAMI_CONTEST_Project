// インクルードファイル

#include <stdio.h>
#include <iostream>
#include <vector>
#include "math.h"
#include "Calculation.h"
#include "Room.h"
#include "GemManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Collision.h"
#include "vector"
#include "UI.h"
#include "SkyDome.h"
#include "Gem.h"
#include "Confetti.h"
#include "TreasureChest.h"
#include "Effekseer.h"
#include "Game.h"


/// <summary>
/// コンストラクタ
/// </summary>
Game::Game()
	:	isHitCount		(0)
	,	isClearCount	(0)
	,	isClearFlag		(false)
	,	nowTimer		(0)
	,	isDrawGetUi		(false)
    ,   score           (0)
{
	// 変数の初期化
	gameState = STATE_MENU;
	gameFrameCount = 0;
	previousTime = 0;
	timer = 0;
	nowTimer = 0;
	keyOn = false;
	keyRelease = false;
	prevKeyOn = false;
	menuGraph = -1;
	// ベースモデルのロード
	modelHandleGemDia = MV1LoadModel("data/model/Gem/Diamonds.mv1");	// ダイア
	modelHandleGemRuby = MV1LoadModel("data/model/Gem/Ruby.mv1");	// ルビー
}

/// <summary>
/// デストラクタ
/// </summary>
Game::~Game()
{
}

/// <summary>
/// ゲームがスタートしてからのフレーム数を数える
/// </summary>
void Game::CountGameFraem()
{
	// ゲームフレームを数える
	gameFrameCount++;
}

/// <summary>
/// ゲームオブジェクトの生成
/// </summary>
void Game::Create()
{
	// 全オブジェクトの生成
	player = new Player();		// プレイヤー
	enemy = new Enemy();		// エネミー
	camera = new Camera();		// カメラ
	collision = new Collision();	// 当たり判定（コリジョン）
	ui = new UI();
	skyDome = new SkyDome();
	room = new Room();
	treasureChest = new TreasureChest();
	gemManager = new GemManager();
	//effekseer1 = new Effekseer1();
}

/// <summary>
/// 生成したオブジェクトの削除
/// </summary>
void Game::DeleteGame()
{
	// 削除
	delete(player);
	delete(enemy);
	delete(camera);
	delete(collision);
	delete(ui);
	delete(skyDome);
	delete(room);
	delete(treasureChest);
	delete(gemManager);
	//delete(effekseer1);
}


/// <summary>
/// ゲーム最初の初期化
/// </summary>
void Game::InitializeGameStart()
{
	// Effekseerを使用する
	//effekseer1->ReadyEffekseerForDXLib();

	// フォント設定
	ChangeFont("チョークS");

	isHitCount = 0;
	nowTimer = 0;

	// ３Ｄモデルの読み込み
	gemManager->LoadModle();		// 宝石のモデルロード

	// ゲームオブジェクトの初期化
	player->Initialize();
	ui->Initialize();
	skyDome->Initialize();
	room->Initialize();
	treasureChest->Initialize();
    // 宝石の初期化
    gemManager->Initialize();

	// エフェクシアを使用
	//effekseer1->Initialize();

	// ゲームが始まる前のGetNowCountを取得
	previousTime = GetNowHiPerformanceCount();

	gameFrameCount = 0;			// フレームカウントの初期化
	isDrawGetUi = false;		// 宝石をゲットした時のUI演出をするかどうか
}


/// <summary>
/// 初期化処理
/// </summary>
void Game::Initialize()
{
	// ゲームが始まる前のGetNowCountを取得
	previousTime = GetNowHiPerformanceCount();

	gameFrameCount = 0;
	nowTimer = 1;
	isHitCount = 0;
	isClearFlag = false;
	isClearCount = 0;
    score = 0;

	player->Initialize();
	ui->Initialize();
	skyDome->Initialize();
	room->Initialize();
	treasureChest->Initialize();
    gemManager->Initialize();
	
	//effekseer1->Initialize();
}




/// <summary>
/// ゲームステート切り替え
/// </summary>
void Game::ChangeGameState()
{
	// 即座に切り替わりすぎるので、ちょっと時間を止める
	//WaitTimer(500);

	// ステートが切り替わった瞬間、キーを離した判定をリセット
	keyOn = false;
	keyRelease = false;

	// ステート切り替え処理
	switch (gameState)
	{
		// タイトル
	case STATE_MENU:
		break;

		// ゲーム中
	case STATE_GAME:
		Initialize();
		break;

		// クリア画面
	case STATE_CLEAR:
		break;

		// ゲームオーバー
	case STATE_GAMEOVER:
		break;

	default:
		break;
	}


}

/// <summary>
/// アップデートゲーム
/// </summary>
void Game::UpdateGame()
{
	// キー入力処理
	ProcessKey();

    // 現在の宝石の数を調べる
    int _gemSize = gem.size();
    auto _scoreUpFlag = false;
    auto _gemType = 0;

	// ステートごとに処理を分ける
    switch (gameState)
    {
        // メニュー //////////////////////////////////////
    case STATE_MENU:

        if (keyRelease)
        {
            gameState = STATE_GAME;
            ChangeGameState();
        }
        break;

        // ゲーム中 //////////////////////////////////////
    case STATE_GAME:
        // ゲームが開始してからの時間を計測
        SettingTimer(*gemManager);

        // ゲームフレームを数える
        CountGameFraem();

        // ゲームアップデート
        // 当たり判定処理
        _scoreUpFlag = gemManager->IsCollisionGem(*player, *treasureChest, *collision);
        if (_scoreUpFlag)
        {
            // 当たった時の演出を出す指令をセット
            ui->SetIsHitGemToChest(true);

            // スコアをアップさせる
            UpdateScore(*treasureChest);
        }

        // キャラクター更新
        player->Update();	// プレイヤー

        // カメラ更新
        camera->Update();// カメラ

		// オブジェクト更新
		skyDome->Update();		                // 背景
		room->Update();			                // 部屋
        gemManager->UpdateWaveGem(nowTimer);    // 宝石
		treasureChest->Update();			    // 宝箱更新

        // データのリセットフラグがたったら宝石のデータをリセットさせる
        gemManager->ResetGemData();

        // STATE_GAMEの終了時間になったらSTATE_CLEARに移行
        if (nowTimer >= STATE_GAME_TIME_LIMIT)
        {
            gameState = STATE_CLEAR;
            ChangeGameState();
        }
         
		//effekseer1->Update();
		
		break;

	// クリア /////////////////////////////////////////
	case STATE_CLEAR:

        // 宝石を出してみる
        gemManager->UpdateWaveGem(nowTimer);

		//　スペースKey入力でSTATE_MENUに移行
		if (keyRelease)
		{
			gameState = STATE_MENU;
			ChangeGameState();
		}
		break;

	// ゲームオーバー ///////////////////////////////
	case STATE_GAMEOVER:

		// スペースKey入力でSTATE_MENUに移行
		if (keyRelease)
		{
			gameState = STATE_MENU;
			ChangeGameState();
		}
		break;

	default:
		break;
	}
}


/// <summary>
/// ゲーム進行にかかわるキー入力
/// </summary>
void Game::ProcessKey()
{
	// キーを離した瞬間をとる
	if (keyOn)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 0)
		{
			keyOn = false;
			keyRelease = true;
		}
	}
	else if (prevKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		keyRelease = false;
		keyOn = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		prevKeyOn = true;
	}
	else
	{
		prevKeyOn = false;
	}

}

/// <summary>
/// 制限時間の描画
/// </summary>
void Game::DrawTimer()
{
	// フォントサイズ設定
	SetFontSize(100);

	// 色保持
	int _color = GetColor(200, 200, 200);

	// 時間を保持する
	timer = (GetNowHiPerformanceCount() - previousTime);		// 現在時間 - 最初の計測時間
	int _nowTimer = (timer % 1000000000)/1000000;				// 一桁の秒数
	nowTimer = (timer % 1000000000) / 1000000;
	char timerStr[256];
	sprintf_s(timerStr, "TIME: %d / 90", _nowTimer);
	DrawString(850, 0, timerStr, _color, true);
	nowTimer = _nowTimer;
	
	// 20秒経過ごとに(_nowTimerが０ではないとき。開始直後の時は無視)
	if (_nowTimer % 20 == 0 && _nowTimer != 0)
	{
		char _timeCount[256];
		sprintf_s(_timeCount, "～～～%f秒経過～～～", nowTimer);
		DrawString(250, 400, _timeCount, GetColor(255,100,100), true);
	}
}


/// <summary>
/// 現在経過時間の更新
/// </summary>
/// <param name="resetFlag">計測時間をリセットするかどうかのフラグ</param>
void Game::SettingTimer(GemManager& gemManager)
{
    //  時間をリセットするフラグがたったら
    if (gemManager.GetResetTimer())
    {
        // 経過時間をリセット
        previousTime = GetNowHiPerformanceCount();
        // フラグをおろす
        gemManager.SetResetTimer(false);
    }

	// 現在時間 - 最初の計測時間
	timer = (GetNowHiPerformanceCount() - previousTime);
	// 現在経過時間（１桁表示）
	nowTimer = (timer % 1000000000) / 1000000;
}


/// <summary>
/// ゲームの描画
/// </summary>
void Game::DrawGame()
{
	if (gameState == STATE_MENU)
	{
		
	}
	if (gameState == STATE_GAME)
	{
		player->Draw();	                // プレイヤー
		room->Draw();					// 部屋
        gemManager->DrawGems();         // 複数の宝石
		treasureChest->Draw();			// 宝箱
	}
    if (gameState == STATE_CLEAR)
    {
        room->Draw();					// 部屋
        gemManager->DrawGems();         // 複数の宝石
        treasureChest->Draw();			// 宝箱
    }

	// UI描画
    ui->Draw(gameState, score, nowTimer, gemManager->GetGemWaveState(),isBlackOutFlag);

	// エフェクトの再生
	//effekseer1->Draw();
}

/// <summary>
/// スコアの更新
/// </summary>
/// <param name="chest">宝箱</param>
void Game::UpdateScore(TreasureChest& chest)
{
    // 当たった宝石の種類を確認
    auto _hitGemType = chest.GetHitGemType();

    // スコアを計算
    score += (_hitGemType + 1) * 100;
}

