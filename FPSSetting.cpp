#include "DxLib.h"
#include "FPSSetting.h"


/// <summary>
/// コンストラクタ
/// </summary>
FPSSetting::FPSSetting()
	:	prevTime		(0)
	,	afterTime		(0)
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
/// ゲーム開始前の時間を計測
/// </summary>
void FPSSetting::SettingPreviousFPS()
{
	prevTime = GetNowHiPerformanceCount();
}

/// <summary>
/// 60FPSに合わせる
/// </summary>
void FPSSetting::Setting60FPS()
{
	// １フレーム終了後の時間を計測
	afterTime = GetNowHiPerformanceCount();
	// 60FPSになるように待機する　　60分の一秒　0.01666......
	while (afterTime - prevTime < FPS_60)
	{
		// この時点での時間を計測して次に備える
		afterTime = GetNowHiPerformanceCount();
	}


}

