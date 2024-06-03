#include "Calculation.h"
#include "GemManager.h"
#include "Gem.h"




/// <summary>
/// �R���X�g���N�^
/// </summary>
Gem::Gem()
	: modelHandle			(-1)
	, visibleFlag			(false)
	, width					(0)
	, height				(0)
	, speed					(0)
	, radius				(0.5f)
	, isHitPlayer			(false)
	, isHitGround			(false)
	, previousIsHitPlayer	(false)
	, boundPower			(0)
	, fallSpeed				(0)
	, rotateCount			(0)
	, gemType				(0)
	, scaleAdjust			(0.02f)
{
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
	contactDir = VGet(0, 0, 0);
	scale = VGet(0.02f, 0.02f, 0.02f);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Gem::~Gem()
{
	// 3D���f���̍폜
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// �^�C�v���Ƃ̈ړ��A���S���Y���̐ݒ�
/// </summary>
/// <param name="gemTyep">��΂̎��</param>
/// <returns>���̃^�C�v�̈ړ�����</returns>
VECTOR Gem::SettingMoveType(int gemTyep)
{
	// �Ԃ�l�p����
	VECTOR reDir = VGet(0, 0, 0);

	// ��΂̃^�C�v���󂯂ĕ�����ݒ�
	switch (gemType)
	{
		// �_�C�A�����h
	case GemManager::DIAMOND:
		reDir = VGet(0.3f, 0.7f, 0.0f);	// �΂߉E
		break;

		// ���r�[
	case GemManager::RUBY:
		reDir = VGet(0.5f, 1.0f, 0.0f);	// �΂߉E�i�㋭�߁j
		break;
		
		// �T�t�@�C�A
	case GemManager::SAPPHIRE:
		reDir = VGet(0.2f, 1.0f, 0.0f);	// �΂߉E(�E���)
		break;
		
		// �G�������h
	case GemManager::EMERALD:
		reDir = VGet(1.0f, 0.1f, 0.0f);	// �΂߉E(�E����)
		break;

		// ���̑�
	default:
		break;
	}

	// ���̃^�C�v�̕�����Ԃ�
	return reDir;
}


/// <summary>
/// ��΂̃^�C�v�ʂŗ������x��ݒ�
/// </summary>
/// <param name="gemType">��΂̃^�C�v</param>
/// <returns>�������x</returns>
float Gem::SettingFallSpeedType(int gemType)
{
	// �Ԃ�l
	float reFallSpeed = 0;
	
	// �^�C�v�ʂɗ������x��ݒ�
	switch (gemType)
	{
		// �_�C�A�����h
	case GemManager::DIAMOND:
		fallSpeed = 0.05f;
		break;

		// ���r�[
	case GemManager::RUBY:
		fallSpeed = 0.001f;
		break;

		// �T�t�@�C�A
	case GemManager::SAPPHIRE:
		fallSpeed = 0.001f;
		break;

		// �G�������h
	case GemManager::EMERALD:
		fallSpeed = 0.01f;
		break;

		// ���̑�
	default:	
		break;
	}

	// �ݒ肵���������x
	return reFallSpeed;
}

/// <summary>
/// ������
/// </summary>
void Gem::Initialize(VECTOR initPos, GemManager gemManager)
{
	// 3D���f���ݒ�
	gemType = GetRand(3);					// ��΂̎�ނ𗐐��Őݒ�
	// �x�[�X�̃��f���̏������ƂɃ��f�������[�h
	modelHandle = MV1DuplicateModel(gemManager.SettingGemModle(gemType));	

	// �X�e�[�^�X���
	pos = initPos;							// ���W�������Őݒ�
	dir = VGet(0, 0, 0);					// �����̐ݒ�
	contactDir = SettingMoveType(gemType);	// ��΂̃^�C�v�̃v���C���[�Ɠ����������̕�����ݒ�
	radius = 0.1;							// ���^�̂����蔻��̔��a
	boundPower = 1.5f;						// �o�E���h����l
	fallSpeed = SettingFallSpeedType(gemType);	// �������x���^�C�v���Ƃɐݒ�
	MV1SetScale(modelHandle, scale);		// �X�P�[���̐ݒ�
	scaleAdjust = 0.02f;					// �X�P�[���̒����p
	rotateCount = 0;						// ��]��

	// �t���O
	isHitPlayer = false;		// �v���C���[�ƐڐG������
	visibleFlag = true;			// ���݂��Ă��邩
	isHitGround = false;		// �n��ƐڐG������
	previousIsHitPlayer = false;// �O�̃t���[���Ńv���C���[�ƐڐG������
	isHitPlayer = false;		// �v���C���[�ƐڐG����
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="cal">�v�Z�N���X</param>
void Gem::Update(Calculation& cal)
{
	// ��������]�P�t���[������1�x��]����
	if (rotateCount <= 360)
	{
		rotateCount++;
	}
	if (rotateCount >= 360)
	{
		rotateCount = 0;
	}
	// ��������]����
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, rotateCount * DX_PI_F / 180.0f, 0.0f));

	

	///////////////////////////////////////////////////////////////
	// �d�͏��� ////////////////////////////////////////////
	// �������x�ɏd�͂����Z
	fallSpeed -= GRAVITY_POWER;
	
	//// �n�ʂɂ��Ă��Ȃ����ɍ쓮
	//if (isHitGround == false)
	//{
	//	// �d�͂𗎉����x�ɉ��Z����
	//	fallSpeed = -JUMP_POWER;
	//}

	// ����艺�ɂ͗����Ȃ�
	if (pos.y <= 0.1 && isHitGround == false)
	{
		pos.y = 0.1;				// ���W��n�ʂɌŒ�
		isHitGround = true;		// �n�ʂɂ��Ă�����
		visibleFlag = false;	// ���݂�����
		
	}

	///////////////////////////////////////////////////////////////
	// �o�E���h���� ////////////////////////////////////////////
	// ���ɂ����璵�˂�
	if (isHitGround == true)
	{
		pos.y = 0.1;
		// �d�͂ɋt�炤�i������Ȃ��ƒn�ʊђʂ���j
		fallSpeed += GRAVITY_POWER * 1.2f;
		//dir = VAdd(dir, VGet(0, 1, 0));
		//isHitGround = false;
		scaleAdjust -= 0.0005f;		// �����ÂX�P�[��������������
		// �X�P�[����ݒ�
		MV1SetScale(modelHandle, VGet(scaleAdjust, scaleAdjust, scaleAdjust));
	}
	// �X�P�[�����[���ȉ��ɂȂ�����C��
	if (scaleAdjust <= 0)
	{
		scaleAdjust = 0;
	}
	
	// �o�E���h������Ȃ�R�����g�͂���
	//// ���`��ԂŃo�E���h����l�����߂�
	//boundPower= cal.Lerp_F(boundPower, 0.0f, 0.01);
	//if (pos.y >= boundPower)	// �n�ʂ�����Ȃ�
	//{
	//	// �o�E���h���ׂ���������Ȃ���
	//	if (boundPower <= 0.3)
	//	{
	//		boundPower = 0;
	//	}
	//	isHitGround = false;
	//}
	
	// �v���C���[�ƐڐG������
	if (isHitPlayer)
	{
		fallSpeed = +JUMP_POWER;
		dir = VAdd(dir, contactDir);	// ��΂��ƂɈႤ����
		isHitGround = false;
		isHitPlayer = false;
	}

	// �ړ����� /////////////////////////////////////////////////////
	
	// ���K��
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}
	// �����ݒ菈�� ///////////////////////////////////////////////////
	
	// �ړ��ʂ��o��
	auto velocity = VScale(dir, MOVE_SPEED);

	// �����̐��K��
	/*if (VSize(velocity) != 0)
	{
		dir = VNorm(dir);
	}*/

	
	// �������x���ړ��ʂɉ�����
	auto fallVelocity = VGet(0, fallSpeed, 0);
	velocity = VAdd(velocity, fallVelocity);

	// �|�W�V�����̍X�V
	pos = VAdd(pos, velocity);


	/////////////////////////////////////////////////////////////////
	
	// 3D���f���̍��W�ݒ�
	MV1SetPosition(modelHandle, pos);
}

/// <summary>
/// �`��
/// </summary>
void Gem::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(modelHandle);

	// ���^�̓����蔻��̕`��
	DrawSphere3D(pos, radius, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);

	// �v���C���[�ƐڐG������
	if (isHitPlayer)
	{
		DrawFormatString(100, 100, GetColor(255, 255, 255), "Gem Hit", true);
	}
}