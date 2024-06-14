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
    /// 画面の明るさをだんだんあげる
    /// </summary>
    void UpBrightnessScreen();

    /// <summary>
    /// 画面の明るさをだんだん下げる
    /// </summary>
    void DownBrightnessScreen();

    /// <summary>
    /// UIの描画
    /// </summary>
    /// <param name="gameState">現在のゲームステート</param>
    /// <param name="gameScore">ゲームスコア</param>
    /// <param name="nowTimer">現在の経過時間</param>
    /// <param name="gemWaveState">現在の宝石のウェーブステート</param>
    /// <param name="isBlackOutFlag">暗転処理するかどうか</param>
    void Draw(int gameState, int gameScore, float nowTimer
        , int gemWaveState, bool isBlackOutFlag);

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
    void SetScreenBrightness(const int set) { screenBrightness = set; }

private:
	// 定数
	const int UI_COLOR = GetColor(200, 200, 200);	        // UIの文字の色
    static constexpr int TRANSPARENCY_LIMIT = 255;          // 透過度の最大上限
    static constexpr int GET_DIRECTION_DRAW_TIME = 100;     // 獲得演出を描画する時間
    static constexpr int ADD_TRANSPARENCY = 2;              // 画像の濃さを加算する値
    static constexpr int ADD_BLACK_OUT_ADD_TRANSPARENCY = 3;// 暗転する際の画像の濃さを加算する値

	// 変数
    // メニューステート
    int		menuGraph;		                // メニュー画像

    // ゲームステート
    int		getDirectionModelHandle;	    // 宝石獲得演出用モデル
    int     getDirectionCount;              // 宝石獲得時の演出を管理するカウント
	bool	isHitGemToChest;	            // 宝石と宝箱が接触した

    // クリアステート
    int     clearUIGraph;                   // クリア用UI画像
    
    // オーバーステート

    // ステート切り替え
    int     blackOutGraph;                  // 明暗転処理用画像
    int     screenBrightness;               // 画面の明るさ
};






