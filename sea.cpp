#include "sea.h"

/// <summary>
/// コンストラクタ
/// </summary>
Sea::Sea()
{
    modelHandle = MV1LoadModel("data/model/sea/seaIsland.mv1");
    position = VGet(-50, 0, 200);
    scale = VGet(0.1, 0.1, 0.1);
    MV1SetScale(modelHandle, scale);
    MV1SetRotationXYZ(modelHandle, VGet(0.0f, 100.0f * DX_PI_F / 180.0f, 0.0f));
}

/// <summary>
/// デストラクタ
/// </summary>
Sea::~Sea()
{
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
void Sea::Update()
{
    // モデルの座標設定
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void Sea::Draw()
{
    MV1DrawModel(modelHandle);
}
