#pragma once
#include "Common.h"
#include "StageObjectBase.h"

/// <summary>
/// 海
/// </summary>
class Sea : public StageObjectBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Sea();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Sea();

    /// <summary>
    /// 更新
    /// </summary>
    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    /// <summary>
    /// 波のアニメーションを再生
    /// </summary>
    void PlayWaveAnimation();

private:
    // 定数
    static constexpr float SCALE_ADD = 0.000002f;           // スケールを加算する値
    static constexpr float SCALE_ADD_MAX_LIMIT = 0.00009f;  // スケールの最大加算値
    static constexpr float SCALE_ADD_MIN_LIMIT = -0.00009f; // スケールの最小加算値

    // 変数
    float waveAnimationScaleY;      // 波のアニメーション用Yスケール
    bool isScaleDown;               // スケールを小さくするかどうか
};

