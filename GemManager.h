#pragma once



/// <summary>
/// ��΃}�l�[�W���[�N���X
/// </summary>
class GemManager final
{
public:
	/// <summary>
	/// ��΂̃^�C�v
	/// </summary>
	enum GemType
	{
		DIAMOND,	// �_�C�A�����h
		RUBY,		// ���r�[
		SAPPHIRE,	// �T�t�@�C�A
		EMERALD		// �G�������h
	};

	// ���\�b�h
	GemManager();
	virtual ~GemManager();
	void LoadModle();			// ��΃��f���n���h���̃��[�h
	int SettingGemModle(int type);		// ��΂̃��f����ݒ�

	// ��΂̃x�[�X���f���n���h��
	int modelHandleDiamond;		// �_�C�A�����h
	int modelHandleRuby;		// ���r�[
	int modelHandleSapphire;	// �T�t�@�C�A
	int	modelHandleEmerald;		// �G�������h

private:


};

