#include "sea.h"

/// <summary>
/// コンストラクタ
/// </summary>
Sea::Sea()
{
    //modelHandle = MV1LoadModel("data/model/sea/seaIsland.mv1");
    modelHandle = MV1LoadModel("data/model/sea/sea.mv1");
    position = VGet(-50.0f, 11.5f, 200.0f);
    scale = VGet(0.1f, 0.1f, 0.1f);
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
