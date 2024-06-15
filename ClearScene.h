#pragma once

#include "SceneBase.h"


/// <summary>
/// クリアシーン
/// </summary>
class ClearScene : public SceneBase
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    ClearScene();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ClearScene() override;

    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 更新
    /// </summary>
    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    /// <summary>
    /// UIの描画
    /// </summary>
    void DrawUI() override;

private:

};


