#pragma once
#include "Common.h"
#include "Player.h"

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

    /// <summary>
    /// オールを漕ぐ
    /// </summary>
    /// <param name="playerState">移動状態</param>
    void UpdateRowingAnimationSpeed(int movingState);

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    const int GetModelHandle() { return modelHandle; }
    const VECTOR GetPosition() { return position; }

    void SetPosition(const VECTOR set) { position = set; }

private:
    static constexpr int ANIMATION_SPEED = 9;               // アニメーション再生速度
    static constexpr int LIMIT_ANGLE_MAX = 180;             // 漕いでいい最大角度
    static constexpr int LIMIT_ANGLE_MIN = -10;             // 漕いでよい最小角度
    static constexpr float MOVE_ACCELARATION = 0.09;        // 漕ぐ加速度
    static constexpr float MOVE_ACCELARATION_LIMIT = 12;    // 加速度の限度値
    static constexpr float MOVE_DECELERATION = 0.1;         // 漕ぐ減速度
    static constexpr float MOVE_DECELERATION_LIMIT = 2;     // 減速度の限度値

    int     modelHandle;
    VECTOR  position;
    VECTOR  scale;
    VECTOR  offSetPosition;
    VECTOR  rotationRate;
    float   animationSpeed;     // アニメーション再生速度
    int     turnOverRate;       // プレイヤー移動に合わせてオールが回転する角度の値
    bool    isBuckReverse;      // 逆回転するフラグ
};


