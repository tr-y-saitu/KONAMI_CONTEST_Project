﻿#include "DxLib.h"
#include "EffekseerForDXLib.h"
#include "EffectManager.h"

// 初期化
EffectManager* EffectManager::effectManager = NULL;

/// <summary>
/// コンストラクタ
/// </summary>
EffectManager::EffectManager()
    :   playingEffectHandle     (0)
    ,   gemGetEffect            (-1)
    ,   playerHitEffect         (-1)
{
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

    // DXライブラリのデバイスロストした時のコールバックを設定する。
    // ウインドウとフルスクリーンの切り替えが発生する場合は必ず実行する。
    // ただし、DirectX11を使用する場合は実行する必要はない。
    Effekseer_SetGraphicsDeviceLostCallbackFunctions();

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

/// <summary>
/// デストラクタ
/// </summary>
EffectManager::~EffectManager()
{
	// エフェクトリソースを削除する。(Effekseer終了時に破棄されるので削除しなくてもいい)
}

/// <summary>
/// エフェクトの読み込み
/// </summary>
void EffectManager::LoadEffect()
{
    // エフェクトのロード
    gemGetEffect = LoadEffekseerEffect("data/effect/GemGetUpEffect.efk", 2.3f);
    playerHitEffect = LoadEffekseerEffect("data/effect/GemHitEffectStar60Frame.efk", 0.5f);
    pirateShipBurnsSmallEffect = LoadEffekseerEffect("data/effect/GameScene/fireEffect.efk",1.0f);
    pirateShipBurnsMediumEffect = LoadEffekseerEffect("data/effect/GameScene/Fire2.efk", 1.0f);
    pirateShipExplosionEffect = LoadEffekseerEffect("data/effect/GameScene/Explosion.efk", 1.0f);
    pirateShipBigExplosionEffect = LoadEffekseerEffect("data/effect/GameScene/flamesEffect.efk", 5.0f);
    thunderEffect = LoadEffekseerEffect("data/effect/GameScene/ThunderLOD50.efk", 10.0f);
    fireWorksEffect = LoadEffekseerEffect("data/effect/FireWorks/FireWorks.efk", 1.0f);
    // エフェクトリストに書き込み
    effectList[GEM_GET_EFFECT] = gemGetEffect;
    effectList[PLAYER_HIT_EFFECT] = playerHitEffect;
    effectList[PIRATE_SHIP_BURNS_SMALL_EFFECT] = pirateShipBurnsSmallEffect;
    effectList[PIRATE_SHIP_BURNS_MEDIUM_EFFECT] = pirateShipBurnsMediumEffect;
    effectList[PIRATE_SHIP_EXPLOSION_EFFECT] = pirateShipExplosionEffect;
    effectList[PIRATE_SHIP_BIG_EXPLOSION_EFFECT] = pirateShipBigExplosionEffect;
    effectList[THUNDER_EFFECT] = thunderEffect;
    effectList[FIRE_WORKS_EFFECT] = fireWorksEffect;
}

/// <summary>
/// インスタンスを作成
/// </summary>
void EffectManager::CreateInstance()
{
    if (effectManager == NULL)
    {
        effectManager = new EffectManager();
    }
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
/// 初期化
/// </summary>
void EffectManager::Initialize()
{
    //// 再生中のエフェクトを削除する
    for (int i = playingList.size() - 1; i >= 0; i--)
    {
        // 再生中か調べる
        if (!IsEffekseer3DEffectPlaying(playingList[i]))
        {
            StopEffekseer3DEffect(playingList[i]);      // 停止
            playingList.erase(playingList.begin() + i); // 削除
        }
    }
}

/// <summary>
/// 更新
/// </summary>
void EffectManager::Update()
{
    // エフェクトが終了したら、再生中から削除する
    for (int i = 0; i < playingList.size(); i++)
    {
        // 再生中か調べる
        if (IsEffekseer3DEffectPlaying(playingList[i]) == NO_PLAY)
        {
            playingList.erase(playingList.begin());
        }
    }
}

/// <summary>
/// 現在再生中のエフェクトがあるかどうか
/// </summary>
/// <returns>ある:true  ない:false</returns>
bool EffectManager::IsAnyEffectPlaying()
{
    bool isPlaying = false;

    for (int i = 0; i < playingList.size(); i++)
    {
        // 再生中か調べる
        if (IsEffekseer3DEffectPlaying(playingList[i]) == PLAY)
        {
            isPlaying = true;
        }
    }

    return isPlaying;
}

/// <summary>
/// 読み込んだエフェクトリストから再生
/// </summary>
/// <param name="effectType">再生するエフェクトの種類</param>
/// <param name="playPosition">再生する座標</param>
/// <param name="scale">※エフェクトの描画サイズ</param>
/// NOTE:第3引数の「scale」はデフォルト引数　デフォルト値{1.0f,1.0f,1.0f}
///      1.0fが読み込み時サイズ
void EffectManager::PlayEffectList(EFFECT_TYPE effectType,VECTOR playPosition, VECTOR scale)
{
    // 再生するエフェクトを設定
    playingEffectHandle = effectList[effectType];

    // 再生するエフェクトの拡大率を設定
    SetScalePlayingEffekseer3DEffect(playingEffectHandle, scale.x, scale.y, scale.z);

    // エフェクトを再生
    PlayEffekseer3DEffect(playingEffectHandle);

    // 再生中リストに追加
    playingList.push_back(playingEffectHandle);

    // エフェクトの描画座標を設定
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
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

/// <summary>
/// 宝石が地面に落ちてしまった時のエフェクト
/// </summary>
/// <param name="playPosition">再生する座標</param>
void EffectManager::PlayGemFallEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(gemFallEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}

/// <summary>
/// 海賊船が燃えるエフェクト（小）を再生
/// </summary>
/// <param name="playPosition">再生する座標</param>
void EffectManager::PlayPirateShipBurnsSmallEffect(VECTOR playPosition, VECTOR scale)
{
    SetScalePlayingEffekseer3DEffect(playingEffectHandle,scale.x, scale.y, scale.z);
    playingEffectHandle = PlayEffekseer3DEffect(pirateShipBurnsSmallEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}

/// <summary>
/// 海賊船が燃えるエフェクト（中）を再生
/// </summary>
/// <param name="playPosition">再生する座標</param>
void EffectManager::PlayPirateShipBurnsMediumEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(pirateShipBurnsMediumEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}

/// <summary>
/// 海賊船が爆発するエフェクトを再生
/// </summary>
/// <param name="playPosition">再生する座標</param>
void EffectManager::PlayPirateShipExplosionEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(pirateShipExplosionEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}

/// <summary>
/// 海賊船が大爆発するエフェクトを再生
/// </summary>
/// <param name="playPosition">再生する座標</param>
void EffectManager::PlayPirateShipBigExplosionEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(pirateShipBigExplosionEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}

/// <summary>
/// 雷のエフェクトを再生
/// </summary>
/// <param name="playPosition"></param>
void EffectManager::PlayThunderEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(thunderEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}

/// <summary>
/// 花火のエフェクト再生
/// </summary>
void EffectManager::PlayFireWorksEffect(VECTOR playPosition)
{
    playingEffectHandle = PlayEffekseer3DEffect(fireWorksEffect);
    playingList.push_back(playingEffectHandle);
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);
}
