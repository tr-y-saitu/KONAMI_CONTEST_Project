#include"BG.h"

BG::BG()
	:graphHandle	(-1)
	,w				(0)
	,h				(0)
{
	// �����Ȃ�
}

BG::~BG()
{
	// �����Ȃ�
}




void BG::Initialize(int graph, int index)
{
	// �摜�����[�h
	graphHandle = graph;

	// �摜�T�C�Y�̓ǂݎ��
	GetGraphSize(graphHandle, &w, &h);

	// ���W�̐ݒ�
	pos.x = index * w;
	pos.y = h * 0.5f;
}

void BG::Update(float buf)
{
	pos.y = 960;

	// �w�i���X�N���[��
	pos.x -= BG_SCROLL_SPEED + buf;

	// �w�i��X���W���w�i�̈�]�v�ɍ��ɂȂ�����A�E�Ɉړ�
	if (pos.x < -w + w * 0.5f)
	{
		pos.x += w * 2;
	}
}

void BG::Draw()
{
	DrawRotaGraph(pos.x, pos.y, 1, 0, graphHandle, true);

}



