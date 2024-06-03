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

	LONGLONG	prevTime;		// ���[�v���n�܂�O�̎���
	LONGLONG	afterTime;		// �Q�[���������I���������
};

