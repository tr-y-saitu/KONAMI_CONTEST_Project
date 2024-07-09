#pragma once
#include "Common.h"
#include "SceneUIBase.h"

/// <summary>
/// クリアシーンUI
/// </summary>
class ClearSceneUI : public SceneUIBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    ClearSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ClearSceneUI();

    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw(int score,int highScore);

    /// <summary>
    /// 文字の点滅
    /// </summary>
    void PlayKeyPleaseTextFlashing();

private:
    // 定数
    // 共通
    const int UI_COLOR = GetColor(20, 20, 10);                      // UIの色
    const int UI_COLOR_RED = GetColor(255, 0, 0);                   // UIの色(赤)
    // フレーム
    static constexpr int CLEAR_FRAME_DRAW_POSITION_X = 0;           // クリア時の画面フレームのX描画座標
    static constexpr int CLEAR_FRAME_DRAW_POSITION_Y = 0;           // クリア時の画面フレームのY描画座標
    // 点滅文字
    static constexpr int FLASHING_INTERVAL = 500;                   // 文字点滅の間隔(GetNowCountなのでミリ秒)
    static constexpr int KEY_PLEASE_TEXT_POSITION_X = 530;          // 入力指示文字X座標
    static constexpr int KEY_PLEASE_TEXT_POSITION_OFFSET_Y = 25;    // 入力指示文字Y座標ずらし量
    static constexpr int KEY_PLEASE_TEXT_EXPAND_RATE = 1;           // 入力指示文字の拡大率
    static constexpr int KEY_PLEASE_TEXT_ANGLE = 0;                 // 入力指示文字の回転率
    static constexpr int KEY_PLEASE_TEXT_DRAW_POSITION_Y = SCREEN_SIZE_Y - (SCREEN_SIZE_Y / 4); // キー入力指示の描画Y位置
    // スコア
    static constexpr int SCORE_DRAW_POSITION_Y = 420;               // スコアを描画するY座標
    static constexpr int HIGH_SCORE_DRAW_POSITION_Y = 480;          // ハイスコアを描画するY座標
    // リザルトテキスト
    static constexpr int RESULT_DRAW_POSITION_Y = 150;              // リザルト画像を描画するY座標
    static constexpr int RESULT_DRAW_EXPAND_RATE = 1;               // リザルト画像の拡大率
    static constexpr int RESULT_DRAW_ANGLE = 0;                     // リザルト画像の回転率
    // スコアボード
    static constexpr int SOCRE_BOARD_EXPAND_RATE = 1;               // スコアボードの拡大率
    static constexpr int SOCRE_BOARD_ANGLE = 0;                     // スコアボードの回転率

    // 変数
    int     clearUIFrame;           // クリアした時のUI画像
    int     scoreBoardGraph;        // スコアボード画像
    int     resultsGraph;           // リザルト画像
    int     keyPleaseGraph;         // キー入力指示画像
    int     lastFlashingTime;       // 最後に点滅した時間
    bool    isKeyPleaseGraphDraw;   // 文字が描画されているか
};


