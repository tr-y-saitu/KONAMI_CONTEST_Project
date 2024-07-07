#pragma once
#include "Common.h"

class TutorialStateInformation;
enum TutorialState;

/// <summary>
/// チュートリアル
/// </summary>
class Tutorial
{
public:
    /// <summary>
    /// チュートリアルの状態
    /// </summary>
    enum TutorialState
    {
        START_TUTORIAL,     // チュートリアル開始
        FIRE_TUTORIAL,      // 火災を教える
        MOVE_TUTORIAL,      // 移動方法を教える
        CUSHION_TUTORIAL,   // クッションで跳ね返すことを教える
        CHEST_TUTORIAL,     // 宝箱に入れることを教える
        GEM_BOUND_TUTORIAL, // 複数当てないといけない宝石について教える
        END_TUTORIAL,       // チュートリアル終了
    };

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Tutorial();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Tutorial();

    /// <summary>
    /// チュートリアルの更新
    /// </summary>
    /// <param name="waveState">現在のウェーブステート</param>
    void Update(int gemWaveState);

private:
    // 定数
    static constexpr int TUTORIAL_UPDATE_INTERVAL = 5000;       // チュートリアルが進行する時間(ミリ秒)
    const int UI_COLOR_BLACK = GetColor(0, 0, 0);               // UIの文字の色(黒)
    static constexpr int FRAME_POSITION_X = 0;                  // フレームを描画するX座標
    static constexpr int FRAME_POSITION_Y = 0;                  // フレームを描画すいY座標
    static constexpr double TUTORIAL_IMAGE_EXPAND_RATE = 0.5;   // チュートリアル画像の拡大率
    static constexpr double TUTORIAL_IMAGE_ANGLE = 0;           // チュートリアル画像の回転率

    // 変数
    // 各チュートリアルステートの情報
    map<int, TutorialStateInformation*> tutorialInfomation;
    int     tutorialState;                  // チュートリアルの進行状態
    int     tutorialLastUpdateTime;         // チュートリアル管理用タイマー
    int     tutorialFrameGraph;             // チュートリアル実行時の画面フレーム
    int     drawImageHandle;                // 実際に描画する画像ハンドル

    // 画像ハンドル
    int fireImageHandle;        // 火災をお知らせ
    int moveImageHandle;        // 移動方法をお知らせ
    int cushionImageHandle;     // クッションで飛ばすことをお知らせ
    int chestImageHandle;       // 宝箱に入れることをお知らせ
    int gemBoundImageHandle;    // 複数回バウンドさせる宝石をお知らせ
    int endImageHandle;         // 後は頑張ってねのお知らせ
    int arrowImageHandle;       // 矢印
};


