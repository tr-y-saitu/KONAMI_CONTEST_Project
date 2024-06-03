#pragma once

#include "DxLib.h"

/// <summary>
/// ��
/// </summary>
class Floor
{
public:
	Floor();
	~Floor();

	// ���\�b�h
	void Initialize(VECTOR initPos);		// ������
	void Update();			// �X�V.
	void Draw();			// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() const { return w; }
	const int GetHeight() const { return h; }
	void SetPos(const VECTOR set) { pos = set; }


private:
	int		modelHandle;	// ���f���n���h��
	VECTOR	pos;			// �|�W�V����.
	VECTOR	dir;			// ����
	int		w;				// ��
	int		h;				// ����
	VECTOR	scale;			// �X�P�[��
	float	speed;			// �ړ��X�s�[�h
	int		r;				// ���^�����蔻��̔��a
};

