#pragma once
#include "StageObjectBase.h"

class EffectManager;

/// <summary>
/// 海賊船
/// </summary>
class PirateShip : public StageObjectBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PirateShip();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PirateShip();

    /// <summary>
    /// 更新
    /// </summary>
    void Update(int gemWaveState);

    /// <summary>
    /// タイトルシーンでの更新
    /// </summary>
    void UpdateTitleScene();

    /// <summary>
    /// 海賊船が炎上するエフェクトを再生
    /// </summary>
    /// <param name="gemWaveState">宝石のウェーブステート</param>
    void PlayShipFireEffect(int gemWaveState);

    /// <summary>
    /// 海賊船が炎上するエフェクトの更新
    /// </summary>
    /// <param name="playNum">再生する数</param>
    /// <param name="effectScale">エフェクトの拡大率</param>
    void UpdateShipFireEffect(int playNum, VECTOR effectScale);

    // 描画
    void Draw() override;

private:
    // 定数
    static constexpr int PIRATE_SHIP_BURNS_SMALL_EFFECT_CYCLE = 100;    // 海賊船が燃えるエフェクト(中)を再生する周期
    static constexpr int THUNDER_EFFECT_CYCLE = 300;                    // 雷のエフェクトを再生する周期
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_PLAY_NUN = 5;         // 海賊船が燃えるエフェクトを再生する数
    static constexpr VECTOR PIRATE_SHIP_BURNS_EFFECT_POSITION = { 18,-19, -5 };   // 海賊船が燃えるエフェクトを再生する座標
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_OFFSET_X = 3;         // 海賊船が燃えるエフェクトの位置調整用
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_OFFSET_Z = 4;         // 海賊船が燃えるエフェクトの位置調整用
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_PLAY_BUF = 2;         // 海賊船が燃えるエフェクトを描画する数のバフ値
    static constexpr int RANDOM_RANGE = 3;                              // 乱数の範囲
    static constexpr int RANDOM_OFFSET = 3;                             // 乱数値調整用


    // 変数
    int effectCount;                    // エフェクトをループ再生するためのカウント
    EffectManager* effectManager;       // エフェクトマネージャー
};


