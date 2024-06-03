#pragma once
#include "DxLib.h"

class BG
{
public:
	BG();
	~BG();

	void Initialize(int graph, int index);	// 初期化
	void Update(float buf);		// 更新
	void Draw();		// 描画

private:
	// 定数
	const float BG_SCROLL_SPEED = 5.0f;

	int		graphHandle;		// 背景スクロール用画像
	VECTOR	pos;				// ポジション
	int		w;					// 幅
	int		h;					// 高さ

};

