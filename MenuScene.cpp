#include "SceneBase.h"
#include "SceneUIBase.h"
#include "GameScene.h"
#include "MenuSceneUI.h"
#include "MenuScene.h"


/// <summary>
/// コンストラクタ
/// </summary>
MenuScene::MenuScene(int _score, int _highScore)
{
    score = _score;
    highScore = _highScore;
    menuSceneUI = new MenuSceneUI();
}

/// <summary>
/// デストラクタ
/// </summary>
MenuScene::~MenuScene()
{
    delete(menuSceneUI);
}

/// <summary>
/// 初期化
/// </summary>
void MenuScene::Initialize()
{

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
    if (menuSceneUI->GetFadeState() == SceneUIBase::FADE_NONE)
    {
        menuSceneUI->SetFadeState(SceneUIBase::FADE_IN_UI_PLAYING);
    }
    if (menuSceneUI->GetFadeState() == SceneUIBase::FADE_IN_UI_PLAYING)
    {
        menuSceneUI->StartFadeInUI();
    }

    // スペースキーが押されたらゲームへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        // フェードアウト開始指示
        isFadeOutStart = true;
        menuSceneUI->SetFadeState(SceneUIBase::FADE_OUT_SCREEN_PLAYING);
    }

    // フェードアウト処理
    if (isFadeOutStart && menuSceneUI->GetFadeState() == SceneUIBase::FADE_OUT_SCREEN_PLAYING)
    {
        menuSceneUI->StartFadeOutScreen();
    }

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
    // UIの描画
    DrawUI();
}

/// <summary>
/// UIの描画
/// </summary>
void MenuScene::DrawUI()
{
    // メニューシーンUIの描画
    menuSceneUI->Draw(highScore);
}
