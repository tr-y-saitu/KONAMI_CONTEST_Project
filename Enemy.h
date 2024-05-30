#pragma once

#include "DxLib.h"



class Enemy
{
public:
	Enemy();		// コンストラクタ
	~Enemy();		// デストラクタ

	void Initialize();		// 初期化処理
	void Update(int timer);	// 更新
	void Draw();	// 描画

	// モデルハンドルの取得
	int GetModelHandle() { return modelHandle; }

	// ゲット
	const VECTOR& GetPos()const { return pos; }
	const bool GetVisibleFlag() { return visibleFlag; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
	const int GetRudius() { return r; }
	// セット
	const float GetSpeedBuf() { return speedBuf; }
	void SetPos(const VECTOR set) { pos = set; }

private:
	// 定数
	const float SPEED = 5.0f;	// 移動スピード

	// 変数
	int		modelHandle;	// モデルハンドル
	VECTOR	scale;			// スケール
	int		graphHandle;	// 2Dモデルハンドル
	int		w;				// 幅
	int		h;				// 高さ
	VECTOR	pos;			// ポジション
	VECTOR	dir;			// 方向
	bool	visibleFlag;	// 存在しているか
	float	speedBuf;		// 移動スピードのバフ値
	double	sizeBuf;		// 画像サイズのバフ
	double	graphSize;		// 画像サイズ
	int		r;				// 球型当たり判定の半径

};

