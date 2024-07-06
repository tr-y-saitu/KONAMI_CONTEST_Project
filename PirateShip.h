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
    void Update() override;

    /// <summary>
    /// タイトルシーンでの更新
    /// </summary>
    void UpdateTitleScene();

    // 描画
    void Draw() override;

private:
    // 定数
    static constexpr int PIRATE_SHIP_BURNS_SMALL_EFFECT_CYCLE = 100;    // 海賊船が燃えるエフェクト(中)を再生する周期
    static constexpr int THUNDER_EFFECT_CYCLE = 300;                    // 雷のエフェクトを再生する周期
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_PLAY_NUN = 5;         // 海賊船が燃えるエフェクトを再生する数
    static constexpr VECTOR PIRATE_SHIP_BURNS_EFFECT_POSITION = { 18,-19, -5 };   // 海賊船が燃えるエフェクトを再生する座標
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_OFFSET_X = 2;
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_OFFSET_Z = 2;

    // 変数
    int effectCount;                    // エフェクトをループ再生するためのカウント
    EffectManager* effectManager;       // エフェクトマネージャー
};


