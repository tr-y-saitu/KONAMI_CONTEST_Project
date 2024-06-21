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
/// 指定位置まで平行移動させる
/// </summary>
/// <param name="targetXPosition">指定位置のX座標</param>
void TimeLimitUIAnimation::TranslationTargetPosition(int targetXPosition, int timerLimit)
{
    // 制限時間が残り少なくなったら
    if (timerLimit <= WARNING_TIME_LIMIT)
    {
        if (position.x >= targetXPosition)
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
void TimeLimitUIAnimation::TranslationlStartPosition(int startXPosition,int timerLimit,int waveEndTime)
{
    // 次のWAVEに移行したら
    if (timerLimit == waveEndTime)
    {
        isStartPosition = true;
    }
    // スタート座標に戻す
    if (isStartPosition && position.x <= startXPosition)
    {
        position.x += UI_MOVE_AMOUNT;
        if (position.x >= startXPosition)
        {
            isStartPosition = false;
        }
    }
}
