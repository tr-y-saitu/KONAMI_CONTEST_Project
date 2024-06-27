#include "BoatWithChest.h"

/// <summary>
/// コンストラクタ
/// </summary>
BoatWithChest::BoatWithChest()
{
    modelHandle = MV1LoadModel("data/model/boatWithChest/boatWithChest.mv1");
    position = VGet(5, 0, -5);
    scale = VGet(0.06, 0.06, 0.06);
    MV1SetScale(modelHandle, scale);
    MV1SetRotationXYZ(modelHandle, VGet(0.0f, 100.0f * DX_PI_F / 180.0f, 0.0f));
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
