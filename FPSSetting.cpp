#include "DxLib.h"
#include "FPSSetting.h"


/// <summary>
/// コンストラクタ
/// </summary>
FPSSetting::FPSSetting()
    : fpsCountStartTime (0)
    , nowFpsCount       (0)
    , deltaTime         (0)
{

}

/// <summary>
/// デストラクタ
/// </summary>
FPSSetting::~FPSSetting()
{
	// 処理なし
}

/// <summary>
/// 更新
/// </summary>
void FPSSetting::Update()
{
    // 1フレーム目なら時刻を記憶
    if (nowFpsCount == 0)
    {
        fpsCountStartTime = GetNowCount();	//基準となる時間を決める
    }
    // 60フレーム目なら平均を計算する
    if (nowFpsCount == (float)SET_FPS)
    {
        int nowTime = GetNowCount();		//今の時間を設定
        deltaTime = 1000.f / ((nowTime - fpsCountStartTime) / (float)SET_FPS);	//１フレームにかかった時間を計算
        nowFpsCount = 0;					//フレームのカウントを初期化
    }
    else
    {
        nowFpsCount++;
    }
}

/// <summary>
/// 待機処理
/// </summary>
void FPSSetting::SleepForFPS()
{
    //かかった時間
    int _tookTime = GetNowCount() - fpsCountStartTime;
    //待つべき時間
    int _waitTime = nowFpsCount * 1000 / SET_FPS - _tookTime;

    //待つべき時間待機する
    if (_waitTime > 0)
    {
        Sleep(_waitTime);
    }
}
