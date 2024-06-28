#include "PlayerOar.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerOar::PlayerOar()
{
    modelHandle = MV1LoadModel("data/model/player/playerAsset/playerOar/playerOar.mv1");
    position = VGet(0, 0, 0);
    scale = VGet(0.03, 0.03, 0.03);
    MV1SetScale(modelHandle, scale);
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
    position = playerPosition;
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void PlayerOar::Draw()
{
    MV1DrawModel(modelHandle);
}

