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
    static constexpr int PIRATE_SHIP_BURNS_SMALL_EFFECT_CYCLE = 100;        // 海賊船が燃えるエフェクト(中)を再生する周期
    static constexpr int THUNDER_EFFECT_CYCLE = 300;                        // 雷のエフェクトを再生する周期
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_PLAY_NUN = 5;             // 海賊船が燃えるエフェクトを再生する数
    static constexpr VECTOR PIRATE_SHIP_BURNS_EFFECT_POSITION = { 19,-19, -5 };   // 海賊船が燃えるエフェクトを再生する座標
    static constexpr float PIRATE_SHIP_BURNS_EFFECT_OFFSET_X = 1.5f;        // 海賊船が燃えるエフェクトの位置調整用
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_OFFSET_Z = 4;             // 海賊船が燃えるエフェクトの位置調整用
    static constexpr int PIRATE_SHIP_BURNS_EFFECT_PLAY_BUF = 2;             // 海賊船が燃えるエフェクトを描画する数のバフ値
    static constexpr int RANDOM_RANGE = 3;                                  // 乱数の範囲
    static constexpr int RANDOM_OFFSET = 3;                                 // 乱数値調整用
    static constexpr int WAVE_FIRST_EFECT_PLAY_NUM = 1;                     // ファーストウェーブのエフェクト再生数
    static constexpr VECTOR WAVE_FIRST_EFFECT_SCALE = { 0.5f, 0.5f, 0.5f }; // ファーストウェー5ぶのエフェクトの拡大率
    static constexpr int WAVE_SECOND_EFFECT_PLAY_NUM = 4;                   // セカンドウェーブのエフェクト再生数
    static constexpr VECTOR WAVE_SECOND_EFFECT_SCALE = { 0.7f, 1.0f, 0.7f };// セカンドウェーブのエフェクトの拡大率
    static constexpr int WAVE_THIRD_EFFECT_PLAY_NUM = 5;                    // サードウェーブのエフェクト再生数
    static constexpr VECTOR WAVE_THIRD_EFFECT_SCALE = { 1.5f, 2.5f, 1.5f }; // サードウェーブのエフェクトの拡大率
    static constexpr int WAVE_END_EFFECT_PLAY_NUM = 5;                      // エンドウェーブのエフェクト再生数
    static constexpr VECTOR WAVE_END_EFFECT_SCALE = { 1.5f, 2.5f, 1.5f };   // エンドウェーブのエフェクト拡大率

    // 変数
    int effectCount;                    // エフェクトをループ再生するためのカウント
    EffectManager* effectManager;       // エフェクトマネージャー
};


