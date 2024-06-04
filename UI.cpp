#include "Game.h"
#include "Player.h"
#include "TreasureChest.h"
#include "UI.h"



/// <summary>
/// �R���X�g���N�^
/// </summary>
UI::UI()
	:	menuGraph			(-1)
	,	strGetModleHandel	(-1)
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
}



/// <summary>
/// �`��
/// </summary>
void UI::Draw(int state, Player& player, bool clearFlag,TreasureChest& chest)
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
		
		// �uGET!�v���f����`��
		MV1SetPosition(strGetModleHandel, VGet(0,0,0));
		if (isHitGemToChest)
		{
			MV1DrawModel(strGetModleHandel);
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
