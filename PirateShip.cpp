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
    // ウェーブに応じてエフェクト内容を再生
    switch (gemWaveState)
    {
    case GemManager::WAVE_FIRST:
        UpdateShipFireEffect(WAVE_FIRST_EFECT_PLAY_NUM, WAVE_FIRST_EFFECT_SCALE);
        break;


    case GemManager::WAVE_SECOND:
        UpdateShipFireEffect(WAVE_SECOND_EFFECT_PLAY_NUM, WAVE_SECOND_EFFECT_SCALE);
        break;

    case GemManager::WAVE_THIRD:
        UpdateShipFireEffect(WAVE_THIRD_EFFECT_PLAY_NUM, WAVE_THIRD_EFFECT_SCALE);
        break;

    case GemManager::WAVE_END:
        UpdateShipFireEffect(WAVE_END_EFFECT_PLAY_NUM, WAVE_END_EFFECT_SCALE);
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
