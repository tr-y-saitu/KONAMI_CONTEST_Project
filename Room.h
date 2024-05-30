#pragma once

#include "DxLib.h"

/// <summary>
/// 部屋
/// </summary>
class Room
{
public:
	Room();		// コンストラクタ
	~Room();	// デストラクタ

	// メソッド
	void Initialize();		// 初期化
	void Update();			// 更新.
	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
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

