#include "PlayerOar.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerOar::PlayerOar()
    : turnOverRate      (0.0f)
    , isBuckReverse     (false)
    , animationSpeed    (MOVE_DECELERATION_LIMIT)
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
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// オールを漕ぐ
/// </summary>
/// <param name="playerState">プレイヤーの状態</param>
void PlayerOar::UpdateRowingAnimationSpeed(int movingState)
{
    // 移動中であれば再生
    if (movingState == Player::MOVE)
    {
        // 再生速度の設定
        if (animationSpeed <= MOVE_ACCELARATION_LIMIT)
        {
            animationSpeed += MOVE_ACCELARATION;
        }

        // 漕ぐ
        if (turnOverRate <= LIMIT_ANGLE_MAX && !isBuckReverse)
        {
            turnOverRate += animationSpeed;
        }
        else
        {
            turnOverRate -= animationSpeed;
        }
        if (turnOverRate > LIMIT_ANGLE_MAX)
        {
            isBuckReverse = true;
        }
        if (turnOverRate < LIMIT_ANGLE_MIN)
        {
            isBuckReverse = false;
        }
    }
    else if (animationSpeed >= MOVE_DECELERATION_LIMIT)
    {
        // 加速度を減速
        animationSpeed -= MOVE_DECELERATION;
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

