#include "SkyDome.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
SkyDome::SkyDome()
	:modelHandle	(-1)
	,textureHandle	(-1)
	,pos			(VGet(0,0,0))
	,pos2			(VGet(0,0,0))
	,dir			(VGet(0,0,0))
	,w				(0)
	,h				(0)
{
	// �����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SkyDome::~SkyDome()
{
	// ���f���n���h���̍폜
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// ������
/// </summary>
void SkyDome::Initialize()
{
	// ���f���n���h���̓ǂݍ���
	modelHandle = MV1LoadModel("data/model/skyDome/Sky_Twilight01.pmx");

	// �e�N�X�`���̃n���h���ǂݍ���
	textureHandle = LoadGraph("data/model/skyDome/Tex_SkyDome_Twilght01.png");

	// ���f���n���h���ɐݒ肵�����e�N�X�`����\��t��
	MV1SetTextureGraphHandle(modelHandle, 0, textureHandle, true);

	// ���f���̊g�嗦���Z�b�g
	MV1SetScale(modelHandle, VGet(0.1f, 0.1f, 0.1f));

	// ���W�ݒ�
	pos = VGet(0, 0, 0);

	// �����ݒ�
	dir = VGet(0, 0, 0);
}

/// <summary>
/// �X�V
/// </summary>
void SkyDome::Update()
{
	// 3D���f���̃|�W�V������ݒ�
	MV1SetPosition(modelHandle,pos);
}

/// <summary>
/// �`��
/// </summary>
void SkyDome::Draw()
{
	// 3D���f���̕`��i��j
	MV1DrawModel(modelHandle);
}


