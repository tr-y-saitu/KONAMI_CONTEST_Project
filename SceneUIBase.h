#pragma once

/// <summary>
/// シーンUIベース
/// </summary>
class SceneUIBase
{
public:
    /// <summary>
    /// フェードの状態
    /// </summary>
    enum FadeState
    {
        FADE_NONE,      // フェード中ではない
        FADE_PLAYING,   // フェード中
        FADE_END        // フェード終了
    };

    /// <summary>
    /// コンストラクタ
    /// </summary>
    SceneUIBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~SceneUIBase();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    /// <summary>
    /// フェードインUIのみ（UIの明るさを徐々にあげる）
    /// </summary>
    void StartFadeInUI();

    /// <summary>
    /// フェードアウトUIのみ（UIの明るさを徐々に下げる）
    /// </summary>
    void StartFadeOutUI();

    /// <summary>
    /// フェードイン画面のみ（画面の明るさを徐々に上げる）
    /// </summary>
    void StartFadeInScreen();

    /// <summary>
    /// フェードアウト画面のみ（画面の明るさを徐々に下げる）
    /// </summary>
    void StartFadeOutScreen();

    // Getter/Setter
    const FadeState GetFadeState()const { return fadeState; }

    void SetFadeState(const int set) { fadeState = (FadeState)set; }


private:
    static constexpr int TRANSPARENCY_LIMIT = 255;          // 透過度の最大上限
    static constexpr int GET_DIRECTION_DRAW_TIME = 100;     // 獲得演出を描画する時間
    static constexpr int ADD_TRANSPARENCY = 2;              // 画像の濃さを加算する値
    static constexpr int ADD_BLACK_OUT_ADD_TRANSPARENCY = 3;// 暗転する際の画像の濃さを加算する値

    int blackOutGraph;      // 画面の明るさを調整する画像
    int screenBrightness;   // 画面の明るさの値
    bool isBlackOut;        // 画面をブラックアウトするかどうか
    FadeState fadeState;    // フェードの状態を表す
};

