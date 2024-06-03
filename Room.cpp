#include "Room.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
Room::Room()
	:	modelHandle		(0)
	,	w				(0)
	,	h				(0)
	,	speed			(0)
	,	r				(0)
{
	modelHandle = MV1LoadModel("data/model/Room/RoomFloorModel.mv1");
	scale = VGet(0.02f ,0.02f, 0.02f);
	// �X�P�[���̐ݒ�
	MV1SetScale(modelHandle, scale);
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Room::~Room()
{
	// ���f���̃A�����[�h
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// ������
/// </summary>
void Room::Initialize()
{
	pos = VGet(6, 0, 9);		// ���W�̃Z�b�g
	dir = VGet(0, 0, 0);		// �����̃Z�b�g

}



/// <summary>
/// �X�V
/// </summary>
void Room::Update()
{
	// 3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);

}


/// <summary>
/// �`��
/// </summary>
void Room::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(modelHandle);
}