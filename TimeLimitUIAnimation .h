#pragma once
#include "DxLib.h"
#include "Common.h"

/// <summary>
/// タイムリミットを知らせるアニメーション付きUI
/// </summary>
class TimeLimitUIAnimation 
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="_graphHandle">画像ファイルパス</param>
    /// <param name="initPos">初期化座標</param>
    TimeLimitUIAnimation (char* _graphHandle,VECTOR initPos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TimeLimitUIAnimation ();

    /// <summary>
    /// 指定位置まで平行移動させる
    /// </summary>
    /// <param name="targetXPosition">指定位置のX座標</param>
    void TranslationTargetPosition(int targetXPosition,int timerLimit);

    /// <summary>
    /// スタート位置まで平行移動させる
    /// </summary>
    /// <param name="startXPosition">スタート位置のX座標</param>
    void TranslationlStartPosition(int startXPosition, int timerLimit, int waveEndTime);

    // Getter/Setter
    const VECTOR GetPosition()const { return position; }
    const int GetGraphHandle()const { return graphHandle; }
    const bool GetIsStartPosition()const { return isStartPosition; }

private:
    static constexpr int WARNING_TIME_LIMIT = 8;    // 残り制限時間を警告するための時間
    static const int UI_MOVE_AMOUNT = 5;            // UIの移動量

    VECTOR  position;       // 描画座標
    int     graphHandle;    // 画像ハンドル
    bool    isStartPosition;// 初期位置に戻るかどうか
};

