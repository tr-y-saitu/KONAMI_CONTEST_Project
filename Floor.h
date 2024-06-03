#pragma once

#include "DxLib.h"

/// <summary>
/// 床
/// </summary>
class Floor
{
public:
	Floor();
	~Floor();

	// メソッド
	void Initialize(VECTOR initPos);		// 初期化
	void Update();			// 更新.
	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() const { return w; }
	const int GetHeight() const { return h; }
	void SetPos(const VECTOR set) { pos = set; }


private:
	int		modelHandle;	// モデルハンドル
	VECTOR	pos;			// ポジション.
	VECTOR	dir;			// 方向
	int		w;				// 幅
	int		h;				// 高さ
	VECTOR	scale;			// スケール
	float	speed;			// 移動スピード
	int		r;				// 球型当たり判定の半径
};

