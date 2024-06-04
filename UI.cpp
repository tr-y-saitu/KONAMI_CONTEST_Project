#include "Game.h"
#include "Player.h"
#include "TreasureChest.h"
#include "UI.h"



/// <summary>
/// �R���X�g���N�^
/// </summary>
UI::UI()
	: menuGraph(-1)
	, strGetModleHandel(-1)
	, isHitGemToChest(false)
	, strGetDrawCount(0)
{
	strGetModleHandel = MV1LoadModel("data/model/UI/GET!.mv1");
	MV1SetScale(strGetModleHandel, VGet(0.05f, 0.05f, 0.0f));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
UI::~UI()
{
	// 3D���f���n���h���̍폜
	MV1DeleteModel(strGetModleHandel);
}


/// <summary>
/// ������
/// </summary>
void UI::Initialize()
{
	if (menuGraph < 0)
	{
		menuGraph = LoadGraph("data/texture/Menu/GemPiratesMenuGraph.png");
	}
	isHitGemToChest = false;
	strGetDrawCount = 0;
}


/// <summary>
/// UI�̕`��
/// </summary>
/// <param name="state">�Q�[���X�e�[�g</param>
/// <param name="player">�v���C���[�N���X</param>
/// <param name="isDrawUIFlag">UI��`�悷��w��</param>
/// <param name="chest">�󔠃N���X</param>
void UI::Draw(int state, Player& player, bool& isDrawUIFlag, TreasureChest& chest)
{
	int _uiColor = GetColor(200, 200, 200);
	// �X�e�[�g���Ƃɕ`���ύX
	switch (state)
	{
		// �^�C�g��
	case STATE_MENU:

		// ������`��

		// �^�C�g���w�i�̕`��
		DrawGraph(0, 0, menuGraph, true);

		break;

		// �Q�[����
	case STATE_GAME:

		// �uGET!�v���f���̍��W��ݒ�
		MV1SetPosition(strGetModleHandel, VGet(0, 0, 0));

		// ��΂ƕ󔠂��ڐG������(�`��w�莞�Ԃ𒴂��Ă��Ȃ����)
		if (isHitGemToChest && strGetDrawCount <= STRING_GET_DRAW_TIME)
		{
			// �uGET!�v���f����`�悷�鎞�Ԃ�i�߂�
			strGetDrawCount++;
			// 3D���f���`��
			MV1DrawModel(strGetModleHandel);
		}
		// �`��w�莞�Ԃ𒴂�����[���ɖ߂�
		if (strGetDrawCount >= STRING_GET_DRAW_TIME)
		{
			// UI��`�悷��w�����I�t�ɂ���
			isDrawUIFlag = false;
			// �`��w�莞�Ԃ��[���ɂ���
			strGetDrawCount = 0;
			// ��΂ƕ󔠂͓������Ă��Ȃ�
			isHitGemToChest = false;
		}


		break;

		// �N���A���
	case STATE_CLEAR:

		// �N���A����
		// �\��

		break;

		// �Q�[���I�[�o�[
	case STATE_GAMEOVER:

		// �Q�[���I�[�o�[����
		// �\��
		break;

	default:
		break;
	}

}
