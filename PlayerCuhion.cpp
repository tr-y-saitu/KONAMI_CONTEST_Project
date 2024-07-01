#include "PlayerCuhion.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerCushion::PlayerCushion()
{
    modelHandle = MV1LoadModel("data/model/player/playerAsset/playerCushion/cushionSand.mv1");
    position = VGet(0.0f, 0.0f, 0.0f);
    offSetPosition = VGet(3.0f, 0.5f, 0.0f);
    scale = VGet(0.07f, 0.07f, 0.07f);
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
