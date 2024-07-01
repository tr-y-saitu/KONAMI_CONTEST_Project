#include "PlayerOar.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerOar::PlayerOar()
    : turnOverRate  (0.0f)
    , isBuckReverse (false)
{
    modelHandle = MV1LoadModel("data/model/player/playerAsset/playerOar/playerOar.mv1");
    position = VGet(0.0f, 0.0f, 0.0f);
    offSetPosition = VGet(1.2f, 1.3f, -1.0f);
    scale = VGet(0.03f, 0.03f, 0.03f);
    MV1SetScale(modelHandle, scale);
    rotationRate = VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f);
    MATRIX matrix = MGetRotX(DX_PI_F / -4.0f);
    rotationRate = VTransform(rotationRate, matrix);
    MV1SetRotationXYZ(modelHandle, rotationRate);
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerOar::~PlayerOar()
{
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
void PlayerOar::Update(VECTOR playerPosition)
{
    // 座標の設定
    position = VAdd(playerPosition, offSetPosition);

    // 漕ぐアニメーション再生
    PlayRowingAnimation();

    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// オールを漕ぐ
/// </summary>
void PlayerOar::PlayRowingAnimation()
{
    // 漕ぐ
    if (turnOverRate <= LIMIT_ANGLE_MAX && !isBuckReverse)
    {
        turnOverRate += ANIMATION_SPEED;
    }
    else
    {
        turnOverRate -= ANIMATION_SPEED;
    }
    if (turnOverRate > LIMIT_ANGLE_MAX)
    {
        isBuckReverse = true;
    }
    if (turnOverRate < LIMIT_ANGLE_MIN)
    {
        isBuckReverse = false;
    }

    // オールを回転
    auto _rotationRate = VGet(turnOverRate * DX_PI_F / 180.0f, -45.0f * DX_PI_F / 180.0f, 0.0f);
    auto matrix = MGetRotY(-45.0f * DX_PI_F / 180.0f);
    _rotationRate = VTransform(_rotationRate, matrix);

    // 回転率をセット
    MV1SetRotationXYZ(modelHandle, _rotationRate);
}

/// <summary>
/// 描画
/// </summary>
void PlayerOar::Draw()
{
    MV1DrawModel(modelHandle);
}

