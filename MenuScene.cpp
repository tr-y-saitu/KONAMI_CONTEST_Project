#include "SceneBase.h"
#include "SceneUIBase.h"
#include "GameScene.h"
#include "MenuSceneUI.h"
#include "MenuScene.h"
#include "Common.h"
#include "Camera.h"
#include "StageObjectSet.h"
#include "SkyDome.h"


/// <summary>
/// コンストラクタ
/// </summary>
MenuScene::MenuScene(int _highScore)
{
    highScore       = _highScore;
    menuSceneUI     = new MenuSceneUI();
    stageObjectSet  = new StageObjectSet();
    camera          = new Camera();
    skyDome         = new SkyDome();
    Initialize();
}

/// <summary>
/// デストラクタ
/// </summary>
MenuScene::~MenuScene()
{
    delete(menuSceneUI);
    delete(stageObjectSet);
    delete(camera);
    delete(skyDome);
}

/// <summary>
/// 初期化
/// </summary>
void MenuScene::Initialize()
{
    camera->Initialize(VGet(0, 50, -150), VGet(0, 0, 0));
}

/// <summary>
/// 更新
/// </summary>
void MenuScene::Update()
{
    
}

/// <summary>
/// シーンの更新
/// </summary>
/// <returns>次のシーンのポインタ</returns>
SceneBase* MenuScene::UpdateScene()
{
    // フェードイン
    PlayFadeIn();

    // オブジェクト更新
    stageObjectSet->Update();
    camera->UpdateMenuScene();
    skyDome->Update();

    // スペースキーが押されたらゲームへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        // フェードアウト開始指示
        isFadeOutStart = true;
        menuSceneUI->SetFadeState(SceneUIBase::FADE_OUT_SCREEN_PLAYING);
    }

    // フェードアウト
    PlayFadeOut();

    // フェード終了
    if (isFadeOutStart && menuSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_END)
    {
        return new GameScene(highScore);
    }

    return this;
}

/// <summary>
/// 描画
/// </summary>
void MenuScene::Draw()
{
    // オブジェクト描画
    stageObjectSet->Draw(); // ステージオブジェクト
    skyDome->Draw();        // スカイドーム

    // UIの描画
    //DrawUI();
}

/// <summary>
/// UIの描画
/// </summary>
void MenuScene::DrawUI()
{
    // メニューシーンUIの描画
    menuSceneUI->Draw(highScore);
}

/// <summary>
/// フェードイン開始
/// </summary>
void MenuScene::PlayFadeIn()
{
    if (menuSceneUI->GetFadeState() == SceneUIBase::FADE_NONE)
    {
        menuSceneUI->SetFadeState(SceneUIBase::FADE_IN_UI_PLAYING);
    }
    if (menuSceneUI->GetFadeState() == SceneUIBase::FADE_IN_UI_PLAYING)
    {
        menuSceneUI->StartFadeInUI();
    }
}

/// <summary>
/// フェードアウト開始
/// </summary>
void MenuScene::PlayFadeOut()
{
    // フェードアウト処理
    if (isFadeOutStart && menuSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_PLAYING)
    {
        menuSceneUI->StartFadeOutScreen();
    }
}
