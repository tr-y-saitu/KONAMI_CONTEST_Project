#include "PirateShip.h"

/// <summary>
/// コンストラクタ
/// </summary>
PirateShip::PirateShip()
{
    modelHandle = MV1LoadModel("data/model/pirateShip/pirateShip.mv1");
    position = VGet(-33, -7, 0);
    scale = VGet(0.11, 0.11, 0.11);
    MV1SetScale(modelHandle, scale);
    MV1SetRotationXYZ(modelHandle, VGet(0.0f, -10.0f * DX_PI_F / 180.0f, 0.0f));
}

/// <summary>
/// デストラクタ
/// </summary>
PirateShip::~PirateShip()
{
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
void PirateShip::Update()
{
    // モデルの座標設定
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void PirateShip::Draw()
{
    MV1DrawModel(modelHandle);
}
