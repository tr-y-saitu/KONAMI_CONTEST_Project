#pragma once
#include "DxLib.h"
#include "Common.h"

/// <summary>
/// タイムリミットを知らせるアニメーション付きUI
/// </summary>
class TimeLimitsWarningUI 
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="_graphHandle">画像ファイルパス</param>
    /// <param name="initPos">初期化座標</param>
    TimeLimitsWarningUI (char* _graphHandle,VECTOR initPos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TimeLimitsWarningUI ();

    /// <summary>
    /// 指定位置まで平行移動させる
    /// </summary>
    /// <param name="targetXPosition">指定位置のX座標</param>
    void TranslationTargetPosition(int timerLimit);

    /// <summary>
    /// スタート位置まで平行移動させる
    /// </summary>
    /// <param name="startXPosition">スタート位置のX座標</param>
    void TranslationlStartPosition();

    /// <summary>
    /// 更新
    /// </summary>
    void Update(int timeLimit,int waveEndTime);

    /// <summary>
    /// 再生
    /// </summary>
    void PlayTranslation();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    // Getter/Setter
    const VECTOR GetPosition()const { return position; }
    const int GetGraphHandle()const { return graphHandle; }
    const bool GetIsStartPosition()const { return isStartPosition; }

private:
    const int TEXT_COLOR_BLACK = GetColor(0, 0, 0);                 // 黒色文字
    static constexpr int TIME_LIMITS_WARNING_TEXT_SIZE = 30;        // 残り制限時間を警告するテキストの文字サイズ
    static constexpr int OFF_SET_POSITION_X = 120;      // 残り制限時間を警告するテキストのX軸のずらし量
    static constexpr int OFF_SET_POSITION_Y = 30;       // 残り制限時間を警告するテキストのY軸のずらし量
    static constexpr int TIME_LIMITS_WARNING_STOP_POSITION = 1200;  // 残り制限時間を警告する画像の停止位置
    static constexpr int WARNING_TIME_LIMIT = 8;                    // 残り制限時間を警告するための時間
    static const int UI_MOVE_AMOUNT = 5;                            // UIの移動量

    VECTOR  position;       // 描画座標
    int     graphHandle;    // 画像ハンドル
    bool    isStartPosition;// 初期位置に戻るかどうか
};

