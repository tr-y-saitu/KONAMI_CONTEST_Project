#pragma once
#include "DxLib.h"

/// <summary>
/// 3D���W��ԂɃX�v���C�g��\������d�g�݁i�s�{�b�g�͒��S�Œ�A�摜��graph�͊O�ŊǗ��j
/// </summary>
class WorldSprite
{
public:
	void Initialize(int textureGraph, int chipPixelSize, int spriteNo);
	void SetTransform(const VECTOR& pos, float spriteSize);
	void Draw();

	const VECTOR& GetPos()const { return pos; }

private:
	int			textureGraph;	// �X�v���C�g���쐬���錳�e�N�X�`���̃O���t�B�b�N�n���h��
	VECTOR		pos;			// �`��|�W�V����
	VERTEX3D	Vertex[4];		// ���_�o�b�t�@
	WORD		Index[6];		// �C���f�b�N�X�o�b�t�@
};

