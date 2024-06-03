#pragma once

#include "DxLib.h"


class Confetti
{
public:
	// ���\�b�h
	Confetti();		// �R���X�g���N�^
	~Confetti();	// �f�X�g���N�^
	void Initialize(int model,VECTOR initVec, int initSpeed,int initType);	// ������
	void Update(int index);		// �X�V
	void Draw();		// �`��
	// �Q�b�g�Z�b�g
	void SetPos(const VECTOR set) { pos = set; }
	const VECTOR& GetPos()const { return pos; }

private:
	int		modelHandle;	// ���f���n���h��
	VECTOR	pos;			// �|�W�V����
	VECTOR	dir;			// ����
	int		w;				// ��
	int		h;				// ����
	int		retrunPosY;		// �ړ����ď����ʒu�ɖ߂����W
	int		speed;			// �X�s�[�h
	int		radian;			// ���W�A���p�x
	int		colorType;		// �J���[�^�C�v
	int		rotateType;		// ��]�^�C�v
};