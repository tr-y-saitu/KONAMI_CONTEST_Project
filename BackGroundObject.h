#pragma once

#include "DxLib.h"

class BGObj
{
public:
	static const int INIT_SCALE = 0.5f;

	// �����o���\�b�h
	BGObj();			// �R���X�g���N�^
	~BGObj();			// �f�X�g���N�^
	void Initialize(int graph,int texture,VECTOR initVec,int speed);	// ������
	void Update();		// �X�V
	void Draw();		// �`��
	
	// ���f���n���h���̎擾
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
	void SetPos(const VECTOR set) { pos = set; }
	void SetReturnPosX(const int set) { returnPosX = set; }
	void SetScrollSpeed(const int set) { scrollSpeed = set; }
	void SetScale(const VECTOR set) { scale = set; }

private:
	// �萔
	const float SPEED = 5.0f;

	int		modelHandle;	// ���f���n���h��
	int		texrureHandle;	// �e�N�X�`���n���h��
	VECTOR	pos;			// �|�W�V����
	VECTOR	pos2;			
	VECTOR	dir;			// ����
	MATRIX	matrix;			// �s��i��]�Ŏg�p�j
	int		w;				// ��
	int		h;				// ����
	VECTOR	scale;			// �X�P�[���T�C�Y

	int		returnPosX;		// �ʒu��߂��^�C�~���O
	int		scrollSpeed;	// ��ʃX�N���[�����鑬�x

	int		graphHandle;	// �w�i�摜�n���h��
	int		graphUniverse;	// �F���摜�n���h��

};







