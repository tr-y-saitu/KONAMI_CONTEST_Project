#pragma once
#include "SceneBase.h"

class MenuScene;
class GameScene;
class ClearScene;
class OverScene;

/// <summary>
/// シーンマネージャー
/// </summary>
class Game
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
    Game();

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~Game();

    /// <summary>
    /// 実際のゲームループ
    /// </summary>
    void GameLoop();

    /// <summary>
    /// シーンの切り替え
    /// </summary>
    void SceneChange();

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

private:

    // シーン
    SceneBase* nowScene;    // 現在のシーン
    SceneBase* nextScene;   // 次のシーン

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





