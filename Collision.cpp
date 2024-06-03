#include <stdio.h>
#include "math.h"
#include "Calculation.h"
#include "TreasureChest.h"
#include "Player.h"
#include "Enemy.h"
#include "Gem.h"
#include "collision.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
Collision::Collision()
{

}


/// <summary>
/// �f�X�g���N�^
/// </summary>
Collision::~Collision()
{

}




void Collision::HitPlayerToEnemy(Player& player, Enemy& enemy)
{
	// �����������A�������Ă��Ȃ���
	bool isHit = false;

	// ���̎擾
	VECTOR _playerPos = player.GetPos();		// �v���C���[�̍��W
	VECTOR _enemyPos = enemy.GetPos();			// �G�l�~�[�̍��W
	double _rPlayer = player.GetRadius();		// �v���C���[�̓����蔻��̔��a
	double _rEnemy = enemy.GetRudius();			// �G�l�~�[�̓����蔻��̔��a

	// �v���C���[�ƃG�l�~�[�̓����蔻��
	// �G�l�~�[�����݂��Ă��邩�̒l�������炤
	if (enemy.GetVisibleFlag() == true)
	{
		// �v���C���[����G�l�~�[�̃x�N�g��
		VECTOR _difference = VSub(_playerPos, _enemyPos);

		// ��Βl�v�Z
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// �������Z�o
		//double _d = sqrt((_playerPos.x * _enemyPos.x) + (_playerPos.y * _enemyPos.y) + (_playerPos.z * _enemyPos.z));
		// �����鋗��
		double _rSum = _rPlayer + _rEnemy;

		
		// ���S�_�Ƃ̋��������߂�
		double _PlayerToEnemy = sqrt(pow(_playerPos.x + _enemyPos.x, 2) + pow(_playerPos.y + _enemyPos.y, 2) + pow(_playerPos.z + _enemyPos.z, 2));


		// ���a�Ƃ̋�����2�̔��a�̍��v�������������
		if ( distance <= _rSum)
		{
			isHit = true;
		}
	}
	// �������Ă��邩�ۂ�
	player.SetIsHitEnemy(isHit);
}


/// <summary>
/// �v���C���[�ƕ�΂Ƃ̓����蔻��
/// </summary>
/// <param name="player">�v���C���[</param>
/// <param name="gem">���</param>
void Collision::IsHitPlayerToGem(Player& player, Gem& gem)
{
	// �ŏ��͓������Ă��Ȃ�����
	bool isHit = false;

	// ���̎擾
	VECTOR _playerPos = player.GetPos();		// �v���C���[���W
	VECTOR _gemPos = gem.GetPos();				// ��΍��W
	double _rPlayer = player.GetRadius();		// �v���C���[�̓����蔻��̔��a
	double _rGem = gem.GetRadius();				// ��΂̓����蔻��̔��a

	// �v���C���[�ƃG�l�~�[�̓����蔻��
	// �G�l�~�[�����݂��Ă��邩�̒l�������炤
	if (gem.GetVisibleFlag() == true)
	{
		// �v���C���[�����΁i�W�F���j�̃x�N�g��
		VECTOR _difference = VSub(_playerPos, _gemPos);

		// ��Βl�v�Z
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// �������Z�o
		//double _d = sqrt((_playerPos.x * _gemPos.x) + (_playerPos.y * _gemPos.y) + (_playerPos.z * _gemPos.z));
		// �����鋗��
		double _rSum = _rPlayer + _rGem;


		// ���a�Ƃ̋�����2�̔��a�̍��v�������������
		if (distance <= _rSum)
		{
			isHit = true;
		}
	}
	// �������Ă��邩�ۂ�
	gem.SetIsHitPlayer(isHit);
	player.SetIsHitGem(isHit);
}

/// <summary>
/// ��΂ƕ󔠂̓����蔻��
/// </summary>
/// <param name="gem">���</param>
/// <param name="chest">��</param>
void Collision::IsHitGemToTreasureChest(Gem& gem, TreasureChest& chest)
{
	// �ŏ��͓������Ă��Ȃ�����
	bool isHit = false;

	// ���̎擾
	VECTOR _gemPos = gem.GetPos();		// ��΂̍��W
	VECTOR _chestPos = chest.GetPos();	// �󔠂̍��W
	double _rGem = gem.GetRadius();		// ��΂̔��a
	double _rChest = chest.GetRadius();	// �󔠂̔��a

	// ��΂ƕ󔠂̓����蔻��
	// ��΂������݂��Ă��邩�̒l�������炤
	if (gem.GetVisibleFlag() == true)
	{
		// �v���C���[�����΁i�W�F���j�̃x�N�g��
		VECTOR _difference = VSub(_gemPos, _chestPos);

		// ��Βl�v�Z
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// �����鋗��
		double _rSum = _rGem + _rChest;

		// ���a�Ƃ̋�����2�̔��a�̍��v�������������
		if (distance <= _rSum)
		{
			// �ڐG���Ă���
			isHit = true;
		}
	}
	// �������Ă��邩�ۂ�
	gem.SetIsHitChest(isHit);
	chest.SetIsHitGem(isHit);
 }


/// <summary>
/// ��΂̂����ꂩ�ƕ󔠂�����������
/// </summary>
/// <param name="gem">���</param>
/// <param name="chest">��</param>
/// <returns>��΂ƕ󔠂��ڐG������</returns>
bool Collision::IsHitGemToTreasureChestBool(Gem& gem, TreasureChest& chest)
{
	// �ŏ��͓������Ă��Ȃ�����
	bool isHit = false;

	// ���̎擾
	VECTOR _gemPos = gem.GetPos();		// ��΂̍��W
	VECTOR _chestPos = chest.GetPos();	// �󔠂̍��W
	double _rGem = gem.GetRadius();		// ��΂̔��a
	double _rChest = chest.GetRadius();	// �󔠂̔��a

	// ��΂ƕ󔠂̓����蔻��
	// ��΂������݂��Ă��邩�̒l�������炤
	if (gem.GetVisibleFlag() == true)
	{
		// �v���C���[�����΁i�W�F���j�̃x�N�g��
		VECTOR _difference = VSub(_gemPos, _chestPos);

		// ��Βl�v�Z
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// �����鋗��
		double _rSum = _rGem + _rChest;

		// ���a�Ƃ̋�����2�̔��a�̍��v�������������
		if (distance <= _rSum)
		{
			// �ڐG���Ă���
			isHit = true;
		}
	}
	// �������Ă��邩�ۂ�
	gem.SetIsHitChest(isHit);
	chest.SetIsHitGem(isHit);
	
	return isHit;

}



