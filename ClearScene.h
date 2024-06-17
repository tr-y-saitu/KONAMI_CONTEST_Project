#pragma once
#include "SceneBase.h"

class ClearSceneUI;
class TreasureChest;
class GemManager;
class Collision;
class Camera;
class SkyDome;
class Room;

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
    void DrawUI() override;

private:
    ClearSceneUI*   clearSceneUI;     // クリアシーンで使用するUI
    TreasureChest*  treasureChest;
    GemManager*     gemManager;
    Collision*      collision;
    Camera*         camera;
    SkyDome*        skyDome;
    Room*           room;

};


