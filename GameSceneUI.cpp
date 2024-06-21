#include "Common.h"
#include "SceneUIBase.h"
#include "GameSceneUI.h"
#include "GemManager.h"
#include "WaveConstants.h"
#include "TimeLimitUIAnimation .h"

/// <summary>
/// コンストラクタ
/// </summary>
GameSceneUI::GameSceneUI()
    : isHitGemToChest       (false)
    , getDirectionCount     (0)
{
    timeLimitsWarningUI = new TimeLimitUIAnimation ("data/texture/time/LimitApproachingGraph400_100.png",VGet(1600,825,0));
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

    // タイマーバーの描画
    DrawTimerBar(nowTimer,waveEndTime);
    DrawTimeWarning(nowTimer, waveEndTime);

    // 「GET!」モデルのポジションを設定
    MV1SetPosition(getDirectionModelHandle, VGet(1, 3, -3));

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
    DrawFormatString(100, 750, UI_COLOR, "%s", waveText);

    // スコアの描画
    DrawScore(VGet(1200, 750, 0), FONT_SIZE_SCORE, gameScore);
}


/// <summary>
/// スコアの描画
/// </summary>
/// <param name="pos">スコアを描画する座標</param>
/// <param name="fontSize">フォントサイズ</param>
/// <param name="score">スコア</param>
void GameSceneUI::DrawScore(VECTOR pos, int fontSize, int score)
{
    SetFontSize(fontSize);
    DrawFormatString(pos.x, pos.y, UI_COLOR, "SCORE : %d", score);
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
    SetFontSize(FONT_SIZE_NOW_TIME);
    sprintf_s(_timeCount, "あと%d秒", waveEndTime - nowTimer);
    DrawString(450, 850, _timeCount, UI_COLOR_BLACK, true);

}

/// <summary>
/// 残り時間が少ないことを知らせる描画をする
/// </summary>
/// <param name="nowTimer">現在時間</param>
/// <param name="waveEndTime">現在のウェーブが終了する時間</param>
void GameSceneUI::DrawTimeWarning(int nowTimer, int waveEndTime)
{
    // 説明変数
    int _timeLimit = waveEndTime - nowTimer;                        // 制限時間
    VECTOR _uiPos = timeLimitsWarningUI->GetPosition();             // 座標
    int _uiGraph = timeLimitsWarningUI->GetGraphHandle();           // イメージハンドル
    bool _uiResetPos = timeLimitsWarningUI->GetIsStartPosition();   // 座標をリセットするか

    // 制限時間が残り少なくなったら移動
    timeLimitsWarningUI->TranslationTargetPosition(TIME_LIMITS_WARNING_STOP_POSITION, _timeLimit);

    // 次のウェーブに移行したら画面外に出す
    timeLimitsWarningUI->TranslationlStartPosition(SCREEN_SIZE_X, _timeLimit, waveEndTime);

    // 描画
    DrawGraph(_uiPos.x, _uiPos.y, _uiGraph, true);
    SetFontSize(FONT_SIZE_WARNING_UI);
    DrawFormatString(_uiPos.x + 120, _uiPos.y + 30, UI_COLOR_BLACK, "残り時間わずか！", true);
}
