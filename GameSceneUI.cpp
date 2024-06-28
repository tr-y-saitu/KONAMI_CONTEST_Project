#include "Common.h"
#include "SceneUIBase.h"
#include "GameSceneUI.h"
#include "GemManager.h"
#include "WaveConstants.h"
#include "TimeLimitsWarningUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameSceneUI::GameSceneUI()
    : isHitGemToChest       (false)
    , getDirectionCount     (0)
{
    SetFontSize(FONT_SIZE_SCORE);
    scoreFrameGrpah = LoadGraph("data/texture/UI/scoreFrameImg.png");
    timeLimitsWarningUI = new TimeLimitsWarningUI("data/texture/time/LimitApproachingGraph400_100.png",VGet(1600,825,0));
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
    delete(timeLimitsWarningUI);
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
/// 更新
/// </summary>
void GameSceneUI::Update(int nowTimer, int waveEndTime)
{
    int _timeLimit = waveEndTime - nowTimer;
    timeLimitsWarningUI->Update(_timeLimit, waveEndTime);
}

/// <summary>
/// 描画
/// </summary>
/// <param name="gameScore">ゲームスコア</param>
/// <param name="nowTimer">現在の経過時間</param>
/// <param name="gemWaveState">現在の宝石のウェーブステート</param>
/// <param name="isBlackOut">暗転処理するかどうか</param>
/// <param name="waveEndTime">現在のウェーブの終了時間</param>
void GameSceneUI::Draw(int gameScore, float nowTimer,
    int gemWaveState, bool isBlackOut,int waveEndTime,
    char* waveText)
{
    char _timeCount[256];		// ゲームの経過時間

    // 「GET!」モデルのポジションを設定
    MV1SetPosition(getDirectionModelHandle, VGet(1, 3, -3));

    // スコアの描画
    DrawScore(gameScore);
}

/// <summary>
/// スコアの描画
/// </summary>
/// <param name="score">スコア</param>
void GameSceneUI::DrawScore(int score)
{
    DrawGraph(SCORE_POSITION_X - 100, SCORE_POSITION_Y - 25, scoreFrameGrpah, true);
    DrawFormatString(SCORE_POSITION_X, SCORE_POSITION_Y, UI_COLOR, "%d", score);
}

/// <summary>
/// タイマーバーの描画
/// </summary>
/// <param name="nowTimer">現在時間</param>
/// <param name="waveEndTime">現在のウェーブが終了する時間</param>
void GameSceneUI::DrawTimerBar(int nowTimer, int waveEndTime)
{
    // フレーム
    DrawExtendGraph(TIMER_FRAME_TOP_LEFT_X, TIMER_FRAME_TOP_LEFT_Y,
        TIMER_FRAME_BOTTOM_RIGHT_X, TIMER_FRAME_BOTTOM_RIGHT_Y, timerBarFrameGraph, true);

    // 時間バー
    // _leftBufでバー左を縮め、_rightBufでバー右をずらす
    // _rightBufがないと少しづつ右に移動する
    int _leftBuf = ((int)(TIMER_BAR_BOTTOM_RIGHT_X) * ((float)nowTimer / waveEndTime));
    int _rightBuf = ((int)(TIMER_BAR_TOP_LEFT_X) * ((float)nowTimer / waveEndTime));

    DrawExtendGraph(TIMER_BAR_TOP_LEFT_X,
        TIMER_BAR_TOP_LEFT_Y,
        (TIMER_BAR_BOTTOM_RIGHT_X - _leftBuf + _rightBuf),
        TIMER_BAR_BOTTOM_RIGHT_Y, timerBarGraph, true);

    // 現在の経過時間を描画
    char _timeCount[256];		// ゲームの経過時間
    sprintf_s(_timeCount, "あと%d秒", waveEndTime - nowTimer);
    DrawString(450, 850, _timeCount, UI_COLOR_BLACK, true);

}

