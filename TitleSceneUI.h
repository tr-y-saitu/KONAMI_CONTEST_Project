#pragma once
#include "SceneUIBase.h"

/// <summary>
/// メニューシーンUI
/// </summary>
class TitleSceneUI : public SceneUIBase
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    TitleSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TitleSceneUI();

    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw(int highScore);

    /// <summary>
    /// 文字の点滅描画
    /// </summary>
    void DrawKeyPleaseTextFlashing();

private:
    // 定数
    const int UI_COLOR_WHITE = GetColor(255, 255, 255); // UIの色(白)
    const int UI_COLOR_BLACK = GetColor(0, 0, 0);       // UIの文字の色(黒)
    static const int UI_FONT_SIZE = 60;                 // UIのフォントサイズ
    static constexpr int FLASHING_INTERVAL = 800;       // 文字点滅の間隔(GetNowCountなのでミリ秒)
    static constexpr int KEY_PLEASE_TEXT_OFFSET_Y = 30; // キー入力指示のオフセット
    // タイトルロゴ
    static constexpr int TITLE_LOGO_POSITION_X = SCREEN_SIZE_X / 2; // タイトルロゴのX描画位置
    static constexpr int TITLE_LOGO_POSITION_Y = SCREEN_SIZE_Y / 4; // タイトルロゴのY描画位置
    static constexpr int TITLE_LOGO_EXPAND_RATE = 1;                // タイトルロゴの拡大率
    static constexpr int TITLE_LOGO_ANGEL = 0;                      // タイトルロゴの回転率
    // スコア関係
    static constexpr int SCORE_DRAW_POSITION_X = SCREEN_SIZE_X / 2; // スコアを描画するX座標
    static constexpr int SCORE_DRAW_POSITION_Y = 525;               // スコアを描画するY座標
    static constexpr int SOCRE_FRAME_DRAW_POSITION_Y = 495;         // スコアフレームを描画するY座標
    static constexpr int SCORE_FRAME_EXPAND_RATE = 1;               // スコアフレームの拡大率
    static constexpr int SCORE_FRAME_ANGLE = 0;                     // スコアフレームの回転率
    // キー入力
    static constexpr char* KEY_PLEASE_TEXT = "Press Any Button to Start";   // 文字列「Press Any Button to Start」

    // 変数
    int     titileGraph;            // タイトル画像
    int     keyPleaseGraph;         // キー入力指示画像
    int     lastFlashingTime;       // 最後に点滅した時間
    bool    isKeyPleaseGraphDraw;   // 文字が描画されているか
    int     highScoreFrameGraph;    // ハイスコアを描画するフレーム
};


