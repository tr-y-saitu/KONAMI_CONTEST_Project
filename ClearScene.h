#pragma once
#include "SceneBase.h"

class ClearSceneUI;
class TreasureChest;
class GemManager;
class Collision;
class Camera;
class SkyDome;
class BoatWithChest;
class Sea;


/// <summary>
/// クリアシーン
/// </summary>
class ClearScene : public SceneBase
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    ClearScene(int _score,int _highScore);

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
    ClearSceneUI*   clearSceneUI;       // クリアシーンで使用するUI
    TreasureChest*  treasureChest;      // 宝箱
    GemManager*     gemManager;         // 宝石マネージャー
    Camera*         camera;             // カメラ
    SkyDome*        skyDome;            // スカイドーム
    BoatWithChest*  boatWithChest;      // 宝箱を乗せる船
    Sea*            sea;                // 海
};


