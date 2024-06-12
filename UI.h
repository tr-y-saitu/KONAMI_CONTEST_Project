#pragma once


#include "DxLib.h"

class Game;
class Player;
class TreasureChest;
class GemManager;

class UI
{
public:
	UI();		// コンストラクタ
	~UI();		// デストラクタ

	/// <summary>
	/// UIの初期化
	/// </summary>
	void Initialize();

    /// <summary>
    /// UIの描画
    /// </summary>
    /// <param name="gameState">現在のゲームステート</param>
    /// <param name="score">ゲームスコア</param>
    /// <param name="nowTimer">現在の経過時間</param>
    /// <param name="gemWaveState">現在の宝石のウェーブステート</param>
    void Draw(int gameState, int gameScore, float nowTimer, int gemWaveState);

    /// <summary>
    /// スコアの描画
    /// </summary>
    /// <param name="pos">スコアを描画する座標</param>
    /// <param name="fontSize">フォントサイズ</param>
    /// <param name="score">スコア</param>
    void DrawScore(VECTOR pos, int fontSize, int score);

	// Getter
	const bool GetIsHitGemToChest()const { return isHitGemToChest; }

	// Setter
	void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
	// 定数
	const int UI_COLOR = GetColor(200, 200, 200);	// UIの文字の色
    const int GET_DIRECTION_DRAW_TIME = 100;        // 獲得演出を描画する時間

	// 変数
	int		menuGraph;		                // メニュー画像
	int		getDirectionModelHandle;	    // 宝石獲得演出用モデル
    int     getDirectionCount;              // 宝石獲得時の演出を管理するカウント
	bool	isHitGemToChest;	            // 宝石と宝箱が接触した
};






