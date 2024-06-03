#pragma once

#include "DxLib.h"



class Enemy
{
public:
	Enemy();		// �R���X�g���N�^
	~Enemy();		// �f�X�g���N�^

	void Initialize();		// ����������
	void Update(int timer);	// �X�V
	void Draw();	// �`��

	// ���f���n���h���̎擾
	int GetModelHandle() { return modelHandle; }

	// �Q�b�g
	const VECTOR& GetPos()const { return pos; }
	const bool GetVisibleFlag() { return visibleFlag; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
	const int GetRudius() { return r; }
	// �Z�b�g
	const float GetSpeedBuf() { return speedBuf; }
	void SetPos(const VECTOR set) { pos = set; }

private:
	// �萔
	const float SPEED = 5.0f;	// �ړ��X�s�[�h

	// �ϐ�
	int		modelHandle;	// ���f���n���h��
	VECTOR	scale;			// �X�P�[��
	int		graphHandle;	// 2D���f���n���h��
	int		w;				// ��
	int		h;				// ����
	VECTOR	pos;			// �|�W�V����
	VECTOR	dir;			// ����
	bool	visibleFlag;	// ���݂��Ă��邩
	float	speedBuf;		// �ړ��X�s�[�h�̃o�t�l
	double	sizeBuf;		// �摜�T�C�Y�̃o�t
	double	graphSize;		// �摜�T�C�Y
	int		r;				// ���^�����蔻��̔��a

};

