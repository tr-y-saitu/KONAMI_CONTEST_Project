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
    : isKeyOn           (false)
    , isKeyRelease      (false)
    , isPreviousKeyOn   (false)
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
    // 入力更新
    UpdateKeyState();

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
    if (isKeyRelease)
    {
        // フェードアウト開始指示
        isFadeOutStart = true;
        titleSceneUI->SetFadeState(SceneUIBase::FADE_OUT_SCREEN_PLAYING);

        // 雷のエフェクトを再生
        effectManager->PlayThunderEffect(PIRATE_SHIP_POSITION);
        // 爆発エフェクト再生
        effectManager->PlayPirateShipBigExplosionEffect(EXPLOSION_POSITION);

        // キーは離れていません
        isKeyRelease = false;
    }

    // フェードアウト
    PlayFadeOut();

    // フェード終了
    if (isFadeOutStart && titleSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_END)
    {
        // 再生中のエフェクトが無ければ
        if (!effectManager->IsAnyEffectPlaying())
        {
            return new GameScene(highScore);
        }
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

    if (isKeyRelease)
    {
        soundManager->PlaySoundListSE(SoundManager::PUSH_SE);       // プッシュ音、再生
        soundManager->PlaySoundListSE(SoundManager::THUNDER_SE);    // 雷音、再生
        soundManager->PlaySoundListSE(SoundManager::EXPLOSION_SE);  // 爆発音、再生
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

/// <summary>
/// 入力更新
/// </summary>
void TitleScene::UpdateKeyState()
{
    // キー入力すでにされている場合
    if (isKeyOn)
    {
        if (CheckHitKey(KEY_INPUT_SPACE) == 0)
        {
            isKeyOn = false;          // キーが入力されていない
            isKeyRelease = true;      // キーが離れた
        }
    }
    else if (isPreviousKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        // キーは長押しされていない && 前フレームで入力なし && キーが押された
        isKeyRelease = false;   // キーは離れていない
        isKeyOn = true;         // キーが押された
    }

    // キー入力されたら
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        isPreviousKeyOn = true;   // このフレームではキーが押された
    }
    else
    {
        isPreviousKeyOn = false;  // このフレームでキーは押されなかった
    }
}
