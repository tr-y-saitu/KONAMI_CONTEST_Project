#include "BoatWithChest.h"

/// <summary>
/// コンストラクタ
/// </summary>
BoatWithChest::BoatWithChest()
{
    modelHandle = MV1LoadModel("data/model/boatWithChest/boatWithChest.mv1");
    position = VGet(5, 1, -5);
    scale = VGet(0.1, 0.1, 0.1);
    MV1SetScale(modelHandle, scale);
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
