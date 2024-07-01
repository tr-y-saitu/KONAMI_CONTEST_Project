#pragma once

#include "SceneBase.h"

class SceneBase;
class Player;
class TreasureChest;
class GemManager;
class Collision;
class Camera;
class SkyDome;
class Room;
class Calculation;
class GameSceneUI;
class EffectManager;
class StageObjectSet;
class SkyDome;

/// <summary>
/// ゲームシーンクラス
/// </summary>
class GameScene : public SceneBase
{
public:
    // SceneBaseクラスを継承。内容が異なるものだけoverrideする

    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameScene(int _highScore);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameScene() override;

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
    void DrawUI() override;

    /// <summary>
    /// スコアの更新
    /// </summary>
    /// <param name="chest">宝箱</param>
    void UpdateScore(TreasureChest& chest);

    /// <summary>
    /// 現在経過時間の更新
    /// </summary>
    /// <param name="resetFlag">計測時間をリセットするかどうかのフラグ</param>
    void SettingTimer(GemManager& gemManager);

    // Getter
    const bool GetIsNextScene() { return isNextScene; }

private:
    static constexpr int STATE_GAME_TIME_LIMIT = 40; // ゲームステートが終了(する時間)(初期40)

    // インスタンス
    Player*         player;
    TreasureChest*  treasureChest;
    GemManager*     gemManager;
    Collision*      collision;
    Camera*         camera;
    Room*           room;
    GameSceneUI*    gameSceneUI;
    EffectManager*  effectManager;
    StageObjectSet*   stageObjectSet;
    SkyDome*        skyDome;

    // 時間
    int     previousTime;   // ゲームループが始まる前の時間
    int     timer;          // ゲーム時間
    float   nowTimer;       // 現在の制限時間

    // スコア
    bool    isScoreUp;      // スコアアップフラグ

    // シーン管理
    bool    isNextScene;        // 次のシーン移行すかどうか

};


