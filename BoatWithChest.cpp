#include "BoatWithChest.h"

/// <summary>
/// コンストラクタ
/// </summary>
BoatWithChest::BoatWithChest()
{
    modelHandle = MV1LoadModel("data/model/boatWithChest/Boat/BoatFBX.mv1");
    position = VGet(11, -1, -5);
    scale = VGet(0.02, 0.02, 0.02);
    MV1SetScale(modelHandle, scale);
    MV1SetRotationXYZ(modelHandle, VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
}

/// <summary>
/// デストラクタ
/// </summary>
BoatWithChest::~BoatWithChest()
{
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
void BoatWithChest::Update()
{
    // モデルの座標設定
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void BoatWithChest::Draw()
{
    MV1DrawModel(modelHandle);
}
