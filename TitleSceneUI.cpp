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
    keyPleaseGraph = LoadGraph("data/texture/State/KeyRelese.png");
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
    DrawFormatString(450, 500, UI_COLOR_BLACK, "HIGHSCORE : %d", highScore);

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
        DrawFormatString(485, SCREEN_SIZE_Y - (SCREEN_SIZE_Y / 5) - KEY_PLEASE_TEXT_OFFSET_X, UI_COLOR_BLACK, "Press Any Button to Start");
    }
}
