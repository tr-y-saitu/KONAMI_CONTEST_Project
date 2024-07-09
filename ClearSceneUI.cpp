#include "DxLib.h"
#include "ClearSceneUI.h"
#include "Common.h"


/// <summary>
/// コンストラクタ
/// </summary>
ClearSceneUI::ClearSceneUI()
    : lastFlashingTime         (0)
    , isKeyPleaseGraphDraw  (false)
{
    clearUIFrame = LoadGraph("data/texture/Clear/FrameUINoClearColor.png");
    scoreBoardGraph = LoadGraph("data/texture/Clear/socreResult600x200.png");
    resultsGraph = LoadGraph("data/texture/Clear/ResultsImg.png");
    keyPleaseGraph = LoadGraph("data/texture/State/KeyRelese.png");
}

/// <summary>
/// デストラクタ
/// </summary>
ClearSceneUI::~ClearSceneUI()
{
    DeleteGraph(clearUIFrame);
    DeleteGraph(scoreBoardGraph);
    DeleteGraph(resultsGraph);
    DeleteGraph(keyPleaseGraph);
}

/// <summary>
/// 更新
/// </summary>
void ClearSceneUI::Update()
{

}

/// <summary>
/// 描画
/// </summary>
void ClearSceneUI::Draw(int score, int highScore)
{
    // クリアUI
    DrawGraph(CLEAR_FRAME_DRAW_POSITION_X, CLEAR_FRAME_DRAW_POSITION_Y, clearUIFrame, true);

    // リザルトテキスト
    DrawRotaGraph(SCREEN_SIZE_X_HALF, RESULT_DRAW_POSITION_Y,
        RESULT_DRAW_EXPAND_RATE, RESULT_DRAW_ANGLE, resultsGraph, true);

    // スコアボード
    DrawRotaGraph(SCREEN_SIZE_X_HALF, SCREEN_SIZE_Y_HALF,
        SOCRE_BOARD_EXPAND_RATE, SOCRE_BOARD_ANGLE, scoreBoardGraph, true);

    // スコア描画
    char scoreText[256];
    snprintf(scoreText, sizeof(scoreText), "SCORE : %d", score);
    DrawStringCenterScreen(scoreText, SCORE_DRAW_POSITION_Y, UI_COLOR);

    // ハイスコア描画
    char highScoreText[256];
    snprintf(highScoreText, sizeof(highScoreText), "HIGHSCORE : %d", highScore);
    DrawStringCenterScreen(highScoreText, HIGH_SCORE_DRAW_POSITION_Y, UI_COLOR_RED);

    // キー入力指示
    DrawRotaGraph(SCREEN_SIZE_X_HALF, KEY_PLEASE_TEXT_DRAW_POSITION_Y,
        KEY_PLEASE_TEXT_EXPAND_RATE, KEY_PLEASE_TEXT_ANGLE, keyPleaseGraph, true);
    PlayKeyPleaseTextFlashing();    // 文字点滅表示
}

/// <summary>
/// 文字の描画
/// </summary>
void ClearSceneUI::PlayKeyPleaseTextFlashing()
{
    // 現在時間取得
    int _time = GetNowCount();

    // 点滅表示
    if (_time - lastFlashingTime >= FLASHING_INTERVAL)
    {
        isKeyPleaseGraphDraw = !isKeyPleaseGraphDraw;
        lastFlashingTime = _time;          // 最後に点滅させた時間を記録
    }
    if (isKeyPleaseGraphDraw)
    {
        // キーを入力してください
        char text[256] = "Press Any Button to Title";
        DrawStringCenterScreen(text, SCREEN_SIZE_Y - (SCREEN_SIZE_Y / 4) - KEY_PLEASE_TEXT_POSITION_OFFSET_Y, UI_COLOR);
    }
}
