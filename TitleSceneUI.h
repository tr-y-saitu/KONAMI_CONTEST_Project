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

    // 変数
    int     titileGraph;            // タイトル画像
    int     keyPleaseGraph;         // キー入力指示画像
    int     lastFlashingTime;       // 最後に点滅した時間
    bool    isKeyPleaseGraphDraw;   // 文字が描画されているか
    int     highScoreFrameGraph;    // ハイスコアを描画するフレーム
};


