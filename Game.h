#pragma once

#include "DxLib.h"
#include <vector>
#include "Calculation.h"


// �v���g�^�C�v�錾
class BG;
class Room;
class Floor;
class Player;
class Enemy;
class Collision;
class Camera;
class BGObj;
class Car;
class UI;
class SkyDome;
class Confetti;
class Effekseer1;
class FPSSetting;
class WorldSprite;
class Calculation;
class Gem;
class GemManager;
class TreasureChest;


/// <summary>
/// �Q�[������N���X
/// </summary>
class Game
{
public:
	Game();
	virtual ~Game();

	/// <summary>
	/// �Q�[���t���[���𐔂���
	/// </summary>
	void CountGameFraem();

	/// <summary>
	/// �S�I�u�W�F�N�g��new�@�C���X�^���X
	/// </summary>
	void Create();

	/// <summary>
	/// �S�I�u�W�F�N�g�̏���������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �Q�[���N�����̂ݍs���S�I�u�W�F�N�g�̏�����
	/// </summary>
	void InitializeGameStart();

	/// <summary>
	/// �C���X�^���X�������S�I�u�W�F�N�g�̍폜
	/// </summary>
	void DeleteGame();

	/// <summary>
	/// �S�I�u�W�F�N�g�̍X�V
	/// </summary>
	void UpdateGame();

	/// <summary>
	/// �S�I�u�W�F�N�g�̕`��
	/// </summary>
	void DrawGame();

	/// <summary>
	/// �Q�[���X�e�[�g�̐؂�ւ�
	/// </summary>
	void ChangeGameState();

	/// <summary>
	/// �Q�[���i�s�ɂ������L�[���͏���
	/// </summary>
	void ProcessKey();

	/// <summary>
	/// �������Ԃ̕`��
	/// </summary>
	void DrawTimer();		// �������Ԃ̕`��

	// Getter/Setter
	const int GetNowTimer() { return nowTimer; }
	const int GetFrameCount() { return gameFrameCount; }
	const int GetGameState() { return gameState; }
	const bool GetIsClearFlag() { return isClearFlag; }


	// �g�p�N���X
	Player* player;			// �v���C���[
	Enemy* enemy;			// �G�l�~�[
	Camera* camera;			// �J����
	Collision* collision;		// �����蔻��
	UI* ui;				// UI
	SkyDome* skyDome;		// �X�J�C�h�[��
	Effekseer1* effekseer1;
	FPSSetting* fpsSetting;
	Room* room;			// ����
	Floor* floor;			// ��
	Calculation calculation;	// �v�Z�p
	GemManager* gemManager;		// ��ΊǗ��N���X
	std::vector<Gem*>	gem;		// ���
	TreasureChest* treasureChest;	// ��

private:

	// �萔
	const int GEM_TOTAL_NUM = 100;	// ��΂̑����̐�

	// �ϐ�
	int		gameState;		// ���݂̃X�e�[�g
	int		gameFrameCount;	// �Q�[���t���[���J�E���g
	int		previousTime;	// �Q�[�����[�v���n�܂�O�̎���
	int		timer;			// �Q�[������
	int		nowTimer;		// ���݂̐�������
	bool	keyOn;			// �L�[���͂���Ă��邩
	bool	keyRelease;		// �L�[���͂����ꂽ��
	bool	prevKeyOn;		// �O�t���[���ŃL�[���͂���������
	int		isHitCount;		// �q�b�g���Ă��牽�t���[���o�߂�����
	bool	isClearFlag;	// �N���A�������̃t���O
	double	isClearCount;	// �N���A���Ă���̃J�E���g
	bool	isDrawGetUI;	// ��΃Q�b�g����UI���o�����邩�ǂ���

	// ���j���[
	int		menuGraph;		// ���j���[�p�摜

	// ���f����
	int		modelHandleGemDia;	// ��΁i�_�C�A�j
	int		modelHandleGemRuby;	// ��΁i���r�[�j

};


// �Q�[���i�s���
enum STATE
{
	STATE_MENU,			// ���j���[
	STATE_GAME,			// �Q�[����
	STATE_CLEAR,		// �N���A
	STATE_GAMEOVER,		// �Q�[���I�[�o�[
};





