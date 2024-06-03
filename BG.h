#pragma once
#include "DxLib.h"

class BG
{
public:
	BG();
	~BG();

	void Initialize(int graph, int index);	// ������
	void Update(float buf);		// �X�V
	void Draw();		// �`��

private:
	// �萔
	const float BG_SCROLL_SPEED = 5.0f;

	int		graphHandle;		// �w�i�X�N���[���p�摜
	VECTOR	pos;				// �|�W�V����
	int		w;					// ��
	int		h;					// ����

};

