#pragma once

#include "SceneBase.h"
#include "SoundManager.h"

class SceneBase;
class TitleSceneUI;
class StageObjectSet;
class Camera;
class SkyDome;
class SoundManager;

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene : public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    TitleScene(int _highScore);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TitleScene() override;

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
    /// サウンドの更新
    /// </summary>
    void UpdateSound() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    /// <summary>
    /// UIの描画
    /// </summary>
    void DrawUI();

    /// <summary>
    /// フェードイン開始
    /// </summary>
    void PlayFadeIn();

    /// <summary>
    /// フェードアウト開始
    /// </summary>
    void PlayFadeOut();

private:
    
    TitleSceneUI* titleSceneUI;     // メニューシーンで使用するUI
    StageObjectSet* stageObjectSet; // ステージオブジェクト
    Camera* camera;                 // カメラ
    SkyDome* skyDome;               // スカイドーム
    SoundManager* soundManager;     // サウンドマネージャー
};




