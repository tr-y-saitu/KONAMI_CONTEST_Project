#pragma once

#include "DxLib.h"


class SkyDome
{
public:
	SkyDome();
	~SkyDome();

	void Initialize();	// ������
	void Update();		// �X�V
	void Draw();		// �`��

	// ���f���n���h���̎擾
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
	void SetPos(const VECTOR set) { pos = set; }



private:
	// �萔
	const float SPEED = 5.0f;

	int		modelHandle;	// ���f���n���h��
	int		textureHandle;	// �e�N�X�`���n���h��
	VECTOR	pos;			// �|�W�V����
	VECTOR	pos2;			// ��]����O�̃|�W�V����
	VECTOR	dir;			// ����
	int		w;				// ��
	int		h;				// ����

};


