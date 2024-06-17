#include "SceneBase.h"
#include "MenuScene.h"
#include "GameScene.h"



SceneBase::SceneBase()
{
}

SceneBase::~SceneBase()
{
}


SceneBase* SceneBase::InitializeBase()
{
    return new MenuScene();
}

void SceneBase::Initialize()
{

}




