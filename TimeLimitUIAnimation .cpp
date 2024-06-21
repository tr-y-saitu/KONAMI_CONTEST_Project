#include "TimeLimitUIAnimation .h"
#include "GameSceneUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
TimeLimitUIAnimation ::TimeLimitUIAnimation (char* _graphHandle, VECTOR initPos)
    : isStartPosition   (false)
{
    graphHandle = LoadGraph(_graphHandle);
    position = initPos;
}

/// <summary>
/// デストラクタ
/// </summary>
TimeLimitUIAnimation ::~TimeLimitUIAnimation ()
{
    DeleteGraph(graphHandle);
}

/// <summary>
/// 更新
/// </summary>
void TimeLimitUIAnimation::Update(int timeLimit, int waveEndTime)
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
void TimeLimitUIAnimation::PlayTranslation()
{

}

/// <summary>
/// 描画
/// </summary>
void TimeLimitUIAnimation::Draw()
{
    DrawGraph(position.x, position.y, graphHandle, true);
    SetFontSize(30);
    DrawFormatString(position.x + 120, position.y + 30, GetColor(0,0,0), "残り時間わずか！", true);
}

/// <summary>
/// 指定位置まで平行移動させる
/// </summary>
/// <param name="targetXPosition">指定位置のX座標</param>
void TimeLimitUIAnimation::TranslationTargetPosition(int timerLimit)
{
    // 制限時間が残り少なくなったら
    if (timerLimit <= WARNING_TIME_LIMIT)
    {
        if (position.x >= 1200)
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
void TimeLimitUIAnimation::TranslationlStartPosition()
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
