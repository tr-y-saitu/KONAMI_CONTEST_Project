#include "Island.h"

/// <summary>
/// コンストラクタ
/// </summary>
Island::Island()
{
    modelHandle = MV1LoadModel("data/model/island/island.mv1");
    position = VGet(0, 0, 0);
    scale = VGet(0.1, 0.1, 0.1);
    MV1SetScale(modelHandle, scale);
}

/// <summary>
/// デストラクタ
/// </summary>
Island::~Island()
{
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
void Island::Update()
{
    // モデルの座標設定
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void Island::Draw()
{
    MV1DrawModel(modelHandle);
}
