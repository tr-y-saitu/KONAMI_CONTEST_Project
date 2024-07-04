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
    void PlayBoundAnimation();

    // Getter/Setter
    VECTOR GetOffSetPosition() const { return offSetPosition; } // 当たり判定調整用
    void SetAnimationState(const int set) { animationState = set; }

private:
    static constexpr float BOUND_ANIMATION_SPEED = 0.005;  // バウンドアニメーションを再生する速度

    int     modelHandle;
    VECTOR  position;
    VECTOR  scale;
    VECTOR  offSetPosition;
    VECTOR  rotationRate;
    float   boundScaleY;            // バウンドアニメーションする際のクッションのYスケール
    int     boundScaleYDirection;   // バウンドアニメーションする際のスケール調整の方向
    int     animationState;         // アニメーションの状態
};


