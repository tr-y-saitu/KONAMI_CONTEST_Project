#pragma once
#include "EffekseerForDXLib.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/// <summary>
/// エフェクトマネージャー
/// </summary>
class EffectManager     final
{
public:
    /// <summary>
    /// 再生状態
    /// </summary>
    enum PLAY_STATE
    {
        NO_PLAY = -1,   // 再生されていない
        PLAY,           // 再生中
    };

    /// <summary>
    /// エフェクトの種類
    /// </summary>
    enum EFFECT_TYPE
    {
        GEM_GET_EFFECT,                     // 宝石をゲットした時
        PLAYER_HIT_EFFECT,                  // プレイヤーと宝石が当たった時
        PIRATE_SHIP_BURNS_SMALL_EFFECT,     // 海賊船炎上エフェクト(小)
        PIRATE_SHIP_BURNS_MEDIUM_EFFECT,    // 海賊船炎上エフェクト(中)
        PIRATE_SHIP_EXPLOSION_EFFECT,       // 海賊船が爆発するエフェクト
        PIRATE_SHIP_BIG_EXPLOSION_EFFECT,   // 海賊船が爆発するエフェクト(大)
        THUNDER_EFFECT,                     // 雷が落ちるエフェクト
        FIRE_WORKS_EFFECT,                  // 花火が上がるエフェクト
    };

	/// <summary>
	/// デストラクタ
	/// </summary>
	~EffectManager();

    /// <summary>
    /// インスタス作成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// エフェクトマネージャーのインスタンスのポインタを渡す
    /// </summary>
    /// <returns>EffectManagerのポインタ</returns>
    static EffectManager* GetInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// エフェクトの読み込み
    /// </summary>
    void LoadEffect();

    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 現在再生中のエフェクトがあるかどうか
    /// </summary>
    /// <returns></returns>
    bool IsAnyEffectPlaying();

    /// <summary>
    /// 読み込んだエフェクトリストから再生
    /// </summary>
    /// <param name="effectType">再生するエフェクトの種類</param>
    /// <param name="playPosition">再生する座標</param>
    /// <param name="scale">※エフェクトの描画サイズ</param>
    /// NOTE:第3引数の「scale」はデフォルト引数　デフォルト値{1.0f,1.0f,1.0f}
    ///      1.0fが読み込み時サイズ
    void PlayEffectList(EFFECT_TYPE effectType,VECTOR playPosition, VECTOR scale = {1.0f,1.0f,1.0f});

    /// <summary>
    /// 宝石獲得エフェクト
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayGemGetEffect(VECTOR playPosition);

    /// <summary>
    /// プレイヤーが宝石に当たった時のエフェクト
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayPlayerHitEffect(VECTOR playPosition);

    /// <summary>
    /// 宝石が地面に落ちてしまった時のエフェクト
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayGemFallEffect(VECTOR playPosition);

    /// <summary>
    /// 海賊船が燃えるエフェクト（小）を再生
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayPirateShipBurnsSmallEffect(VECTOR playPosition,VECTOR scale);

    /// <summary>
    /// 海賊船が燃えるエフェクト（中）を再生
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayPirateShipBurnsMediumEffect(VECTOR playPosition);

    /// <summary>
    /// 海賊船が爆発するエフェクトを再生
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayPirateShipExplosionEffect(VECTOR playPosition);

    /// <summary>
    /// 海賊船が大爆発するエフェクトを再生
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayPirateShipBigExplosionEffect(VECTOR playPosition);

    /// <summary>
    /// 雷のエフェクトを再生
    /// </summary>
    /// <param name="playPosition"></param>
    void PlayThunderEffect(VECTOR playPosition);

    /// <summary>
    /// 花火のエフェクト再生
    /// </summary>
    /// <param name="playPosition"></param>
    void PlayFireWorksEffect(VECTOR playPosition);

private:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EffectManager();

    // 管理用
    static EffectManager* effectManager;    // エフェクトマネージャーのインスタンス
    int playingEffectHandle;                // 現在再生中のエフェクトのハンドル
    vector<int> playingList;           // 現在再生中のリスト
    map< EFFECT_TYPE, int> effectList;      // 再生するエフェクトのリスト

    // ハンドル
    // 宝石とプレイヤー
    int     playerHitEffect;                // プレイヤーと宝石のヒット時
    // 宝石と宝箱
    int     gemGetEffect;                   // 宝石ゲット時
    int     gemFallEffect;                  // 宝石が落ちてしまった時
    // 海賊船
    int     pirateShipBurnsSmallEffect;     // 海賊船が燃えるエフェクト（小）
    int     pirateShipBurnsMediumEffect;    // 海賊船が燃えるエフェクト（中）
    int     pirateShipExplosionEffect;      // 海賊船が爆発するエフェクト
    int     pirateShipBigExplosionEffect;   // 海賊船が大爆発するエフェクト
    int     thunderEffect;                  // 雷が落ちるエフェクト
    // その他
    int     fireWorksEffect;                // 花火のエフェクト
};

