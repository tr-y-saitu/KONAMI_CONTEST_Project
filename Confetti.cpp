#include "Confetti.h"


// コンストラクタ
Confetti::Confetti()
	:	w			(0)
	,	h			(0)
	,	retrunPosY	(0)
	,	speed		(0)
	,	radian		(0)
	,	colorType	(0)
	,	rotateType	(0)
{
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
}

// デストラクタ
Confetti::~Confetti()
{
	// 処理なし
}

// 初期化
void Confetti::Initialize(int model,VECTOR initVec, int initSpeed,int initType)
{
	// 座標の初期化
	pos = initVec;
	// 速度
	speed = initSpeed;
	// モデルハンドルの初期化
	modelHandle = model;
	// 角度の初期化
	radian = 0;
	// 色を指定
	colorType = initType;
	// 回転のタイプを指定
	rotateType = initType;

	// スペアきゅからーを緑に変更
	if (colorType == 0)
	{
		MV1SetMaterialSpcColor(modelHandle, 0, GetColorF(1.0f, 1.0f, 0.0f, 1.0f));
	}
	if (colorType == 1)
	{
		MV1SetMaterialSpcColor(modelHandle, 0, GetColorF(1.0f, 0.0f, 1.0f, 1.0f));
	}
	if (colorType == 2)
	{
		MV1SetMaterialSpcColor(modelHandle, 0, GetColorF(0.0f, 1.0f, 1.0f, 1.0f));
	}
}

// 更新
void Confetti::Update(int index)
{
	

	// モデルの回転
	if (radian < 360)
	{
		radian += 25;
	}
	else
	{
		radian = 0;
	}
	// 回転のタイプごとに回転
	if (rotateType == 0)
	{
		MV1SetRotationXYZ(modelHandle, VGet(radian * index * DX_PI_F / 180.0f, radian * DX_PI_F / 180.0f, 0.0f));
	}
	if (rotateType == 1)
	{
		MV1SetRotationXYZ(modelHandle, VGet( (radian * index + 20) * DX_PI_F / 180.0f, 0.0f, radian * DX_PI_F / 180.0f));
	}
	if (rotateType == 2)
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, (radian * index + 15) * DX_PI_F / 180.0f, (radian + 50) * DX_PI_F / 180.0f));
	}
	

	// 方向の設定
	dir = VGet(0, -1, 0);

	// 正規化
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}


	// 正規化後、スピードを掛ける
	auto velocity = VScale(dir, speed);

	// ポジション移動
	pos = VAdd(pos, velocity);

	// もし画面端に行ったら戻す
	/*if (pos.y <= -200)
	{
		pos.y = 500;
	}*/

	// モデルの座標を設定
	MV1SetPosition(modelHandle, pos);
}

// 描画
void Confetti::Draw()
{
	// モデルの描画
	MV1DrawModel(modelHandle);
}












