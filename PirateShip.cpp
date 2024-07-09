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
void PirateShip::Update(int gemWaveState)
{
    // 海賊船が燃えているエフェクトを再生
    if (effectCount % PIRATE_SHIP_BURNS_SMALL_EFFECT_CYCLE == 0)
    {
        // 座標設定
        VECTOR playPosition = VAdd(position, PIRATE_SHIP_BURNS_EFFECT_POSITION);

        // 宝石のWAVEステートに応じて数を変更
        int numberToPlay = gemWaveState + PIRATE_SHIP_BURNS_EFFECT_PLAY_BUF;
        for (int i = 0; i < numberToPlay; i++)
        {
            // エフェクトずらし量
            VECTOR offSet = VGet(-i /PIRATE_SHIP_BURNS_EFFECT_OFFSET_X, 0, i * PIRATE_SHIP_BURNS_EFFECT_OFFSET_Z);
            // 再生位置
            playPosition = VAdd(playPosition, offSet);
            // エフェクト拡大率
            float scaleNum = (float)numberToPlay / 2;
            VECTOR scale = VGet(scaleNum, scaleNum, scaleNum);
            // エフェクト再生
            effectManager->PlayPirateShipBurnsSmallEffect(playPosition,scale);
        }
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
