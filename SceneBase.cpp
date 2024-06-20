#include "SceneBase.h"
#include "MenuScene.h"
#include "GameScene.h"


/// <summary>
/// コンストラクタ
/// </summary>
SceneBase::SceneBase()
    : isFadeOutStart    (false)
{
}

/// <summary>
/// デストラクタ
/// </summary>
SceneBase::~SceneBase()
{
}

/// <summary>
/// ベース初期化
/// </summary>
/// <returns>初期化するSceneBase*型のnewインスタンス</returns>
SceneBase* SceneBase::InitializeBase()
{
    return new MenuScene(0,0);
}

/// <summary>
/// 初期化
/// </summary>
void SceneBase::Initialize()
{

}




