// �C���N���[�h�t�@�C��

#include <stdio.h>
#include <iostream>
#include <vector>
#include "math.h"
#include "Calculation.h"
#include "Room.h"
#include "GemManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Collision.h"
#include "vector"
#include "UI.h"
#include "SkyDome.h"
#include "Gem.h"
#include "Confetti.h"
#include "TreasureChest.h"
#include "Effekseer.h"
#include "Game.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
Game::Game()
	: isHitCount(0)
	, isClearCount(0)
	, isClearFlag(false)
	, nowTimer(0)
	, isDrawGetUI(false)
{
	// �ϐ��̏�����
	gameState = STATE_MENU;
	gameFrameCount = 0;
	previousTime = 0;
	timer = 0;
	nowTimer = 0;
	keyOn = false;
	keyRelease = false;
	prevKeyOn = false;
	menuGraph = -1;
	// �x�[�X���f���̃��[�h
	modelHandleGemDia = MV1LoadModel("data/model/Gem/Diamonds.mv1");	// �_�C�A
	modelHandleGemRuby = MV1LoadModel("data/model/Gem/Ruby.mv1");	// ���r�[
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Game::~Game()
{
}

/// <summary>
/// �Q�[�����X�^�[�g���Ă���̃t���[�����𐔂���
/// </summary>
void Game::CountGameFraem()
{
	// �Q�[���t���[���𐔂���
	gameFrameCount++;
}

/// <summary>
/// �Q�[���I�u�W�F�N�g�̐���
/// </summary>
void Game::Create()
{
	// �S�I�u�W�F�N�g�̐���
	player = new Player();		// �v���C���[
	enemy = new Enemy();		// �G�l�~�[
	camera = new Camera();		// �J����
	collision = new Collision();	// �����蔻��i�R���W�����j
	ui = new UI();
	skyDome = new SkyDome();
	room = new Room();
	treasureChest = new TreasureChest();
	for (int i = 0; i < GEM_TOTAL_NUM; i++)
	{
		gem.push_back(new Gem());
	}
	gemManager = new GemManager();
	//effekseer1 = new Effekseer1();
}

/// <summary>
/// ���������I�u�W�F�N�g�̍폜
/// </summary>
void Game::DeleteGame()
{
	// �폜
	delete(player);
	delete(enemy);
	delete(camera);
	delete(collision);
	delete(ui);
	delete(skyDome);
	delete(room);
	delete(treasureChest);
	delete(gemManager);
	for (int i = 0; i < GEM_TOTAL_NUM; i++)
	{
		delete(gem[i]);
	}

	//delete(effekseer1);
}


/// <summary>
/// �Q�[���ŏ��̏�����
/// </summary>
void Game::InitializeGameStart()
{
	// Effekseer���g�p����
	//effekseer1->ReadyEffekseerForDXLib();

	// �t�H���g�ݒ�
	ChangeFont("�`���[�NS");

	isHitCount = 0;
	nowTimer = 0;

	// �R�c���f���̓ǂݍ���
	gemManager->LoadModle();		// ��΂̃��f�����[�h

	// �Q�[���I�u�W�F�N�g�̏�����
	player->Initialize();
	ui->Initialize();
	skyDome->Initialize();
	room->Initialize();
	treasureChest->Initialize();
	for (int i = 0; i < gem.size(); i++)
	{
		gem[i]->Initialize(VGet(i, 0, -5), *gemManager);
	}
	//effekseer1->Initialize();

	// �Q�[�����n�܂�O��GetNowCount���擾
	previousTime = GetNowHiPerformanceCount();

	gameFrameCount = 0;			// �t���[���J�E���g�̏�����
	isDrawGetUI = false;		// ��΂��Q�b�g��������UI���o�����邩�ǂ���

}


/// <summary>
/// ����������
/// </summary>
void Game::Initialize()
{
	// �Q�[�����n�܂�O��GetNowCount���擾
	previousTime = GetNowHiPerformanceCount();

	gameFrameCount = 0;
	nowTimer = 1;
	isHitCount = 0;
	isClearFlag = false;
	isClearCount = 0;

	player->Initialize();
	//enemy->Initialize();
	ui->Initialize();
	skyDome->Initialize();
	room->Initialize();
	treasureChest->Initialize();
	for (int i = 0; i < gem.size(); i++)
	{
		gem[i]->Initialize(VGet(i - 10, 10, -5), *gemManager);
	}
	//effekseer1->Initialize();
}




/// <summary>
/// �Q�[���X�e�[�g�؂�ւ�
/// </summary>
void Game::ChangeGameState()
{
	// �����ɐ؂�ւ�肷����̂ŁA������Ǝ��Ԃ��~�߂�
	WaitTimer(500);

	// �X�e�[�g���؂�ւ�����u�ԁA�L�[�𗣂�����������Z�b�g
	keyOn = false;
	keyRelease = false;

	// �X�e�[�g�؂�ւ�����
	switch (gameState)
	{
		// �^�C�g��
	case STATE_MENU:
		break;

		// �Q�[����
	case STATE_GAME:
		Initialize();
		break;

		// �N���A���
	case STATE_CLEAR:
		break;

		// �Q�[���I�[�o�[
	case STATE_GAMEOVER:
		break;

	default:
		break;
	}


}

/// <summary>
/// �A�b�v�f�[�g�Q�[��
/// </summary>
void Game::UpdateGame()
{
	// �L�[���͏���
	ProcessKey();

	// �X�e�[�g���Ƃɏ����𕪂���
	switch (gameState)
	{
		// ���j���[ //////////////////////////////////////
	case STATE_MENU:

		if (keyRelease)
		{
			gameState = STATE_GAME;
			ChangeGameState();
		}

		break;

		// �Q�[���� //////////////////////////////////////
	case STATE_GAME:

		// �Q�[���t���[���𐔂���
		CountGameFraem();

		// �Q�[���A�b�v�f�[�g
		// �����蔻�菈��
		//collision->HitPlayerToEnemy(*player, *enemy);	// �v���C���[�ƃG�l�~�[�̓����蔻��
		for (int i = 0; i < gem.size(); i++)
		{
			// �v���C���[�ƕ�΂̓����蔻�菈��
			collision->IsHitPlayerToGem(*player, *gem[i]);

			// ��΂ƕ󔠂̓����蔻�菈��
			//collision->IsHitGemToTreasureChest(*gem[i],*treasureChest);

			// ��΂ƕ󔠂̓����蔻�菈��(bool�^�Ԃ�l)
			if (collision->IsHitGemToTreasureChestBool(*gem[i], *treasureChest))
			{
				// UI��`�悷��w�����o��
				isDrawGetUI = true;
				break;
			}
		}
		// �uGET!�v�̃��f����`��
		ui->SetIsHitGemToChest(isDrawGetUI);

		// �L�����N�^�[�X�V
		player->Update(*enemy);	// �v���C���[

		// �J�����X�V
		camera->Update(*player);

		// �I�u�W�F�N�g�X�V
		skyDome->Update();		// �w�i
		room->Update();			// ����
		for (int i = 0; i < gem.size(); i++)
		{
			gem[i]->Update(calculation);	// ���
			treasureChest->Update(*gem[i]);	// �󔠍X�V
		}

		// ���ʊ֌W�X�V
		//effekseer1->Update();

		// �������Ԃ��o�߂�����
		if (nowTimer >= 90)
		{
			// �N���A����
			isClearFlag = true;

			// �N���A���Ă���̃J�E���g
			isClearCount++;

			if (isClearCount >= 100)
			{
				gameState = STATE_CLEAR;
				ChangeGameState();
			}
		}

		break;

		// �N���A /////////////////////////////////////////
	case STATE_CLEAR:

		// �L�[���͂��ꂽ��
		if (keyRelease)
		{
			gameState = STATE_MENU;
			ChangeGameState();
		}
		break;

		// �Q�[���I�[�o�[ ///////////////////////////////
	case STATE_GAMEOVER:

		// �L�[���͂��ꂽ��
		if (keyRelease)
		{
			gameState = STATE_MENU;
			ChangeGameState();
		}
		break;

	default:
		break;
	}
}


/// <summary>
/// �Q�[���i�s�ɂ������L�[����
/// </summary>
void Game::ProcessKey()
{
	// �L�[�𗣂����u�Ԃ��Ƃ�
	if (keyOn)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 0)
		{
			keyOn = false;
			keyRelease = true;
		}
	}
	else if (prevKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		keyRelease = false;
		keyOn = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		prevKeyOn = true;
	}
	else
	{
		prevKeyOn = false;
	}

}

/// <summary>
/// �������Ԃ̕`��
/// </summary>
void Game::DrawTimer()
{
	// �t�H���g�T�C�Y�ݒ�
	SetFontSize(100);

	// �F�ێ�
	int _color = GetColor(200, 200, 200);

	// ���Ԃ�ێ�����
	timer = (GetNowHiPerformanceCount() - previousTime);
	int _nowTimer = (timer % 1000000000) / 1000000;				// �ꌅ�̕b��
	nowTimer = (timer % 1000000000) / 1000000;
	char timerStr[256];
	sprintf_s(timerStr, "TIME: %d / 90", _nowTimer);
	DrawString(850, 0, timerStr, _color, true);
	nowTimer = _nowTimer;

	// 20�b�o�߂��Ƃ�(_nowTimer���O�ł͂Ȃ��Ƃ��B�J�n����̎��͖���)
	if (_nowTimer % 20 == 0 && _nowTimer != 0)
	{
		char _timeCount[256];
		sprintf_s(_timeCount, "�`�`�`%d�b�o�߁`�`�`", _nowTimer);
		DrawString(250, 400, _timeCount, GetColor(255, 100, 100), true);
	}
}


/// <summary>
/// �Q�[���̕`��
/// </summary>
void Game::DrawGame()
{
	if (gameState == STATE_MENU)
	{

	}
	if (gameState == STATE_GAME)
	{
		//skyDome->Draw();
		player->Draw(gameFrameCount);			// �v���C���[
		room->Draw();							// ����
		for (int i = 0; i < gem.size(); i++)	// ���
		{
			gem[i]->Draw();
		}
		treasureChest->Draw();					// ��
		//DrawTimer();							// ��������
	}

	// UI�`��
	ui->Draw(GetGameState(), *player, isDrawGetUI, *treasureChest);

	// �G�t�F�N�g�̍Đ�
	//effekseer1->Draw();
}



