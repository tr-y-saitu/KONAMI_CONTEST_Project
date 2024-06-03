#include "Confetti.h"


// �R���X�g���N�^
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

// �f�X�g���N�^
Confetti::~Confetti()
{
	// �����Ȃ�
}

// ������
void Confetti::Initialize(int model,VECTOR initVec, int initSpeed,int initType)
{
	// ���W�̏�����
	pos = initVec;
	// ���x
	speed = initSpeed;
	// ���f���n���h���̏�����
	modelHandle = model;
	// �p�x�̏�����
	radian = 0;
	// �F���w��
	colorType = initType;
	// ��]�̃^�C�v���w��
	rotateType = initType;

	// �X�y�A���ォ��[��΂ɕύX
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

// �X�V
void Confetti::Update(int index)
{
	

	// ���f���̉�]
	if (radian < 360)
	{
		radian += 25;
	}
	else
	{
		radian = 0;
	}
	// ��]�̃^�C�v���Ƃɉ�]
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
	

	// �����̐ݒ�
	dir = VGet(0, -1, 0);

	// ���K��
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}


	// ���K����A�X�s�[�h���|����
	auto velocity = VScale(dir, speed);

	// �|�W�V�����ړ�
	pos = VAdd(pos, velocity);

	// ������ʒ[�ɍs������߂�
	/*if (pos.y <= -200)
	{
		pos.y = 500;
	}*/

	// ���f���̍��W��ݒ�
	MV1SetPosition(modelHandle, pos);
}

// �`��
void Confetti::Draw()
{
	// ���f���̕`��
	MV1DrawModel(modelHandle);
}












