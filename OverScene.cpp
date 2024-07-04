#include "SceneBase.h"
#include "TitleScene.h"
#include "OverScene.h"

/// <summary>
/// コンストラクタ
/// </summary>
OverScene::OverScene()
{
}

/// <summary>
/// デストラクタ
/// </summary>
OverScene::~OverScene()
{
}

/// <summary>
/// 初期化
/// </summary>
void OverScene::Initialize()
{

}

/// <summary>
/// 更新
/// </summary>
void OverScene::Update()
{

}

/// <summary>
/// シーンの更新
/// </summary>
/// <returns>次のシーンのポインタ</returns>
SceneBase* OverScene::UpdateScene()
{
    // スペースキーが押されたらメニューへ
    if (CheckHitKey(KEY_INPUT_SPACE) == 1 || GetJoypadInputState(DX_INPUT_KEY_PAD1))
    {
        return new TitleScene(highScore);
    }

    return this;
}

/// <summary>
/// サウンドの更新
/// </summary>
void OverScene::UpdateSound()
{

}

/// <summary>
/// 描画
/// </summary>
void OverScene::Draw()
{
    // UIの描画
    DrawUI();
}

/// <summary>
/// UIの描画
/// </summary>
void OverScene::DrawUI()
{

}

