#include "Calculation.h"


Calculation::Calculation()
{
	// 処理なし
}

Calculation::~Calculation()
{
	// 処理なし
}

/// <summary>
/// 線形補間関数
/// </summary>
/// <param name="num">線形補間したいfloat型変数</param>
/// <returns>線形補間されたfloat型の返り値</returns>
float Calculation::Lerp_F(const float num1, const float num2, float t)
{
	float reNum = num1 + (num2 - num1) * t;
	return reNum;
}


