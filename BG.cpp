#include"BG.h"

BG::BG()
	:graphHandle	(-1)
	,w				(0)
	,h				(0)
{
	// 処理なし
}

BG::~BG()
{
	// 処理なし
}




void BG::Initialize(int graph, int index)
{
	// 画像をロード
	graphHandle = graph;

	// 画像サイズの読み取り
	GetGraphSize(graphHandle, &w, &h);

	// 座標の設定
	pos.x = index * w;
	pos.y = h * 0.5f;
}

void BG::Update(float buf)
{
	pos.y = 960;

	// 背景横スクロール
	pos.x -= BG_SCROLL_SPEED + buf;

	// 背景のX座標が背景の一つ余計に左になったら、右に移動
	if (pos.x < -w + w * 0.5f)
	{
		pos.x += w * 2;
	}
}

void BG::Draw()
{
	DrawRotaGraph(pos.x, pos.y, 1, 0, graphHandle, true);

}



