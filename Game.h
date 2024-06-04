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
	void CountGameFraem() ;	// ゲームフレームを数える
	void Create();			// 生成
	void Initialize();		// 初期化処理
	void InitializeGameStart();	// ゲーム最初の初期化
	void DeleteGame();		// 生成したオブジェクトの削除
	void UpdateGame();		// ゲームアップデート
	void DrawGame();		// ゲーム描画
	void ChangeGameState();	// ゲームステートの切り替え
	void ProcessKey();		// ゲーム進行にかかわるキー入力処理
	void DrawTimer();		// 制限時間の描画
	void SettingTimer();	// 現在経過時間の更新
	

	const int GetNowTimer() { return nowTimer; }
	const int GetFrameCount() { return gameFrameCount; }
	const int GetGameState() { return gameState; }
	const bool GetIsClearFlag() { return isClearFlag; }

	// 使用クラス
	Player*		player;
	Enemy*		enemy;
	Camera*		camera;
	Collision*	collision;
	BGObj*		bgobj[5];
	BGObj*		bgobj2[4];
	UI*			ui;
	SkyDome*	skyDome;
	BG*			bg[3];
	Effekseer1* effekseer1;
	FPSSetting* fpsSetting;
	Room*		room;
	Floor*		floor;
	Calculation calculation;
	GemManager*	gemManager;
	TreasureChest* treasureChest;

	std::vector<Gem*>	gem;

private:
	// 定数
	const int GEM_TOTAL_NUM = 100;	// 宝石の総合の数

	// 変数
	int		gameState;		// 現在のステート
	int		gameFrameCount;	// ゲームフレームカウント
	int		previousTime;	// ゲームループが始まる前の時間
	int		timer;			// ゲーム時間
	float	nowTimer;		// 現在の制限時間
	bool	keyOn;			// キー入力されているか
	bool	keyRelease;		// キー入力が離れたか
	bool	prevKeyOn;		// 前フレームでキー入力があったか
	int		isHitCount;		// ヒットしてから何フレーム経過したか
	bool	isClearFlag;	// クリアしたかのフラグ
	double	isClearCount;	// クリアしてからのカウント
	bool	isDrawGetUi;	// 宝石ゲット時のUI演出をするかどうか

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





