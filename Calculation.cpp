#include "Calculation.h"


Calculation::Calculation()
{
	// �����Ȃ�
}

Calculation::~Calculation()
{
	// �����Ȃ�
}

/// <summary>
/// ���`��Ԋ֐�
/// </summary>
/// <param name="num">���`��Ԃ�����float�^�ϐ�</param>
/// <returns>���`��Ԃ��ꂽfloat�^�̕Ԃ�l</returns>
float Calculation::Lerp_F(const float num1, const float num2, float t)
{
	float reNum = num1 + (num2 - num1) * t;
	return reNum;
}


