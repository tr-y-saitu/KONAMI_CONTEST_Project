#include "PirateShip.h"
#include "EffectManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
PirateShip::PirateShip()
    : effectCount       (0)
{
    effectManager = EffectManager::GetInstance();
    modelHandle = MV1LoadModel("data/model/pirateShip/Ship1/ship1.mv1");
    position = VGet(-40, 30, 0);
    scale = VGet(0.7, 0.7, 0.7);
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
    // 海賊船が燃えているエフェクトを再生
    if (effectCount % 60 == 0)
    {
        VECTOR _playPos = VAdd(position, VGet(20, -25, -5));
        effectManager->PlayPirateShipBurnsSmallEffect(_playPos);
        //effectManager->PlayPirateShipBurnsMediumEffect(_playPos);
    }
    if (effectCount % 120 == 0)
    {
        VECTOR _playPos = VAdd(position, VGet(30, -25, 0));
        effectManager->PlayPirateShipExplosionEffect(_playPos);
    }

    // エフェクトカウント更新
    effectCount++;

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
