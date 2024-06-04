#pragma once

#include "DxLib.h"
#include <vector>
#include "Calculation.h"


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
	Game();
	virtual ~Game();

	/// <summary>
	/// ゲームフレームを数える
	/// </summary>
	void CountGameFraem();

	/// <summary>
	/// 全オブジェクトをnew　インスタンス
	/// </summary>
	void Create();

	/// <summary>
	/// 全オブジェクトの初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// ゲーム起動時のみ行う全オブジェクトの初期化
	/// </summary>
	void InitializeGameStart();

	/// <summary>
	/// インスタンス化した全オブジェクトの削除
	/// </summary>
	void DeleteGame();

	/// <summary>
	/// 全オブジェクトの更新
	/// </summary>
	void UpdateGame();

	/// <summary>
	/// 全オブジェクトの描画
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
	void DrawTimer();		// 制限時間の描画

	// Getter/Setter
	const int GetNowTimer() { return nowTimer; }
	const int GetFrameCount() { return gameFrameCount; }
	const int GetGameState() { return gameState; }
	const bool GetIsClearFlag() { return isClearFlag; }


	// 使用クラス
	Player* player;			// プレイヤー
	Enemy* enemy;			// エネミー
	Camera* camera;			// カメラ
	Collision* collision;		// 当たり判定
	UI* ui;				// UI
	SkyDome* skyDome;		// スカイドーム
	Effekseer1* effekseer1;
	FPSSetting* fpsSetting;
	Room* room;			// 部屋
	Floor* floor;			// 床
	Calculation calculation;	// 計算用
	GemManager* gemManager;		// 宝石管理クラス
	std::vector<Gem*>	gem;		// 宝石
	TreasureChest* treasureChest;	// 宝箱

private:

	// 定数
	const int GEM_TOTAL_NUM = 100;	// 宝石の総合の数

	// 変数
	int		gameState;		// 現在のステート
	int		gameFrameCount;	// ゲームフレームカウント
	int		previousTime;	// ゲームループが始まる前の時間
	int		timer;			// ゲーム時間
	int		nowTimer;		// 現在の制限時間
	bool	keyOn;			// キー入力されているか
	bool	keyRelease;		// キー入力が離れたか
	bool	prevKeyOn;		// 前フレームでキー入力があったか
	int		isHitCount;		// ヒットしてから何フレーム経過したか
	bool	isClearFlag;	// クリアしたかのフラグ
	double	isClearCount;	// クリアしてからのカウント
	bool	isDrawGetUI;	// 宝石ゲット時のUI演出をするかどうか

	// メニュー
	int		menuGraph;		// メニュー用画像

	// モデル元
	int		modelHandleGemDia;	// 宝石（ダイア）
	int		modelHandleGemRuby;	// 宝石（ルビー）

};


// ゲーム進行状態
enum STATE
{
	STATE_MENU,			// メニュー
	STATE_GAME,			// ゲーム中
	STATE_CLEAR,		// クリア
	STATE_GAMEOVER,		// ゲームオーバー
};





