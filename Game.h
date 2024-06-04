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
	void CountGameFraem() ;	// �Q�[���t���[���𐔂���
	void Create();			// ����
	void Initialize();		// ����������
	void InitializeGameStart();	// �Q�[���ŏ��̏�����
	void DeleteGame();		// ���������I�u�W�F�N�g�̍폜
	void UpdateGame();		// �Q�[���A�b�v�f�[�g
	void DrawGame();		// �Q�[���`��
	void ChangeGameState();	// �Q�[���X�e�[�g�̐؂�ւ�
	void ProcessKey();		// �Q�[���i�s�ɂ������L�[���͏���
	void DrawTimer();		// �������Ԃ̕`��
	void SettingTimer();	// ���݌o�ߎ��Ԃ̍X�V
	

	const int GetNowTimer() { return nowTimer; }
	const int GetFrameCount() { return gameFrameCount; }
	const int GetGameState() { return gameState; }
	const bool GetIsClearFlag() { return isClearFlag; }

	// �g�p�N���X
	Player*		player;
	Enemy*		enemy;
	Camera*		camera;
	Collision*	collision;
	BGObj*		bgobj[5];
	BGObj*		bgobj2[4];
	UI*			ui;
	SkyDome*	skyDome;
	BG*			bg[3];
	Effekseer1* effekseer1;
	FPSSetting* fpsSetting;
	Room*		room;
	Floor*		floor;
	Calculation calculation;
	GemManager*	gemManager;
	TreasureChest* treasureChest;

	std::vector<Gem*>	gem;

private:
	// �萔
	const int GEM_TOTAL_NUM = 100;	// ��΂̑����̐�

	// �ϐ�
	int		gameState;		// ���݂̃X�e�[�g
	int		gameFrameCount;	// �Q�[���t���[���J�E���g
	int		previousTime;	// �Q�[�����[�v���n�܂�O�̎���
	int		timer;			// �Q�[������
	float	nowTimer;		// ���݂̐�������
	bool	keyOn;			// �L�[���͂���Ă��邩
	bool	keyRelease;		// �L�[���͂����ꂽ��
	bool	prevKeyOn;		// �O�t���[���ŃL�[���͂���������
	int		isHitCount;		// �q�b�g���Ă��牽�t���[���o�߂�����
	bool	isClearFlag;	// �N���A�������̃t���O
	double	isClearCount;	// �N���A���Ă���̃J�E���g
	bool	isDrawGetUi;	// ��΃Q�b�g����UI���o�����邩�ǂ���

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





