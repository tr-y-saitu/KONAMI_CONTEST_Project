#pragma once

#include "DxLib.h"

class Calculation;
class GemManager;


/// <summary>
/// ��΁i�W�F���j
/// </summary>
class Gem final
{
public:
	Gem();
	virtual ~Gem();

	// ���\�b�h
	VECTOR SettingMoveType(int gemType);	// �^�C�v���Ƃ̈ړ��A���S���Y���̐ݒ�
	float SettingFallSpeedType(int gemType);// �^�C�v���Ƃ̗������x�w��
	void Initialize(VECTOR initPos,GemManager gemManager);		// ������
	void Update(Calculation& cal);		// �X�V
	void Draw();						// �`��

	// ���f���n���h���̎擾.
	int GetModelHandle() const { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() const{ return width; }
	const int GetHeight() const { return height; }
	const bool GetVisibleFlag() const { return visibleFlag; }
	const bool GetIsHitPlayer() const { return isHitPlayer; }
	const bool GetIsHitGround() const { return isHitGround; }
	const bool GetIsHitChest() const { return isHitTreasureChest; }
	const float GetRadius() const { return radius; }
	
	// setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitPlayer(const bool set) { isHitPlayer = set; }
	void SetIsHitGround(const bool set) { isHitGround = set; }
	void SetIsHitChest(const bool set) { isHitTreasureChest = set; }

private:
	// �萔
	const float GRAVITY_POWER = 0.002f;		// ��΂ɂ�����d�͂̒l
	const float MOVE_SPEED = 0.13f;			// �ړ����x
	const float JUMP_POWER = 0.1f;			// �v���C���[�ɓ����������̃W�����v��

	// �ϐ�
	// ���f���֌W
	int		modelHandle;	// ���f���n���h��

	// �X�e�[�^�X
	int		gemType;		// ��΂̎��(�_�C�A,���r�[,�T�t�@�C�A,�G�������h)
	VECTOR	pos;			// �|�W�V����
	VECTOR	dir;			// ����
	VECTOR	contactDir;		// �ڐG���̕���
	int		width;			// ��
	int		height;			// ����
	VECTOR	scale;			// �X�P�[��
	float	scaleAdjust;	// �X�P�[���̒���
	float	speed;			// �ړ��X�s�[�h
	float	radius;			// ���^�����蔻��̔��a
	float	fallSpeed;		// �������x
	float	boundPower;		// �o�E���h����l
	float	rotateCount;	// �Q�[�����ɏ����Â�]�����邽�߂̃J�E���g

	// �t���O
	bool	visibleFlag;	// ���݂��Ă��邩
	bool	isHitPlayer;	// �v���C���[�ƐڐG����
	bool	isHitGround;	// ���ƐڐG������
	bool	previousIsHitPlayer;	// �O�̃t���[���Ńv���C���[�ƐڐG���Ă�����
	bool	isHitTreasureChest;	// �󔠂ƐڐG������
};

