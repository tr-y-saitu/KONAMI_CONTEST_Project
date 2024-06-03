#include "DxLib.h"
#include "Gem.h"
#include "TreasureChest.h"

// �R���X�g���N�^
TreasureChest::TreasureChest()
	: modelHanlde		(-1)
	, width				(0)
	, height			(0)
	, isHitGem			(false)
	, radius			(0)
{
	modelHanlde = MV1LoadModel("data/model/TreasureChest/TreasureChest.mv1");
	pos = VGet(7, 0, 0);
	scale = VGet(0.005f, 0.005f, 0.005f);
	// ���f���̉�](��a���Ȃ��ʒu�ɏC��)
	MV1SetRotationXYZ(modelHanlde, VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
}

// �f�X�g���N�^
TreasureChest::~TreasureChest()
{
	// ���f���n���h���̍폜
	MV1DeleteModel(modelHanlde);
}

// ������
void TreasureChest::Initialize()
{
	pos = VGet(7, 0, -5);
	// �X�P�[���̐ݒ�
	MV1SetScale(modelHanlde, scale);
	radius = 3.0f;
}

// �X�V
void TreasureChest::Update(Gem& gem)
{
	// 3D���f���̍��W�ݒ�
	MV1SetPosition(modelHanlde, pos);
}

// �`��
void TreasureChest::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(modelHanlde);

	// ���^�̓����蔻��̕`��
	DrawSphere3D(pos, radius, 32, GetColor(0, 0, 255), GetColor(255, 255, 255), false);
}


