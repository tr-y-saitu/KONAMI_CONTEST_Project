#pragma once
#include "Common.h"

/// <summary>
/// プレイヤーの持つクッション
/// </summary>
class PlayerCushion
{
public:
    /// <summary>
    /// クッションのアニメーション状態
    /// </summary>
    enum ANIMATION_STATE
    {
        NONE,       // 再生していない
        PLAY,       // 再生する
        BOUND,      // バウンド中
        SCALE_UP,   // 拡大中
        SCALE_DOWN, // 縮小中
        END,        // 再生終了
    };

    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayerCushion();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PlayerCushion();

    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="playerPosition">プレイヤーの座標</param>
    void Update(VECTOR playerPosition);

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    /// <summary>
    /// バウンドアニメーションの再生
    /// </summary>
    void UpdateBoundAnimationState();

    // Getter/Setter
    VECTOR GetOffSetPosition() const { return offSetPosition; } // 当たり判定調整用
    void SetAnimationState(const int set) { animationState = set; }

private:
    static constexpr float BOUND_START_ANIMATION_SPEED = 0.01; // バウンドアニメーションの最初の再生速度
    static constexpr float BOUND_START_SCALE_Y_LIMIT = 0.05;    // バウンドアニメーション最初のスケールの限度
    static constexpr float BOUND_UP_ANIMATION_SPEED = 0.007;    // スケールを大きくする時の速度
    static constexpr float BOUND_UP_SCALE_Y_LIMIT = 0.07;       // スケールを大きくする時のスケールの限度
    static constexpr float BOUND_DONW_ANIMATION_SPEED = 0.005;  // スケールを小さくする時の速度
    static constexpr float BOUND_DOWN_SCALE_Y_LIMIT = 0;        // スケールを小さくする時のスケールの限度

    int     modelHandle;
    VECTOR  position;
    VECTOR  scale;
    VECTOR  offSetPosition;
    VECTOR  rotationRate;
    float   boundScaleY;            // バウンドアニメーションする際のクッションのYスケール
    int     boundScaleYDirection;   // バウンドアニメーションする際のスケール調整の方向
    int     animationState;         // アニメーションの状態
};


