#include "PirateShip.h"
#include "EffectManager.h"
#include "GemManager.h"

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
    PlayShipFireEffect(gemWaveState);

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
/// 海賊船が炎上するエフェクトを再生
/// </summary>
/// <param name="gemWaveState">宝石のウェーブステート</param>
void PirateShip::PlayShipFireEffect(int gemWaveState)
{
    //// 海賊船が燃えているエフェクトを再生
    //if (effectCount % PIRATE_SHIP_BURNS_SMALL_EFFECT_CYCLE == 0)
    //{
    //    // 再生する座標設定
    //    VECTOR playPosition = VAdd(position, PIRATE_SHIP_BURNS_EFFECT_POSITION);

    //    // ウェーブ更新で再生するエフェクトの数が増加
    //    int numberToPlay = gemWaveState + PIRATE_SHIP_BURNS_EFFECT_PLAY_BUF;
    //    for (int i = 0; i < numberToPlay; i++)
    //    {
    //        // 再生位置ずらし量
    //        VECTOR offSet = VGet(-i / PIRATE_SHIP_BURNS_EFFECT_OFFSET_X, 0, i * PIRATE_SHIP_BURNS_EFFECT_OFFSET_Z);

    //        // 再生位置設定
    //        playPosition = VAdd(playPosition, offSet);

    //        // エフェクト拡大率
    //        float scaleNum = (float)numberToPlay / 3;

    //        // 拡大率設定
    //        VECTOR scale = VGet(scaleNum, scaleNum, scaleNum);

    //        // エフェクト再生
    //        effectManager->PlayPirateShipBurnsSmallEffect(playPosition, scale);
    //    }
    //}

    //// エフェクトカウント更新
    //effectCount++;


    switch (gemWaveState)
    {
    case GemManager::WAVE_FIRST:
        UpdateShipFireEffect(1, VGet(0.3f, 0.3f, 0.3f));
        break;


    case GemManager::WAVE_SECOND:
        UpdateShipFireEffect(4, VGet(0.7f, 1.0f, 0.7f));
        break;

    case GemManager::WAVE_THIRD:
        UpdateShipFireEffect(5, VGet(2.0f, 3.0f, 2.0f));
        break;

    case GemManager::WAVE_END:
        UpdateShipFireEffect(5, VGet(2.0f, 3.0f, 2.0f));
        break;


    default:
        break;
    }

}


void PirateShip::UpdateShipFireEffect(int playNum, VECTOR effectScale)
{
    // 海賊船が燃えているエフェクトを再生
    if (effectCount % PIRATE_SHIP_BURNS_SMALL_EFFECT_CYCLE == 0)
    {
        // 再生する座標設定
        VECTOR playPosition = VAdd(position, PIRATE_SHIP_BURNS_EFFECT_POSITION);

        // ウェーブ更新で再生するエフェクトの数が増加
        for (int i = 0; i < playNum; i++)
        {
            // 再生位置ずらし量
            // Y座標をずらし、ゆらゆら燃えている感を出す
            float positionY = GetRand(RANDOM_RANGE) - RANDOM_OFFSET;
            VECTOR offSet = VGet(-i / PIRATE_SHIP_BURNS_EFFECT_OFFSET_X, positionY, i * PIRATE_SHIP_BURNS_EFFECT_OFFSET_Z);

            // 再生位置設定
            playPosition = VAdd(playPosition, offSet);

            // エフェクト再生
            effectManager->PlayPirateShipBurnsSmallEffect(playPosition, effectScale);
        }
    }

    // エフェクトカウント更新
    effectCount++;
}

/// <summary>
/// 描画
/// </summary>
void PirateShip::Draw()
{
    MV1DrawModel(modelHandle);
}
