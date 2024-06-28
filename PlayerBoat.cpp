#include "PlayerBoat.h"


/// <summary>
/// コンストラクタ
/// </summary>
PlayerBoat::PlayerBoat()
{
    modelHandle = MV1LoadModel("data/model/player/playerAsset/playerBoat/playerBoat.mv1");
    position = VGet(0, 0, 0);
    offSetPosition = VGet(2, -1, 0);
    scale = VGet(0.02f, 0.02f, 0.02f);
    MV1SetScale(modelHandle, scale);
    rotationRate = VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f);
    MV1SetRotationXYZ(modelHandle, rotationRate);
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerBoat::~PlayerBoat()
{
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
/// <param name="playerPosition">プレイヤーの座標</param>
void PlayerBoat::Update(VECTOR playerPosition)
{
    // 座標の更新
    position = VAdd(playerPosition, offSetPosition);
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void PlayerBoat::Draw()
{
    MV1DrawModel(modelHandle);
}
