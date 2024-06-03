#pragma once

#include "DxLib.h"


class SkyDome
{
public:
	SkyDome();
	~SkyDome();

	void Initialize();	// 初期化
	void Update();		// 更新
	void Draw();		// 描画

	// モデルハンドルの取得
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
	void SetPos(const VECTOR set) { pos = set; }



private:
	// 定数
	const float SPEED = 5.0f;

	int		modelHandle;	// モデルハンドル
	int		textureHandle;	// テクスチャハンドル
	VECTOR	pos;			// ポジション
	VECTOR	pos2;			// 回転する前のポジション
	VECTOR	dir;			// 方向
	int		w;				// 幅
	int		h;				// 高さ

};


