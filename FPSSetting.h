#pragma once

/// <summary>
/// FPS管理
/// </summary>
class FPSSetting
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	FPSSetting();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~FPSSetting();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 待機処理
    /// </summary>
    void SleepForFPS();

private:
    // 定数
    static constexpr int SET_FPS = 30;  // 設定したFPS値

    // 変数
    int     nowFpsCount;                // 現在のフレーム数
    int     fpsCountStartTime;          // フレームカウントを始めた時間
    float   deltaTime;                  // １フレームにかかった時間


};

