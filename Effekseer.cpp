#include "DxLib.h"
//#include "EffekseerForDXLib.h"
#include "Effekseer.h"


Effekseer1::Effekseer1()
	:	effectResourceHandle	(0)
	,	graphBackGroundHandle	(0)
	,	graphFrontHandle		(0)
	,	time					(0)
	,	isFullScreen			(false)
	,	playingEffectHandle		(0)
{
	pos = VGet(0, 0, 0);
}

Effekseer1::~Effekseer1()
{
	// �G�t�F�N�g���\�[�X���폜����B(Effekseer�I�����ɔj�������̂ō폜���Ȃ��Ă�����)
	//DeleteEffekseerEffect(effectResourceHandle);
}

// �G�t�F�N�V�A���g�����߂̏���
void Effekseer1::ReadyEffekseerForDXLib()
{
	//// �`���𗠉�ʂɐݒ肷��
	//SetDrawScreen(DX_SCREEN_BACK);

	//// DirectX11���g�p����悤�ɂ���B(DirectX9���A�ꕔ�@�\�s��)
	//// Effekseer���g�p����ɂ͕K���ݒ肷��B
	//SetUseDirect3DVersion(DX_DIRECT3D_11);

	//// Z�o�b�t�@��L���ɂ���B
	//// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
	//SetUseZBuffer3D(TRUE);

	//// Z�o�b�t�@�ւ̏������݂�L���ɂ���B
	//// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
	//SetWriteZBuffer3D(TRUE);

}

// ������
void Effekseer1::Initialize()
{
	// �G�t�F�N�g���\�[�X�̓ǂݍ���
	//effectResourceHandle = LoadEffekseerEffect("Laser01.efkefc", 25.0f);

	// �Ȃ�ł������̂ŉ摜��ǂݍ���
	graphBackGroundHandle = LoadGraph(_T("Texture/Background.png"));
	graphFrontHandle = LoadGraph(_T("Texture/Front.png"));

	// ���Ԃ��������i����I�ɃG�t�F�N�g���Đ����邽�߁j
	time = 0;

	// �t���X�N���[���؂�ւ��t���O��ݒ肷��
	isFullScreen = false;

	// �G�t�F�N�g��\������ʒu��ݒ�
	pos = VGet(100.0f, 250.0f, 0.0f);

	// ���[���h���W���X�N���[�����W�ɕϊ�����
	pos = ConvWorldPosToScreenPos(VGet(0,10,20));

	// �X�N���[�����W�����[���h���W�ɕϊ�����
	//pos = ConvScreenPosToWorldPos(pos);

	// �Đ����̃G�t�F�N�g�̃n���h��������������
	playingEffectHandle = -1;

}

void Effekseer1::Update()
{
	// ����I�ɃG�t�F�N�g���Đ�����
	if (time % 60 == 0)
	{
		// �G�t�F�N�g���Đ�����B
		//playingEffectHandle = PlayEffekseer2DEffect(effectResourceHandle);
		
		// �G�t�F�N�g�̈ʒu�����Z�b�g����B
		pos.x = 100.0f;
	}


	// �Đ����̃G�t�F�N�g���ړ�����B
	//SetPosPlayingEffekseer2DEffect(playingEffectHandle, pos.x, pos.y, 0);
	pos.x += 2.0f;

	// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
	//UpdateEffekseer2D();

	// ���Ԃ��o�߂�����
	time++;

	//// ���[���h���W���X�N���[�����W�ɕϊ�����
	//pos = ConvWorldPosToScreenPos(pos);

	// ()���̍��W���J�����̎��E�ɓ����Ă��Ȃ����ǂ����𔻒f����
	int flag = CheckCameraViewClip(pos);
	int gg = 0;
}


void Effekseer1::Draw()
{
	// ���ł������̂ŉ摜��`�悷��B
	// �������ĕ`�悵����łȂ��ƁAEffekseer�͕`��ł��Ȃ��B
	DrawGraph(0, 0, graphBackGroundHandle, TRUE);

	// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
	//DrawEffekseer2D();

	// �G�t�F�N�g�̏�ɂ��摜��`��ł���B
	DrawGraph(0, 0, graphFrontHandle, TRUE);
}
