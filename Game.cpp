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
	: isHitCount(0)
	, isClearCount(0)
	, isClearFlag(false)
	, nowTimer(0)
	, isDrawGetUI(false)
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
	for (int i = 0; i < GEM_TOTAL_NUM; i++)
	{
		gem.push_back(new Gem());
	}
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
	for (int i = 0; i < GEM_TOTAL_NUM; i++)
	{
		delete(gem[i]);
	}

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
	for (int i = 0; i < gem.size(); i++)
	{
		gem[i]->Initialize(VGet(i, 0, -5), *gemManager);
	}
	//effekseer1->Initialize();

	// ゲームが始まる前のGetNowCountを取得
	previousTime = GetNowHiPerformanceCount();

	gameFrameCount = 0;			// フレームカウントの初期化
	isDrawGetUI = false;		// 宝石をゲットした時のUI演出をするかどうか

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

	player->Initialize();
	//enemy->Initialize();
	ui->Initialize();
	skyDome->Initialize();
	room->Initialize();
	treasureChest->Initialize();
	for (int i = 0; i < gem.size(); i++)
	{
		gem[i]->Initialize(VGet(i - 10, 10, -5), *gemManager);
	}
	//effekseer1->Initialize();
}




/// <summary>
/// ゲームステート切り替え
/// </summary>
void Game::ChangeGameState()
{
	// 即座に切り替わりすぎるので、ちょっと時間を止める
	WaitTimer(500);

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

		// ゲームフレームを数える
		CountGameFraem();

		// ゲームアップデート
		// 当たり判定処理
		//collision->HitPlayerToEnemy(*player, *enemy);	// プレイヤーとエネミーの当たり判定
		for (int i = 0; i < gem.size(); i++)
		{
			// プレイヤーと宝石の当たり判定処理
			collision->IsHitPlayerToGem(*player, *gem[i]);

			// 宝石と宝箱の当たり判定処理
			//collision->IsHitGemToTreasureChest(*gem[i],*treasureChest);

			// 宝石と宝箱の当たり判定処理(bool型返り値)
			if (collision->IsHitGemToTreasureChestBool(*gem[i], *treasureChest))
			{
				// UIを描画する指示を出す
				isDrawGetUI = true;
				break;
			}
		}
		// 「GET!」のモデルを描画
		ui->SetIsHitGemToChest(isDrawGetUI);

		// キャラクター更新
		player->Update(*enemy);	// プレイヤー

		// カメラ更新
		camera->Update(*player);

		// オブジェクト更新
		skyDome->Update();		// 背景
		room->Update();			// 部屋
		for (int i = 0; i < gem.size(); i++)
		{
			gem[i]->Update(calculation);	// 宝石
			treasureChest->Update(*gem[i]);	// 宝箱更新
		}

		// 効果関係更新
		//effekseer1->Update();

		// 制限時間が経過したら
		if (nowTimer >= 90)
		{
			// クリアした
			isClearFlag = true;

			// クリアしてからのカウント
			isClearCount++;

			if (isClearCount >= 100)
			{
				gameState = STATE_CLEAR;
				ChangeGameState();
			}
		}

		break;

		// クリア /////////////////////////////////////////
	case STATE_CLEAR:

		// キー入力されたら
		if (keyRelease)
		{
			gameState = STATE_MENU;
			ChangeGameState();
		}
		break;

		// ゲームオーバー ///////////////////////////////
	case STATE_GAMEOVER:

		// キー入力されたら
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
	timer = (GetNowHiPerformanceCount() - previousTime);
	int _nowTimer = (timer % 1000000000) / 1000000;				// 一桁の秒数
	nowTimer = (timer % 1000000000) / 1000000;
	char timerStr[256];
	sprintf_s(timerStr, "TIME: %d / 90", _nowTimer);
	DrawString(850, 0, timerStr, _color, true);
	nowTimer = _nowTimer;

	// 20秒経過ごとに(_nowTimerが０ではないとき。開始直後の時は無視)
	if (_nowTimer % 20 == 0 && _nowTimer != 0)
	{
		char _timeCount[256];
		sprintf_s(_timeCount, "～～～%d秒経過～～～", _nowTimer);
		DrawString(250, 400, _timeCount, GetColor(255, 100, 100), true);
	}
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
		//skyDome->Draw();
		player->Draw(gameFrameCount);			// プレイヤー
		room->Draw();							// 部屋
		for (int i = 0; i < gem.size(); i++)	// 宝石
		{
			gem[i]->Draw();
		}
		treasureChest->Draw();					// 宝箱
		//DrawTimer();							// 制限時間
	}

	// UI描画
	ui->Draw(GetGameState(), *player, isDrawGetUI, *treasureChest);

	// エフェクトの再生
	//effekseer1->Draw();
}



