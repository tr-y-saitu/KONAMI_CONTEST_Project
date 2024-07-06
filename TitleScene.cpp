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
#include "EffectManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
TitleScene::TitleScene(int _highScore)
{
    highScore = _highScore;
    soundManager = SoundManager::GetInstance();
    effectManager = EffectManager::GetInstance();
    titleSceneUI = new TitleSceneUI();
    stageObjectSet = new StageObjectSet();
    camera = new Camera();
    skyDome = new SkyDome();
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
    stageObjectSet->UpdateTitleScene(); // ステージ
    camera->UpdateTitleScene();         // カメラ
    skyDome->Update();                  // スカイドーム
    UpdateSound();                      // サウンド更新
    effectManager->Update();            // エフェクト
    UpdateEffekseer3D();                // エフェクト更新

    // スペースキーが押されたらゲームへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        // フェードアウト開始指示
        isFadeOutStart = true;
        titleSceneUI->SetFadeState(SceneUIBase::FADE_OUT_SCREEN_PLAYING);

        // 雷のエフェクトを再生
        effectManager->PlayThunderEffect(PIRATE_SHIP_POSITION);
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
    soundManager->PlaySoundListBGM(SoundManager::TITLE_SCENE_BGM);
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        // プッシュ音再生
        soundManager->PlaySoundListSE(SoundManager::PUSH_SE);

        // 雷が落ちた音再生
        soundManager->PlaySoundListSE(SoundManager::THUNDER_SE);
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
    DrawEffekseer3D();      // 3Dエフェクト描画

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
