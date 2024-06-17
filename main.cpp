//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
// 標準ライブラリ
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "math.h"
// 追加外部ライブラリ
#include "DxLib.h"
//#include "EffekseerForDXLib.h"
// 自作ヘッダー
#include "GemManager.h"
#include "TreasureChest.h"
#include "Calculation.h"
#include "Enemy.h"
#include "Player.h"
#include "Camera.h"
#include "Collision.h"
#include "Effekseer.h"
#include "FPSSetting.h"
#include "Room.h"
#include "Gem.h"
// シーン
#include "SceneBase.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "ClearScene.h"
#include "OverScene.h"

// Game.hの上にすべての自作ヘッダーをインクルードする
#include "Game.h"




//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	// DXライブラリの表示方法をウィンドウモードに変更する。
	ChangeWindowMode(true);	// ウィンドウモード
	//ChangeWindowMode(false);// 全画面モード

	//描画先を裏画面に変更する。
	SetDrawScreen(DX_SCREEN_BACK);

	// DirectX11を使用するようにする。(DirectX9も可、一部機能不可)
	// Effekseerを使用するには必ず設定する。
	//SetUseDirect3DVersion(DX_DIRECT3D_11);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)		
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// Effekseerを初期化する。
	// 引数には画面に表示する最大パーティクル数を設定する。
	/*if (Effekseer_Init(8000) == -1)
	{
		DxLib_End();
		return -1;
	}*/

	// 画面モードのセット
	SetGraphMode(1600, 960, 32);
	//SetGraphMode(160, 60, 32);

	// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
	// Effekseerを使用する場合は必ず設定する。
	//SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	// DXライブラリのデバイスロストした時のコールバックを設定する。
	// ウインドウとフルスクリーンの切り替えが発生する場合は必ず実行する。
	// ただし、DirectX11を使用する場合は実行する必要はない。
	//Effekseer_SetGraphicsDeviceLostCallbackFunctions();

	// Effekseerに2D描画の設定をする。
	//Effekseer_Set2DSetting(1600, 960);


	// Zバッファを有効にする。
	// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	//SetUseZBuffer3D(TRUE);

	// Zバッファへの書き込みを有効にする。
	// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	//SetWriteZBuffer3D(TRUE);

	// 2.5Dに対応するための処理
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBufferFlag(TRUE);
	SetWriteZBufferFlag(TRUE);
	SetUseBackCulling(TRUE);

	// インスタンス化
	Game* game = new Game();

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// FPS処理
		auto _prevTime = GetNowHiPerformanceCount();

        // ゲームループ
        game->Update();

		// FPS処理
   		auto _afterTime = GetNowHiPerformanceCount();

		while (_afterTime - _prevTime < 16667)
		{
			_afterTime = GetNowHiPerformanceCount();
		}

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// マイナスの値（エラー値）が返ってきたらループを抜ける
		if (ProcessMessage() < 0)
		{
			break;
		}
		// もしＥＳＣキーが押されていたらループから抜ける
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	// Effekseerを終了する。
	//Effkseer_End();

	// ＤＸライブラリの後始末
 	DxLib_End();

	// ソフトの終了
	return 0;
}
