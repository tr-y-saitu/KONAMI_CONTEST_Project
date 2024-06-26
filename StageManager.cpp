#include "StageManager.h"
#include "BoatWithChest.h"
#include "PirateShip.h"
#include "sea.h"


/// <summary>
/// コンストラクタ
/// </summary>
StageManager::StageManager()
{
    boatWithChest = new BoatWithChest();
    pirateShip = new PirateShip();
    sea = new Sea();
}

/// <summary>
/// デストラクタ
/// </summary>
StageManager::~StageManager()
{
    delete(boatWithChest);
    delete(pirateShip);
    delete(sea);
}

/// <summary>
/// 更新
/// </summary>
void StageManager::Update()
{
    boatWithChest->Update();
    pirateShip->Update();
    sea->Update();
}

/// <summary>
/// 描画
/// </summary>
void StageManager::Draw()
{
    boatWithChest->Draw();
    pirateShip->Draw();
    sea->Draw();
}
