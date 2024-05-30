#pragma once


class FPSSetting
{
public:
	FPSSetting();
	~FPSSetting();
	void SettingPreviousFPS();
	void Setting60FPS();

private:
	const int FPS_60 = 16667;

	LONGLONG	prevTime;		// ループが始まる前の時間
	LONGLONG	afterTime;		// ゲーム処理が終わった時間
};

