#include "PlayerCuhion.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerCushion::PlayerCushion()
    : boundScaleY           (0.0f)
    , boundScaleYDirection  (1)
    , animationState        (ANIMATION_STATE::NONE)
{
    modelHandle = MV1LoadModel("data/model/player/playerAsset/playerCushion/clothModle.mv1");
    position = VGet(0.0f, 0.0f, 0.0f);
    offSetPosition = VGet(3.0f, 0.8f, 0.0f);
    scale = VGet(0.07f, 0.11f, 0.12f);
    MV1SetScale(modelHandle, scale);
    rotationRate = VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f);
    MV1SetRotationXYZ(modelHandle, rotationRate);
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerCushion::~PlayerCushion()
{
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
/// <param name="playerPosition">プレイヤーの座標</param>
void PlayerCushion::Update(VECTOR playerPosition)
{
    PlayBoundAnimation();
    // 座標の更新
    position = VAdd(playerPosition, offSetPosition);
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void PlayerCushion::Draw()
{
    MV1DrawModel(modelHandle);
}

/// <summary>
/// バウンドアニメーションの再生
/// </summary>
void PlayerCushion::PlayBoundAnimation()
{
    // アニメーション開始
    if (animationState == PLAY)
    {
        animationState = BOUND;
    }

    // 最初は少しへこませる(スケールダウン)
    if (animationState == BOUND)
    {
        boundScaleY -= BOUND_START_ANIMATION_SPEED;
        if (boundScaleY <= -BOUND_START_SCALE_Y_LIMIT)
        {
            animationState = SCALE_UP;
        }
    }

    // スケールアップさせる
    if (animationState == SCALE_UP)
    {
        boundScaleY += BOUND_UP_ANIMATION_SPEED;
        if (boundScaleY >= BOUND_UP_SCALE_Y_LIMIT)
        {
            animationState = SCALE_DOWN;
        }
    }

    // スケールダウンさせる
    if(animationState == SCALE_DOWN)
    {
        boundScaleY -= BOUND_DONW_ANIMATION_SPEED;
        if (boundScaleY <= BOUND_DOWN_SCALE_Y_LIMIT)
        {
            // アニメーション終了
            animationState = END;
        }
    }

    // スケールをセットする
    VECTOR setScale = VAdd(scale,VGet(0, boundScaleY, 0));
    MV1SetScale(modelHandle, setScale);
}
