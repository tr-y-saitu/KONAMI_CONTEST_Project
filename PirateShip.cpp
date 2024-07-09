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
    if (effectCount % PIRATE_SHIP_BURNS_SMALL_EFFECT_CYCLE == 0)
    {
        // 座標設定
        VECTOR _playPosition1 = VAdd(position, PIRATE_SHIP_BURNS_SMALL_EFFECT_POSITION_1);
        VECTOR _playPosition2 = VAdd(position, PIRATE_SHIP_BURNS_SMALL_EFFECT_POSITION_2);
        VECTOR _playPosition3 = VAdd(position, PIRATE_SHIP_BURNS_SMALL_EFFECT_POSITION_3);
        // 再生
        effectManager->PlayPirateShipBurnsSmallEffect(_playPosition1);
        effectManager->PlayPirateShipBurnsSmallEffect(_playPosition2);
        effectManager->PlayPirateShipBurnsSmallEffect(_playPosition3);
    }

    // エフェクトカウント更新
    effectCount++;

    // モデルの座標設定
    MV1SetPosition(modelHandle, position);
}

/// <summary>
/// タイトルシーンでの更新
/// </summary>
void PirateShip::UpdateTitleScene()
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
