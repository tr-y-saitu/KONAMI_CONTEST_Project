// �G�l�~�[�N���X

#include "Enemy.h"

Enemy::Enemy()
	:	speedBuf		(0)
	,	modelHandle		(0)
	,	visibleFlag		(false)
	,	sizeBuf			(0.0)
	,	w				(0)
	,	h				(0)
	,	graphSize		(1)
	,	r				(2)
{
	// ���f���n���h���̐ݒ�
	modelHandle = MV1LoadModel("data/model/enemy/KillerModel1.mv1");
	// �|�W�V�����̐ݒ�
	pos = VGet(0, 0, 0);
	// �����̐ݒ�
	dir = VGet(0, 0, 0);
	// �T�C�Y�̒���
	scale = VGet(0.05f, 0.05f, 0.05f);
	MV1SetScale(modelHandle, scale);


}

// �f�X�g���N�^
Enemy::~Enemy()
{
	// ���f���̃A�����[�h

}

/// <summary>
/// ������
/// </summary>
void Enemy::Initialize()
{
	// �|�W�V�����̐ݒ�
	pos = VGet(0, 0, 0);

	// �����̐ݒ�
	dir = VGet(0, 0, 0);
	
	// �T�C�Y�𓾂�
	GetGraphSize(graphHandle, &w, &h);

	
	visibleFlag = true;
	speedBuf = 0;
	graphSize = 1;
	sizeBuf = 0;
}


// �G�l�~�[�̍X�V
void Enemy::Update(int timer)
{
	// ���W��ݒ�
	//pos = VGet(20, 10, 20);

	// �E���獶�Ɉړ�
	dir = VGet(0, 0, 0);

	// ���K��
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}

	auto velocity = VScale(dir, SPEED );

	// ���ړ�
	pos = VAdd(pos, velocity);

	// 3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);

}


// �G�l�~�[�̕`��
void Enemy::Draw()
{
	// �G�l�~�[�̕`��
	MV1DrawModel(modelHandle);

	// �G�l�~�[�̓����蔻���`��
	DrawSphere3D(pos, r, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);
}






