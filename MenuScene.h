#pragma once

#include "SceneBase.h"

class SceneBase;

/// <summary>
/// メニューシーンクラス
/// </summary>
class MenuScene : public SceneBase
{
public:
    MenuScene();
    ~MenuScene() override;

    void Update() override;

    void Draw() override;

private:


};




