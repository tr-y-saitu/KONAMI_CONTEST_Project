#include "PirateShip.h"

/// <summary>
/// コンストラクタ
/// </summary>
PirateShip::PirateShip()
{
    modelHandle = MV1LoadModel("data/model/pirateShip/pirateShip.mv1");
    position = VGet(2, 0, 0);
    scale = VGet(0.1, 0.1, 0.1);
    MV1SetScale(modelHandle, scale);
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
    MV1DeleteModel(modelHandle);
}
