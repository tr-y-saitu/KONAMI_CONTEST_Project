#pragma once
#include "Common.h"

/// <summary>
/// プレイヤーの持つオール
/// </summary>
class PlayerOar
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayerOar();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PlayerOar();

    /// <summary>
    /// 更新
    /// </summary>
    void Update(VECTOR playerPosition);

    // オールを漕ぐ
    void PlayRowingAnimation();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    const int GetModelHandle() { return modelHandle; }
    const VECTOR GetPosition() { return position; }

    void SetPosition(const VECTOR set) { position = set; }

private:
    static constexpr int ANIMATION_SPEED = 2;   // アニメーション再生速度
    static constexpr int LIMIT_ANGLE_MAX = 120; // 漕いでいい最大角度
    static constexpr int LIMIT_ANGLE_MIN = 0;   // 漕いでよい最小角度

    int     modelHandle;
    VECTOR  position;
    VECTOR  scale;
    VECTOR  offSetPosition;
    VECTOR  rotationRate;
    int     turnOverRate;       // プレイヤー移動に合わせてオールが回転する角度の値
    bool    isBuckReverse;      // 逆回転するフラグ
};


