#include "Common.h"
#include "TitleSceneUI.h"


/// <summary>
/// コンストラクタ
/// </summary>
TitleSceneUI::TitleSceneUI()
    : lastFlashingTime      (0)
    , isKeyPleaseGraphDraw  (false)
{
    SetFontSize(UI_FONT_SIZE);  // フォントサイズ設定
    titileGraph = LoadGraph("data/texture/Menu/titileLogo1200.png");
    keyPleaseGraph = LoadGraph("data/texture/State/KeyReleseImg800x119.png");
    highScoreFrameGraph = LoadGraph("data/texture/Clear/socreResult700.png");
}

/// <summary>
/// デストラクタ
/// </summary>
TitleSceneUI::~TitleSceneUI()
{
    DeleteGraph(titileGraph);
}

/// <summary>
/// 更新
/// </summary>
void TitleSceneUI::Update()
{
    // 処理なし
}

/// <summary>
/// 描画
/// </summary>
void TitleSceneUI::Draw(int highScore)
{
    // タイトルロゴ
    DrawRotaGraph(TITLE_LOGO_POSITION_X, TITLE_LOGO_POSITION_Y,
        TITLE_LOGO_EXPAND_RATE, TITLE_LOGO_ANGEL, titileGraph, true);

    // スコア
    DrawRotaGraph(SCORE_DRAW_POSITION_X, SCORE_DRAW_POSITION_Y,
        SCORE_FRAME_EXPAND_RATE, SCORE_FRAME_ANGLE, highScoreFrameGraph, true);
    char drawText[256];
    snprintf(drawText, sizeof(drawText), "HIGHSCORE : %d", highScore);
    DrawStringCenterScreen(drawText, SOCRE_FRAME_DRAW_POSITION_Y, UI_COLOR_BLACK);

    // キー入力指示
    DrawKeyPleaseTextFlashing();
}

/// <summary>
/// 文字の点滅描画
/// </summary>
void TitleSceneUI::DrawKeyPleaseTextFlashing()
{
    // 枠表示
    DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y - (SCREEN_SIZE_Y / 5), 1, 0, keyPleaseGraph, true);

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
        char drawString[256] = "Press Any Button to Start";
        int drawPostionY = SCREEN_SIZE_Y - (SCREEN_SIZE_Y / 5) - KEY_PLEASE_TEXT_OFFSET_Y;
        DrawStringCenterScreen(drawString, drawPostionY, UI_COLOR_BLACK);
    }
}
