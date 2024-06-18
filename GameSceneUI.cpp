#include "GameSceneUI.h"
#include "GemManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameSceneUI::GameSceneUI()
    : isHitGemToChest       (false)
    , getDirectionCount     (0)
{
    getDirectionModelHandle = MV1LoadModel("data/model/UI/GET!.mv1");
    timerBarFrameGraph = LoadGraph("data/texture/time/TimerBarFrame.png");
    timerBarGraph = LoadGraph("data/texture/time/TimerBar_2.png");
    MV1SetScale(getDirectionModelHandle, VGet(0.05f, 0.05f, 0.0f));
    MV1SetRotationXYZ(getDirectionModelHandle, VGet(0, 25.0f * DX_PI_F / 180.0f, 0));
}

/// <summary>
/// デストラクタ
/// </summary>
GameSceneUI::~GameSceneUI()
{
    MV1DeleteModel(getDirectionModelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void GameSceneUI::Initialize()
{
    isHitGemToChest = false;
    getDirectionCount = 0;
}

/// <summary>
/// 描画
/// </summary>
/// <param name="gameScore">ゲームスコア</param>
/// <param name="nowTimer">現在の経過時間</param>
/// <param name="gemWaveState">現在の宝石のウェーブステート</param>
/// <param name="isBlackOut">暗転処理するかどうか</param>
void GameSceneUI::Draw(int gameScore, float nowTimer,
    int gemWaveState, bool isBlackOut)
{
    char _timeCount[256];		// ゲームの経過時間

    // 現在の経過時間を描画
    sprintf_s(_timeCount, "～～～%f秒経過～～～", nowTimer);
    DrawString(250, 400, _timeCount, UI_COLOR, true);

    // タイマーバーの描画
    DrawTimerBar(nowTimer);

    // 「GET!」モデルのポジションを設定
    MV1SetPosition(getDirectionModelHandle, VGet(1, 3, 1));

    // 宝石獲得演出(宝石が当たっているかつ演出時間ないである)
    if (isHitGemToChest && getDirectionCount <= GET_DIRECTION_DRAW_TIME)
    {
        // 演出時間を経過
        getDirectionCount++;

        // 演出用モデルの描画
        MV1DrawModel(getDirectionModelHandle);
    }
    // 描画指定時間を越えたらゼロに戻す
    if (getDirectionCount >= GET_DIRECTION_DRAW_TIME)
    {
        getDirectionCount = 0;
        isHitGemToChest = false;
    }

    // 現在のWAVEステートの描画
    switch (gemWaveState)
    {
    case GemManager::WAVE_FIRST:
        DrawFormatString(100, 100, UI_COLOR, "WAVE_FIRST");
        break;

    case GemManager::WAVE_SECOND:
        DrawFormatString(100, 100, UI_COLOR, "WAVE_SECOND");
        break;

    case GemManager::WAVE_THIRD:
        DrawFormatString(100, 100, UI_COLOR, "WAVE_THIRD");
        break;

    default:
        break;
    }

    // スコアの描画
    DrawScore(VGet(0, 0, 0), 20, gameScore);
}


/// <summary>
/// スコアの描画
/// </summary>
/// <param name="pos">スコアを描画する座標</param>
/// <param name="fontSize">フォントサイズ</param>
/// <param name="score">スコア</param>
void GameSceneUI::DrawScore(VECTOR pos, int fontSize, int score)
{
    // フォントサイズの変更
    SetFontSize(fontSize);

    // スコアの描画
    DrawFormatString(pos.x, pos.y, UI_COLOR, "SCORE : %d", score);
}

/// <summary>
/// タイマーバーの描画
/// </summary>
/// <param name="nowTimer">現在時間</param>
void GameSceneUI::DrawTimerBar(int nowTimer)
{
    // フレーム
    DrawExtendGraph(TIMER_FRAME_TOP_LEFT_X, TIMER_FRAME_TOP_LEFT_Y,
        TIMER_FRAME_BOTTOM_RIGHT_X, TIMER_FRAME_BOTTOM_RIGHT_Y, timerBarFrameGraph, true);

    // 時間バー
    int _leftBuf = ((int)(TIMER_BAR_BOTTOM_RIGHT_X) * ((float)nowTimer / 20));
    int _rightBuf = ((int)(TIMER_BAR_TOP_LEFT_X) * ((float)nowTimer / 20));

    DrawExtendGraph(TIMER_BAR_TOP_LEFT_X,
        TIMER_BAR_TOP_LEFT_Y,
        (TIMER_BAR_BOTTOM_RIGHT_X - _leftBuf + _rightBuf),
        TIMER_BAR_BOTTOM_RIGHT_Y, timerBarGraph, true);

}
