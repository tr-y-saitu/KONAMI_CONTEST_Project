#pragma once


class Effekseer1
{
public:
	Effekseer1();
	~Effekseer1();
	void ReadyEffekseerForDXLib();	// �G�t�F�N�V�A���g������
	void Initialize();
	void Update();
	void Draw();
	int		effectResourceHandle;		// �G�t�F�N�g���\�[�X
	int		graphBackGroundHandle;		// �w�i�摜
	int		graphFrontHandle;			// ��O�摜
	int		time;						// ����I�ɃG�t�F�N�g���Đ����鎞��
	bool	isFullScreen;				// �t���X�N���[���؂�ւ��悤�t���O
	VECTOR	pos;						// �G�t�F�N�g��`�悷��ʒu
	int		playingEffectHandle;		// �Đ����̃G�t�F�N�g�n���h��

private:



};

