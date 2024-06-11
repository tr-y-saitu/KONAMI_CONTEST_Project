#pragma once


#include "DxLib.h"

class Game;
class Player;
class TreasureChest;

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
	/// UIの更新
	/// </summary>
	/// <param name="state">ゲームステート</param>
	/// <param name="player">プレイヤークラス</param>
	/// <param name="clearFlag">クリアしているかどうか</param>
	/// <param name="chest">宝箱クラス</param>
	/// <param name="nowTimer">ゲームの現在経過時間</param>
	void Draw(int state,Player& player,bool& isDrawUIFlag, TreasureChest& chest,float nowTimer, GemManager& gemManager,int score);	// 描画

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






