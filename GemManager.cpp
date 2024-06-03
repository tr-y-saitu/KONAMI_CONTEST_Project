#include "DxLib.h"
#include "GemManager.h"

// �R���X�g���N�^
GemManager::GemManager()
	: modelHandleDiamond	(-1)
	, modelHandleRuby		(-1)
	, modelHandleSapphire	(-1)
	, modelHandleEmerald	(-1)
{

}

// �f�X�g���N�^
GemManager::~GemManager()
{

}


// ���f���̃��[�h
void GemManager::LoadModle()
{
	// ��΂̃��f�������[�h
	if (modelHandleDiamond <= -1)
	{	// �_�C�A�����h
		modelHandleDiamond	= MV1LoadModel("data/model/Gem/Diamonds.mv1");
	}
	if (modelHandleRuby <= -1)
	{	// ���r�[
		modelHandleRuby		= MV1LoadModel("data/model/Gem/Ruby.mv1");
	}
	if (modelHandleSapphire <= -1)
	{	// �T�t�@�C�A
		modelHandleSapphire = MV1LoadModel("data/model/Gem/Sapphire.mv1");
	}
	if (modelHandleEmerald <= -1)
	{	// �G�������h
		modelHandleEmerald	= MV1LoadModel("data/model/Gem/Emerald.mv1");
	}

}

/// <summary>
/// �^�C�v��������ă��f���n���h����ݒ�
/// </summary>
/// <param name="type">��΂̃^�C�v</param>
/// <returns>���̃^�C�v�̃��f���n���h��</returns>
int GemManager::SettingGemModle(int type)
{
	// ���̃^�C�v�̃��f���n���h��
	int reTypeModelHandle = -1;

	// ���(�^�C�v)�̔���
	switch (type)
	{
	// �_�C�A�����h
	case DIAMOND:	
		reTypeModelHandle = modelHandleDiamond;
		break;

	// ���r�[
	case RUBY:		
		reTypeModelHandle = modelHandleRuby;
		break;

	// �T�t�@�C�A
	case SAPPHIRE:	
		reTypeModelHandle = modelHandleSapphire;
		break;

	// �G�������h
	case EMERALD:	
		reTypeModelHandle = modelHandleEmerald;
		break;

	// ����ȊO
	default:
		break;
	}
	
	// ���̃^�C�v�̃��f���n���h����Ԃ�
	return reTypeModelHandle;
}








