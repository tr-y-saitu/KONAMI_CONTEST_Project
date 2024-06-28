#include "PlayerCuhion.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerCushion::PlayerCushion()
{
    modelHandle = MV1LoadModel("data/model/player/playerAsset/playerCushion/cushion.mv1");
    position = VGet(0, 0, 0);
    scale = VGet(0.1f, 0.1f, 0.1f);
    MV1SetScale(modelHandle, scale);
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
    position = VAdd(playerPosition, VGet(1, 0, 0));
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void PlayerCushion::Draw()
{
    MV1DrawModel(modelHandle);
}
