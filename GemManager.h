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

	// ��΂��o�ꂷ��f�[�^
	struct EntryGemDataBase
	{
		int entryFrameCount;		// �o�ꂷ��t���[����
		VECTOR entryPosition;		// �o�ꂷ��ʒu
	};

	// ���\�b�h
	GemManager();
	virtual ~GemManager();

	/// <summary>
	/// ��΃��f���̃n���h�������[�h
	/// </summary>
	void LoadModle();

	/// <summary>
	/// ��΂̃��f����ݒ�
	/// </summary>
	/// <param name="type">��΂̎��</param>
	/// <returns>���̎�ނ̃��f���n���h��</returns>
	int SettingGemModle(int type);

	/// <summary>
/// ��΂̃G���g���[����ݒ�
/// </summary>
/// <param name="data">��΂̃G���g���[�����i�[���鑽�����z��</param>
/// <param name="size">�������z��̓Y������</param>
	void SettingEntryData(EntryGemDataBase data[], int size);

	// ��΂̃x�[�X���f���n���h��
	int modelHandleDiamond;		// �_�C�A�����h
	int modelHandleRuby;		// ���r�[
	int modelHandleSapphire;	// �T�t�@�C�A
	int	modelHandleEmerald;		// �G�������h

	
	// ���ۂ̃f�[�^
	EntryGemDataBase entryGemDataBase[100];

private:

};

