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
#include "BoatWithChest.h"
#include "sea.h"

/// <summary>
/// コンストラクタ
/// </summary>
ClearScene::ClearScene(int _score, int _highScore)
{
    score           = _score;
    highScore       = _highScore;
    clearSceneUI    = new ClearSceneUI();
    treasureChest   = new TreasureChest();
    gemManager      = new GemManager();
    camera          = new Camera();
    skyDome         = new SkyDome();
    boatWithChest   = new BoatWithChest();
    sea             = new Sea();
}

/// <summary>
/// デストラクタ
/// </summary>
ClearScene::~ClearScene()
{
    delete(clearSceneUI);
    delete(treasureChest);
    delete(gemManager);
    delete(camera);
    delete(skyDome);
    delete(boatWithChest);
    delete(sea);
}

/// <summary>
/// 初期化
/// </summary>
void ClearScene::Initialize()
{
    treasureChest->Initialize();
    gemManager->Initialize();
    boatWithChest->Initialize(VGet(0, 0, 0));
}

/// <summary>
/// 更新
/// </summary>
void ClearScene::Update()
{
    treasureChest->Update();    // 宝箱
}

/// <summary>
/// シーンの更新
/// </summary>
/// <returns></returns>
SceneBase* ClearScene::UpdateScene()
{
    // フェードイン指示
    if (clearSceneUI->GetFadeState() == SceneUIBase::FADE_NONE)
    {
        clearSceneUI->SetFadeState(SceneUIBase::FADE_IN_UI_PLAYING);
    }
    if (clearSceneUI->GetFadeState() == SceneUIBase::FADE_IN_UI_PLAYING)
    {
        clearSceneUI->StartFadeInUI();
    }

    // 更新処理
    treasureChest->Update();    // 宝箱
    skyDome->Update();          // スカイドーム
    boatWithChest->Update();    // 宝箱を乗せる船
    sea->Update();              // 海

    // スペースキーが押されたらフェードアウトしてメニューへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        isFadeOutStart = true;
        clearSceneUI->SetFadeState(SceneUIBase::FADE_OUT_SCREEN_PLAYING);
    }
    if (isFadeOutStart && clearSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_PLAYING)
    {
        clearSceneUI->StartFadeOutScreen();
    }
    if (isFadeOutStart && clearSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_END)
    {
        // メニューシーンへ移行
        return new MenuScene(highScore);
    }

    return this;
}

/// <summary>
/// 描画
/// </summary>
void ClearScene::Draw()
{
    // オブジェクト描画
    treasureChest->Draw();      // 宝箱
    skyDome->Draw();            // スカイドーム
    boatWithChest->Draw();      // 宝石を乗せる船
    sea->Draw();                // 海

    // UI描画
    DrawUI();
}

/// <summary>
/// UIの描画
/// </summary>
void ClearScene::DrawUI()
{
    clearSceneUI->Draw(score, highScore);
}
