#pragma once
#include "SceneBase.h"


class MenuScene;
class GameScene;
class ClearScene;
class OverScene;

/// <summary>
/// シーンマネージャー
/// </summary>
class SceneManager
{
public:
    /// <summary>
    /// シーンの進行状態
    /// </summary>
    enum SceneState
    {
        SCENE_MENU,     // メニュー
        SCENE_GAME,     // ゲーム
        SCENE_CLEAR,    // クリア
        SCENE_OVER      // オーバー
    };

    /// <summary>
    /// コンストラクタ
    /// </summary>
    SceneManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~SceneManager();

    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    /// <summary>
    /// 現在のシーンの切り替え
    /// </summary>
    void ChangeNowScene();

    /// <summary>
    /// 入力処理
    /// </summary>
    void ProcessKey();

    /// <summary>
    /// 現在制限時間の描画
    /// </summary>
    void DrawTimer();

    /// <summary>
    /// 現在制限時間の再設定
    /// </summary>
    void SettingTimer();

private:

    // シーン
    MenuScene* menuScene;
    GameScene* gameScene;
    ClearScene* clearScene;
    OverScene* overScene;

    // ステート
    int     sceneState;     // 現在のシーン

    // 時間
    int		previousTime;	// ゲームループが始まる前の時間
    int		timer;			// ゲーム時間
    float	nowTimer;		// 現在の制限時間

    // スコア
    int     score;          // スコア

    // キー入力
    bool	keyOn;			// キー入力されているか
    bool	keyRelease;		// キー入力が離れたか
    bool	prevKeyOn;		// 前フレームでキー入力があったか


};



