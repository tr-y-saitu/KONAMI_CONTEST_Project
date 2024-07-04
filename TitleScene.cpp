#include "SceneBase.h"
#include "SceneUIBase.h"
#include "GameScene.h"
#include "TitleSceneUI.h"
#include "TitleScene.h"
#include "Common.h"
#include "Camera.h"
#include "StageObjectSet.h"
#include "SkyDome.h"
#include "SoundManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
TitleScene::TitleScene(int _highScore)
{
    highScore       = _highScore;
    soundManager    = SoundManager::GetInstance();
    titleSceneUI    = new TitleSceneUI();
    stageObjectSet  = new StageObjectSet();
    camera          = new Camera();
    skyDome         = new SkyDome();
    Initialize();
}

/// <summary>
/// デストラクタ
/// </summary>
TitleScene::~TitleScene()
{
    delete(titleSceneUI);
    delete(stageObjectSet);
    delete(camera);
    delete(skyDome);
}

/// <summary>
/// 初期化
/// </summary>
void TitleScene::Initialize()
{
    camera->Initialize(VGet(0, 50, -150), VGet(0, 0, 0));
}

/// <summary>
/// 更新
/// </summary>
void TitleScene::Update()
{
    
}

/// <summary>
/// シーンの更新
/// </summary>
/// <returns>次のシーンのポインタ</returns>
SceneBase* TitleScene::UpdateScene()
{
    // フェードイン
    PlayFadeIn();

    // オブジェクト更新
    stageObjectSet->Update();   // ステージ
    camera->UpdateMenuScene();  // カメラ
    skyDome->Update();          // スカイドーム
    UpdateSound();              // サウンド更新

    // スペースキーが押されたらゲームへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        // フェードアウト開始指示
        isFadeOutStart = true;
        titleSceneUI->SetFadeState(SceneUIBase::FADE_OUT_SCREEN_PLAYING);
    }

    // フェードアウト
    PlayFadeOut();

    // フェード終了
    if (isFadeOutStart && titleSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_END)
    {
        return new GameScene(highScore);
    }

    return this;
}

/// <summary>
/// サウンドの更新
/// </summary>
void TitleScene::UpdateSound()
{
    // BGM再生
    soundManager->PlayTitleSceneBGM();
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        // プッシュ音再生
        soundManager->PlayPushuSE();
    }
}

/// <summary>
/// 描画
/// </summary>
void TitleScene::Draw()
{
    // オブジェクト描画
    stageObjectSet->Draw(); // ステージオブジェクト
    skyDome->Draw();        // スカイドーム

    // UIの描画
    DrawUI();
}

/// <summary>
/// UIの描画
/// </summary>
void TitleScene::DrawUI()
{
    // メニューシーンUIの描画
    titleSceneUI->Draw(highScore);
}

/// <summary>
/// フェードイン開始
/// </summary>
void TitleScene::PlayFadeIn()
{
    if (titleSceneUI->GetFadeState() == SceneUIBase::FADE_NONE)
    {
        titleSceneUI->SetFadeState(SceneUIBase::FADE_IN_UI_PLAYING);
    }
    if (titleSceneUI->GetFadeState() == SceneUIBase::FADE_IN_UI_PLAYING)
    {
        titleSceneUI->StartFadeInUI();
    }
}

/// <summary>
/// フェードアウト開始
/// </summary>
void TitleScene::PlayFadeOut()
{
    // フェードアウト処理
    if (isFadeOutStart && titleSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_PLAYING)
    {
        titleSceneUI->StartFadeOutScreen();
    }
}
