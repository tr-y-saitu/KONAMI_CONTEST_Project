﻿#include "DxLib.h"
#include "EffekseerForDXLib.h"
#include "EffectManager.h"

// 初期化
EffectManager* EffectManager::effectManager = NULL;

/// <summary>
/// コンストラクタ
/// </summary>
EffectManager::EffectManager()
	:	effectResourceHandle	(0)
	,	graphBackGroundHandle	(0)
	,	graphFrontHandle		(0)
	,	time					(0)
	,	isFullScreen			(false)
	,	playingEffectHandle		(0)
    ,   gemGetEffect            (-1)
    ,   playerHitEffect         (-1)
{
	pos = VGet(0, 0, 0);
    // DirectX11を使用するようにする。(DirectX9も可、一部機能不可)
    // Effekseerを使用するには必ず設定する。
    //DirectX11のバージョンを指定
    SetUseDirect3DVersion(DX_DIRECT3D_11);

    // 引数には画面に表示する最大パーティクル数を設定する。
    if (Effkseer_Init(20000) == -1)
    {
        DxLib_End();
    }

    // フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
    // Effekseerを使用する場合は必ず設定する。
    SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

    // Zバッファを有効にする。
    // Effekseerを使用する場合、2DゲームでもZバッファを使用する。
    SetUseZBuffer3D(TRUE);

    // Zバッファへの書き込みを有効にする。
    // Effekseerを使用する場合、2DゲームでもZバッファを使用する。
    SetWriteZBuffer3D(TRUE);

    //EffekseerSyncronizDxlib();

    // 使用エフェクトを読み込み
    LoadEffect();
}

EffectManager::~EffectManager()
{
	// エフェクトリソースを削除する。(Effekseer終了時に破棄されるので削除しなくてもいい)
	DeleteEffekseerEffect(gemGetEffect);
	DeleteEffekseerEffect(playerHitEffect);
}

/// <summary>
/// エフェクトの読み込み
/// </summary>
void EffectManager::LoadEffect()
{
    gemGetEffect = LoadEffekseerEffect("data/effect/getEffectLight.efk", 0.3f);
    playerHitEffect = LoadEffekseerEffect("data/effect/playerHitEffect波紋.efk", 2.0f);
}

/// <summary>
/// インスタンスを作成
/// </summary>
void EffectManager::CreateInstance()
{
    effectManager = new EffectManager();
}

/// <summary>
/// エフェクトマネージャーのインスタンスのポインタを渡す
/// </summary>
/// <returns>EffectManagerのポインタ</returns>
EffectManager* EffectManager::GetInstance()
{
    return effectManager;
}

/// <summary>
/// エフェクトマネージャーの削除
/// </summary>
void EffectManager::DeleteInstance()
{
    delete(effectManager);
}

/// <summary>
/// 宝石獲得エフェクト
/// </summary>
/// <param name="playPosition">再生する座標</param>
void EffectManager::PlayGemGetEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(gemGetEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x,playPosition.y,playPosition.z);
}

/// <summary>
/// プレイヤーが宝石に当たった時のエフェクト
/// </summary>
/// <param name="playPosition">再生する座標</param>
void EffectManager::PlayPlayerHitEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(playerHitEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}