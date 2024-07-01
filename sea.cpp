#include "sea.h"

/// <summary>
/// コンストラクタ
/// </summary>
Sea::Sea()
    : waveAnimationScaleY       (0)
    , isScaleDown               (false)
{
    //modelHandle = MV1LoadModel("data/model/sea/seaIsland.mv1");
    modelHandle = MV1LoadModel("data/model/sea/sea.mv1");
    position = VGet(-60.0f, 11.5f, 200.0f);
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
    // 波のアニメーションを再生
    PlayWaveAnimation();

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

/// <summary>
/// 波のアニメーションを再生
/// </summary>
void Sea::PlayWaveAnimation()
{
    // スケールを変更する
    if (!isScaleDown)
    {
        waveAnimationScaleY += SCALE_ADD;
    }
    else
    {
        waveAnimationScaleY -= SCALE_ADD;
    }

    // 大きくするか、小さくするか
    if (waveAnimationScaleY >= SCALE_ADD_MAX_LIMIT)
    {
        isScaleDown = true;
    }
    if (waveAnimationScaleY < SCALE_ADD_MIN_LIMIT)
    {
        isScaleDown = false;
    }

    // スケールを変更
    scale = VAdd(scale, VGet(0, waveAnimationScaleY, 0));
    MV1SetScale(modelHandle, scale);
}
