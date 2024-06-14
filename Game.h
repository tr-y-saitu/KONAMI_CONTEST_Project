#pragma once

#include "DxLib.h"
#include <vector>
#include <list>
#include "Calculation.h"

using namespace std;

// プロトタイプ宣言
class BG;
class Room;
class Floor;
class Player;
class Enemy;
class Collision;
class Camera;
class BGObj;
class Car;
class UI;
class SkyDome;
class Confetti;
class Effekseer1;
class FPSSetting;
class WorldSprite;
class Calculation;
class Gem;
class GemManager;
class TreasureChest;


/// <summary>
/// ゲーム制御クラス
/// </summary>
class Game
{
public:

    /// <summary>
    /// ゲームの進行状態
    /// </summary>
    enum STATE
    {
        STATE_MENU,			// メニュー
        STATE_GAME,			// ゲーム中
        STATE_CLEAR,		// クリア
        STATE_GAMEOVER,		// ゲームオーバー
    };

	Game();                 // コンストラクタ
	virtual ~Game();        // デストラクタ

	/// <summary>
	/// 現在のゲームフレームを数える
	/// </summary>
	void CountGameFraem() ;

	/// <summary>
	/// ゲームで使用する全オブジェクトをnewインスタンス
	/// </summary>
	void Create();

	/// <summary>
	/// ゲームオブジェクトすべての初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// ゲーム開始前最初の全オブジェクト初期化処理
	/// </summary>
	void InitializeGameStart();

	/// <summary>
	/// newインスタンスしたオブジェクトの削除
	/// </summary>
    void DeleteGame();

	/// <summary>
	/// ゲーム更新
	/// </summary>
	void UpdateGame();

	/// <summary>
	/// ゲーム描画
	/// </summary>
	void DrawGame();

	/// <summary>
	/// ゲームステートの切り替え
	/// </summary>
	void ChangeGameState();

	/// <summary>
	/// ゲーム進行にかかわるキー入力処理
	/// </summary>
	void ProcessKey();

	/// <summary>
	/// 制限時間の描画
	/// </summary>
	void DrawTimer();

	/// <summary>
	/// 現在経過時間の更新
	/// </summary>
	/// <param name="resetFlag">計測時間をリセットするかどうかのフラグ</param>
	void SettingTimer(GemManager& gemManager);

    /// <summary>
    /// スコアの更新
    /// </summary>
    /// <param name="chest">宝箱</param>
    void UpdateScore(TreasureChest& chest);
	

	const int GetNowTimer() { return nowTimer; }
	const int GetFrameCount() { return gameFrameCount; }
	const int GetGameState() { return gameState; }
	const bool GetIsClearFlag() { return isClearFlag; }
    const int GetScore() { return score; }

	// 使用クラス
	Player*		player;
	Enemy*		enemy;
	Camera*		camera;
	Collision*	collision;
	UI*			ui;
	SkyDome*	skyDome;
	BG*			bg[3];
	Effekseer1* effekseer1;
	FPSSetting* fpsSetting;
	Room*		room;
	Calculation calculation;
	GemManager*	gemManager;
	TreasureChest* treasureChest;

    vector<Gem*>	gem;

private:
	// 定数
	const int GEM_TOTAL_NUM = 100;	                // 宝石の総合の数
    static constexpr int STATE_GAME_TIME_LIMIT = 4; // ゲームステートが終了する時間

	// 変数
	int		gameState;		// 現在のステート
	int		gameFrameCount;	// ゲームフレームカウント
	int		previousTime;	// ゲームループが始まる前の時間
	int		timer;			// ゲーム時間
	float	nowTimer;		// 現在の制限時間
	int		isHitCount;		// ヒットしてから何フレーム経過したか
	bool	isClearFlag;	// クリアしたかのフラグ
	double	isClearCount;	// クリアしてからのカウント
	bool	isDrawGetUi;	// 宝石ゲット時のUI演出をするかどうか

    // スコア
    int     score;          // スコア

    // キー入力
	bool	keyOn;			// キー入力されているか
	bool	keyRelease;		// キー入力が離れたか
	bool	prevKeyOn;		// 前フレームでキー入力があったか

	// メニュー
	int		menuGraph;		// メニュー用画像

	// モデル元
	int		modelHandleGemDia;	// 宝石（ダイア）
	int		modelHandleGemRuby;	// 宝石（ルビー）

    // UI
    bool    isBlackOutFlag;     // 暗転明転処理の指示

};








