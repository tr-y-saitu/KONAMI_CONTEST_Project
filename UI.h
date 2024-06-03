#pragma once


#include "DxLib.h"

class Game;
class Player;
class TreasureChest;

class UI
{
public:
	UI();		// �R���X�g���N�^
	~UI();		// �f�X�g���N�^

	void Initialize();		// ������
	void Draw(int state,Player& player,bool clearFlag, TreasureChest& chest);	// �`��

	// Getter
	const bool GetIsHitGemToChest()const { return isHitGemToChest; }

	// Setter
	void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
	// �萔

	// �ϐ�
	int		menuGraph;		// ���j���[�摜
	int		strGetModleHandel;	// �uGET!�v�̃��f���n���h��
	bool	isHitGemToChest;	// ��΂ƕ󔠂��ڐG����
};






