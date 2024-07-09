#pragma once
#include "DxLib.h"
#include <stdio.h>
#include <iostream>
#include "SceneUIBase.h"

class WaveConstants;
class TimeLimitsWarningUI ;

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
    /// 更新
    /// </summary>
    /// <param name="nowTimer">現在時間</param>
    /// <param name="waveEndTime">ウェーブ終了時間</param>
    void Update(int nowTimer,int waveEndTime);

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
    /// <param name="score">スコア</param>
    void DrawScore(int score);

    /// <summary>
    /// 宝石のスコア表を描画
    /// </summary>
    void DrawGemScoreTable();

    /// <summary>
    /// タイマーバーの描画
    /// </summary>
    /// <param name="nowTimer">現在時間</param>
    /// <param name="waveEndTime">現在のウェーブが終了する時間</param>
    void DrawTimerBar(int nowTimer,int waveEndTime);

    /// <summary>
    /// ウェーブが終了した時のアニメーション再生
    /// </summary>
    void PlayWaveFinishAnimation();

    // Setter
    void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
    // 共通
    const int UI_COLOR = GetColor(200, 200, 200);           // UIの文字の色
    const int UI_COLOR_BLACK = GetColor(0, 0, 0);           // UIの文字の色(黒)
    const int UI_COLOR_RED = GetColor(200, 0, 0);           // UIの文字の色(赤)
    const int UI_COLOR_WHITE = GetColor(255, 255, 255);     // UIの文字の色(白)
    static constexpr int GET_DIRECTION_DRAW_TIME = 100;     // 獲得演出を描画する時間
    // スコア
    static constexpr int FONT_SIZE_SCORE = 50;              // スコアのフォントサイズ
    static constexpr int SCORE_POSITION_X = 1250;           // スコアを描画するX座標
    static constexpr int SCORE_POSITION_Y = 25;             // スコアを描画するY座標
    static constexpr int SCORE_FRAME_OFFSET_X = 125;        // スコア装飾用のフレームのX軸ずらし量
    static constexpr int SCORE_FRAME_OFFSET_Y = 28;         // スコア装飾用のフレームのY軸ずらし量
    // 宝石スコア表
    static constexpr int GEM_SCORE_TABLE_OFFSET_Y = 100;    // 宝石スコア表を描画するY軸のずらし量
    // タイマーUI
    static constexpr int TIMER_FRAME_TOP_LEFT_X = 0;        // タイマーフレームを描画する左上頂点X座標
    static constexpr int TIMER_FRAME_TOP_LEFT_Y = 800;      // タイマーフレームを描画する左上頂点Y座標
    static constexpr int TIMER_FRAME_BOTTOM_RIGHT_X = 1200; // タイマーフレームを描画する右下頂点X座標
    static constexpr int TIMER_FRAME_BOTTOM_RIGHT_Y = 950;  // タイマーフレームを描画する右下頂点Y座標
    static constexpr int TIMER_BAR_TOP_LEFT_X = TIMER_FRAME_TOP_LEFT_X + 175;           // タイマーバーを描画する左上頂点X座標
    static constexpr int TIMER_BAR_TOP_LEFT_Y = TIMER_FRAME_TOP_LEFT_Y + 40;            // タイマーバーを描画する左上頂点Ｙ座標
    static constexpr int TIMER_BAR_BOTTOM_RIGHT_X = TIMER_FRAME_BOTTOM_RIGHT_X - 50;    // タイマーバーを描画する右下頂点Ｘ座標
    static constexpr int TIMER_BAR_BOTTOM_RIGHT_Y = TIMER_FRAME_BOTTOM_RIGHT_Y - 40;    // タイマーバーを描画する右下頂点Ｙ座標
    static constexpr int FONT_SIZE_NOW_TIME = 40;           // 現在時間のフォントサイズ
    // 制限時間警告UI
    static constexpr int WARNING_TIME_LIMIT = 8;            // 残り制限時間を警告するための時間
    static constexpr int UI_MOVE_ADDITION = 5;              // UIの移動量
    static constexpr int FONT_SIZE_WARNING_UI = 30;         // 制限時間UIのフォントサイズ
    // WAVEステート
    static constexpr int FONT_SIAE_WAVE_STATE_UI = 50;      // WAVEステートのフォントサイズ
    static constexpr int WAVE_TITLE_MESSAGE_X = 50;         // WAVEごとのタイトルを描画するX座標
    static constexpr int WAVE_TITLE_MESSAGE_Y = 750;        // WAVEごとのタイトルを描画するY座標
    // WAVEフィニッシュ演出
    static constexpr double WAVE_END_GRAPH_EXPAND_RATE_SPEED = 0.5; // WAVE終了演出画像の拡大スピード
    static constexpr double WAVE_END_GRAPH_EXPAND_MAX_LIMIT = 1.4;  // WAVE終了演出画像の最大拡大率
    static constexpr double WAVE_END_GRAPH_ANGLE_SPEED = 1.0;       // WAVE終了演出画像の回転スピード

    // 変数
    int     getDirectionModelHandle;        // 宝石獲得演出用モデル
    TimeLimitsWarningUI * timeLimitsWarningUI;
    int     timerBarFrameGraph;             // 時間表示バーのフレーム画像
    int     timerBarGraph;                  // 時間表示バーの画像
    int     getDirectionCount;              // 宝石獲得時の演出を管理するカウント
    bool    isHitGemToChest;                // 宝石と宝箱が接触した
    int     scoreFrameGrpah;                // スコア装飾用フレーム
    int     gemScoreTableGraph;             // 宝石スコア表画像
    int     waveEndFinishGraph;             // Waveが終了した時の演出画像
    double  waveEndFinishGraphExpandRate;   // Wave終了演出用画像の拡大率
    double  waveEndFinishGraphAngle;        // Wave終了演出用回転率(ラジアン度)
};


