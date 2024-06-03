#pragma once

class Gem;

/// <summary>
/// �󔠃N���X
/// </summary>
class TreasureChest final
{
public:
	TreasureChest();
	virtual ~TreasureChest();

	void Initialize();		// ������
	void Update(Gem& gem);			// �X�V
	void Draw();			// �`��

	// Getter
	const VECTOR& GetPos()const { return pos; }
	const bool GetIsHitGem()const { return isHitGem; }
	const float GetRadius()const { return radius; }	

	// Setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitGem(const bool set) { isHitGem = set; }

private:
	// �ϐ�
	// ���f��
	int		modelHanlde;		// ���f���n���h��

	// ���
	VECTOR	pos;			// �|�W�V����
	VECTOR	scale;			// �X�P�[��
	int		width;			// ��
	int		height;			// ����

	// �t���O
	bool	isHitGem;		// �󔠂���΂ƐڐG������

	// �����蔻��
	float	radius;			// ���^�����蔻��p�̔��a
};


