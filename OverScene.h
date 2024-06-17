#pragma once
#include "SceneBase.h"


class SceneBase;

/// <summary>
/// 
/// </summary>
class OverScene : public SceneBase
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    OverScene();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~OverScene() override;

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

};



