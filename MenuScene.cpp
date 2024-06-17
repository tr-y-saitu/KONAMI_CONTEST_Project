#include "SceneBase.h"
#include "SceneUIBase.h"
#include "GameScene.h"
#include "MenuSceneUI.h"
#include "MenuScene.h"


/// <summary>
/// コンストラクタ
/// </summary>
MenuScene::MenuScene()
{
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
    // スペースキーが押されたらゲームへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        // フェードアウト開始指示
        menuSceneUI->SetFadeState(SceneUIBase::FADE_PLAYING);
    }

    // フェードアウト処理
    if (menuSceneUI->GetFadeState() == SceneUIBase::FADE_PLAYING)
    {
        menuSceneUI->StartFadeOutScreen();
    }

    // フェード終了
    if (menuSceneUI->GetFadeState() == SceneUIBase::FADE_END)
    {
        return new GameScene();
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
    menuSceneUI->Draw();
}
