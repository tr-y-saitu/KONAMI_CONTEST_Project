#pragma once
#include "DxLib.h"
#include <stdio.h>
#include <iostream>
#include "SceneUIBase.h"

class WaveConstants;

/// <summary>
/// ゲームシーンUI
/// </summary>
class GameSceneUI : public SceneUIBase
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameSceneUI();

    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();



    /// <summary>
    /// 描画
    /// </summary>
    /// <param name="gameScore">ゲームスコア</param>
    /// <param name="nowTimer">現在の経過時間</param>
    /// <param name="gemWaveState">現在の宝石のウェーブステート</param>
    /// <param name="isBlackOut">暗転処理するかどうか</param>
    /// <param name="waveEndTime">現在のウェーブの終了時間</param>
    void Draw(int gameScore, float nowTimer,
        int gemWaveState, bool isBlackOut,int waveEndTime,
        char* waveText);

    /// <summary>
    /// スコアの描画
    /// </summary>
    /// <param name="pos">スコアを描画する座標</param>
    /// <param name="fontSize">フォントサイズ</param>
    /// <param name="score">スコア</param>
    void DrawScore(VECTOR pos, int fontSize, int score);

    /// <summary>
    /// タイマーバーの描画
    /// </summary>
    /// <param name="nowTimer">現在時間</param>
    /// <param name="waveEndTime">現在のウェーブが終了する時間</param>
    void DrawTimerBar(int nowTimer,int waveEndTime);


    void DrawTextAtSize(char* text,int textSize,VECTOR textPos,int color);

    // Setter
    void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
    // 定数
    const int UI_COLOR = GetColor(200, 200, 200);	        // UIの文字の色
    const int UI_COLOR_BLACK = GetColor(0, 0, 0);           // UIの文字の色(黒)
    const int UI_COLOR_RED = GetColor(200, 0, 0);           // UIの文字の色(赤)
    static constexpr int FONT_SIZE_SCORE = 50;              // スコアのフォントサイズ
    static constexpr int GET_DIRECTION_DRAW_TIME = 100;     // 獲得演出を描画する時間
    static constexpr int TIMER_FRAME_TOP_LEFT_X = 200;      // タイマーフレームを描画する左上頂点X座標
    static constexpr int TIMER_FRAME_TOP_LEFT_Y = 800;      // タイマーフレームを描画する左上頂点Y座標
    static constexpr int TIMER_FRAME_BOTTOM_RIGHT_X = 1400; // タイマーフレームを描画する右下頂点X座標
    static constexpr int TIMER_FRAME_BOTTOM_RIGHT_Y = 950;  // タイマーフレームを描画する右下頂点Y座標
    static constexpr int TIMER_BAR_TOP_LEFT_X = 375;        // タイマーバーを描画する左上頂点X座標
    static constexpr int TIMER_BAR_TOP_LEFT_Y = 840;        // タイマーバーを描画する左上頂点Ｙ座標
    static constexpr int TIMER_BAR_BOTTOM_RIGHT_X = 1350;   // タイマーバーを描画する右下頂点Ｘ座標
    static constexpr int TIMER_BAR_BOTTOM_RIGHT_Y = 910;    // タイマーバーを描画する右下頂点Ｙ座標

    // 変数
    int		getDirectionModelHandle;	    // 宝石獲得演出用モデル
    int     timerBarFrameGraph;             // 時間表示バーのフレーム画像
    int     timerBarGraph;                  // 時間表示バーの画像
    int     getDirectionCount;              // 宝石獲得時の演出を管理するカウント
    bool	isHitGemToChest;	            // 宝石と宝箱が接触した


};


