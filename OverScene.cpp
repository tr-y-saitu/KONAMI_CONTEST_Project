#include "SceneBase.h"
#include "MenuScene.h"
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
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        return new MenuScene();
    }

    return this;
}

/// <summary>
/// 描画
/// </summary>
void OverScene::Draw()
{

}

/// <summary>
/// UIの描画
/// </summary>
void OverScene::DrawUI()
{

}

