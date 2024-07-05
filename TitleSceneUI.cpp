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
    highScoreFrameGraph = LoadGraph("data/texture/Menu/highscoreFrame.png");
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
    DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 4, 1, 0, titileGraph, true);

    // スコア
    DrawRotaGraph(SCREEN_SIZE_X / 2, 525, 1, 0, highScoreFrameGraph, true);
    char drawText[256];
    snprintf(drawText, sizeof(drawText), "HIGHSCORE : %d", highScore);
    DrawStringCenterScreen(drawText, 500, UI_COLOR_BLACK);

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
