#include "StageObjectSet.h"
#include "BoatWithChest.h"
#include "PirateShip.h"
#include "sea.h"


/// <summary>
/// コンストラクタ
/// </summary>
StageObjectSet::StageObjectSet()
{
    boatWithChest = new BoatWithChest();
    pirateShip = new PirateShip();
    sea = new Sea();
}

/// <summary>
/// デストラクタ
/// </summary>
StageObjectSet::~StageObjectSet()
{
    delete(boatWithChest);
    delete(pirateShip);
    delete(sea);
}

/// <summary>
/// 更新
/// </summary>
/// <param name="gemWaveState">宝石のウェーブステート</param>
void StageObjectSet::Update(int gemWaveState)
{
    boatWithChest->Update();
    pirateShip->Update(gemWaveState);
    sea->Update();
}

/// <summary>
/// タイトルシーでの更新
/// </summary>
void StageObjectSet::UpdateTitleScene()
{
    boatWithChest->Update();
    pirateShip->UpdateTitleScene();
    sea->Update();
}

/// <summary>
/// 描画
/// </summary>
void StageObjectSet::Draw()
{
    boatWithChest->Draw();
    pirateShip->Draw();
    sea->Draw();
}
