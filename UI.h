#pragma once


#include "DxLib.h"

class Game;
class Player;
class TreasureChest;


/// <summary>
/// UI�N���X
/// </summary>
class UI
{
public:
	UI();		// �R���X�g���N�^
	virtual ~UI();		// �f�X�g���N�^

	/// <summary>
	/// UI�̏�����
	/// </summary>
	void Initialize();

	/// <summary>
	/// UI�̕`��
	/// </summary>
	/// <param name="state">�Q�[���X�e�[�g</param>
	/// <param name="player">�v���C���[�N���X</param>
	/// <param name="isDrawUIFlag">UI��`�悷��w��</param>
	/// <param name="chest">�󔠃N���X</param>
	void Draw(int state, Player& player, bool& isDrawUIFlag, TreasureChest& chest);	// �`��

	// Getter
	const bool GetIsHitGemToChest()const { return isHitGemToChest; }

	// Setter
	void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
	// �萔
	const int STRING_GET_DRAW_TIME = 100;		// �uGET!�v��`�悷��t���[����

	// �ϐ�
	int		menuGraph;			// ���j���[�摜
	bool	isHitGemToChest;	// ��΂ƕ󔠂��ڐG����
	int		strGetModleHandel;	// �uGET!�v�̃��f���n���h��
	int		strGetDrawCount;	// �uGET!�v��`�悷�鎞�Ԃ�ݒ肷��J�E���g
};






