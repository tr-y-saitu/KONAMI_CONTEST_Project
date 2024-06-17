#include "ClearSceneUI.h"
#include "ClearScene.h"
#include "MenuScene.h"
#include "SceneBase.h"
#include "Room.h"
#include "TreasureChest.h"
#include "Camera.h"
#include "Collision.h"
#include "SkyDome.h"
#include "Gem.h"
#include "GemManager.h"
#include "Player.h"
#include "GameScene.h"
#include "Calculation.h"

/// <summary>
/// コンストラクタ
/// </summary>
ClearScene::ClearScene()
{
    clearSceneUI = new ClearSceneUI();
    treasureChest = new TreasureChest();
    gemManager = new GemManager();
    collision = new Collision();
    camera = new Camera();
    skyDome = new SkyDome();
    room = new Room();
}

/// <summary>
/// デストラクタ
/// </summary>
ClearScene::~ClearScene()
{
    delete(clearSceneUI);
    delete(treasureChest);
    delete(gemManager);
    delete(collision);
    delete(camera);
    delete(skyDome);
    delete(room);
}

/// <summary>
/// 初期化
/// </summary>
void ClearScene::Initialize()
{
    treasureChest->Initialize();
    gemManager->Initialize();
    skyDome->Initialize();
    room->Initialize();
}

/// <summary>
/// 更新
/// </summary>
void ClearScene::Update()
{
    treasureChest->Update();
    room->Update();
}

/// <summary>
/// シーンの更新
/// </summary>
/// <returns></returns>
SceneBase* ClearScene::UpdateScene()
{
    treasureChest->Update();
    room->Update();
    // スペースキーが押されたらメニューへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        return new MenuScene();
    }
    return this;
}

/// <summary>
/// 描画
/// </summary>
void ClearScene::Draw()
{
    // オブジェクト描画
    treasureChest->Draw();
    room->Draw();

    // UI描画
    DrawUI();
}

/// <summary>
/// UIの描画
/// </summary>
void ClearScene::DrawUI()
{
    clearSceneUI->Draw();
}
