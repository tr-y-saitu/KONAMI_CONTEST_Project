#include "Floor.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Floor::Floor()
	:	modelHandle		(0)
	,	w				(0)
	,	h				(0)
	,	speed			(0)
	,	r				(0)
{
	// ���f���̓ǂݍ���
	modelHandle = MV1LoadModel("data/model/Room/RoomFloorModel.mv1");
	// �X�P�[���̐ݒ�
	scale = VGet(0.01f, 0.01f, 0.01f);
	MV1SetScale(modelHandle, scale);
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
}


/// <summary>
/// �f�X�g���N�^
/// </summary>
Floor::~Floor()
{
	// ���f���n���h���̍폜
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// ������
/// </summary>
void Floor::Initialize(VECTOR initPos)
{
	// initPos
	// ���Ƀ^�C������ׂ邽�߂ɏ������W�������ł��炤

	// �|�W�V�����̏�����
	// �����ŏ�����ׂ�
	pos = initPos;
	dir = VGet(0, 0, 0);
}

/// <summary>
/// �X�V
/// </summary>
void Floor::Update()
{
	// 3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
}

/// <summary>
/// �`��
/// </summary>
void Floor::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(modelHandle);
}


