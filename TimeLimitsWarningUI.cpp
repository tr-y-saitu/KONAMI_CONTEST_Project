#include "TimeLimitsWarningUI.h"
#include "GameSceneUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
TimeLimitsWarningUI::TimeLimitsWarningUI(char* _graphHandle, VECTOR initPos)
    : isStartPosition   (false)
{
    graphHandle = LoadGraph(_graphHandle);
    position = initPos;
}

/// <summary>
/// デストラクタ
/// </summary>
TimeLimitsWarningUI::~TimeLimitsWarningUI()
{
    DeleteGraph(graphHandle);
}

/// <summary>
/// 更新
/// </summary>
void TimeLimitsWarningUI::Update(int timeLimit, int waveEndTime)
{
    // 制限時間わずかになったら表示を画面内へ
    if (timeLimit <= WARNING_TIME_LIMIT)
    {
        TranslationTargetPosition(timeLimit);
    }
    // ウェーブが切り替わったら表示を画面外へ
    if (timeLimit == waveEndTime)
    {
        isStartPosition = true;
    }
    if (isStartPosition)
    {
        TranslationlStartPosition();
    }
}

/// <summary>
/// 再生
/// </summary>
void TimeLimitsWarningUI::PlayTranslation()
{

}

/// <summary>
/// 描画
/// </summary>
void TimeLimitsWarningUI::Draw()
{
    DrawGraph(position.x, position.y, graphHandle, true);
    SetFontSize(TIME_LIMITS_WARNING_TEXT_SIZE);
    DrawFormatString(position.x + OFF_SET_POSITION_X, position.y + OFF_SET_POSITION_Y, TEXT_COLOR_BLACK, "残り時間わずか！", true);
}

/// <summary>
/// 指定位置まで平行移動させる
/// </summary>
/// <param name="targetXPosition">指定位置のX座標</param>
void TimeLimitsWarningUI::TranslationTargetPosition(int timerLimit)
{
    // 制限時間が残り少なくなったら
    if (timerLimit <= WARNING_TIME_LIMIT)
    {
        if (position.x >= TIME_LIMITS_WARNING_STOP_POSITION)
        {
            position.x -= UI_MOVE_AMOUNT;
        }
    }
}

/// <summary>
/// スタート位置まで平行移動させる
/// </summary>
/// <param name="startXPosition">スタート位置のX座標</param>
/// <returns>移動が終了したか</returns>
void TimeLimitsWarningUI::TranslationlStartPosition()
{
    // スタート座標に戻す
    if (isStartPosition && position.x <= SCREEN_SIZE_X)
    {
        position.x += UI_MOVE_AMOUNT;
        if (position.x >= SCREEN_SIZE_X)
        {
            isStartPosition = false;
        }
    }
}
