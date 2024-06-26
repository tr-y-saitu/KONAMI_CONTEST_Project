#include "sea.h"

/// <summary>
/// コンストラクタ
/// </summary>
Sea::Sea()
{
    modelHandle = MV1LoadModel("data/model/sea/seaIsland.mv1");
    position = VGet(0, 0, 0);
    scale = VGet(1, 1, 1);
    MV1SetScale(modelHandle, scale);
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
