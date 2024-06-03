#include "DxLib.h"
#include "FPSSetting.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
FPSSetting::FPSSetting()
	:	prevTime		(0)
	,	afterTime		(0)
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
FPSSetting::~FPSSetting()
{
	// �����Ȃ�
}

/// <summary>
/// �Q�[���J�n�O�̎��Ԃ��v��
/// </summary>
void FPSSetting::SettingPreviousFPS()
{
	prevTime = GetNowHiPerformanceCount();
}

/// <summary>
/// 60FPS�ɍ��킹��
/// </summary>
void FPSSetting::Setting60FPS()
{
	// �P�t���[���I����̎��Ԃ��v��
	afterTime = GetNowHiPerformanceCount();
	// 60FPS�ɂȂ�悤�ɑҋ@����@�@60���̈�b�@0.01666......
	while (afterTime - prevTime < FPS_60)
	{
		// ���̎��_�ł̎��Ԃ��v�����Ď��ɔ�����
		afterTime = GetNowHiPerformanceCount();
	}


}

