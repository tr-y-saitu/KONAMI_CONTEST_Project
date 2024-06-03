#pragma once

#include "DxLib.h"


class Confetti
{
public:
	// メソッド
	Confetti();		// コンストラクタ
	~Confetti();	// デストラクタ
	void Initialize(int model,VECTOR initVec, int initSpeed,int initType);	// 初期化
	void Update(int index);		// 更新
	void Draw();		// 描画
	// ゲットセット
	void SetPos(const VECTOR set) { pos = set; }
	const VECTOR& GetPos()const { return pos; }

private:
	int		modelHandle;	// モデルハンドル
	VECTOR	pos;			// ポジション
	VECTOR	dir;			// 方向
	int		w;				// 幅
	int		h;				// 高さ
	int		retrunPosY;		// 移動して初期位置に戻す座標
	int		speed;			// スピード
	int		radian;			// ラジアン角度
	int		colorType;		// カラータイプ
	int		rotateType;		// 回転タイプ
};