#pragma once

#include "SceneBase.h"

class SceneBase;
class MenuSceneUI;

/// <summary>
/// メニューシーンクラス
/// </summary>
class MenuScene : public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    MenuScene();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~MenuScene() override;

    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize() override;

    /// <summary>
    /// 更新
    /// </summary>
    void Update() override;

    /// <summary>
    /// シーンのアップデート
    /// </summary>
    /// <returns>次のシーンのポインタ</returns>
    SceneBase* UpdateScene() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    /// <summary>
    /// UIの描画
    /// </summary>
    void DrawUI();

private:
    
    MenuSceneUI* menuSceneUI;   // メニューシーンで使用するUI

};




