#pragma once

#include "DxLib.h"

class BGObj
{
public:
	static const int INIT_SCALE = 0.5f;

	// メンバメソッド
	BGObj();			// コンストラクタ
	~BGObj();			// デストラクタ
	void Initialize(int graph,int texture,VECTOR initVec,int speed);	// 初期化
	void Update();		// 更新
	void Draw();		// 描画
	
	// モデルハンドルの取得
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
	void SetPos(const VECTOR set) { pos = set; }
	void SetReturnPosX(const int set) { returnPosX = set; }
	void SetScrollSpeed(const int set) { scrollSpeed = set; }
	void SetScale(const VECTOR set) { scale = set; }

private:
	// 定数
	const float SPEED = 5.0f;

	int		modelHandle;	// モデルハンドル
	int		texrureHandle;	// テクスチャハンドル
	VECTOR	pos;			// ポジション
	VECTOR	pos2;			
	VECTOR	dir;			// 方向
	MATRIX	matrix;			// 行列（回転で使用）
	int		w;				// 幅
	int		h;				// 高さ
	VECTOR	scale;			// スケールサイズ

	int		returnPosX;		// 位置を戻すタイミング
	int		scrollSpeed;	// 画面スクロールする速度

	int		graphHandle;	// 背景画像ハンドル
	int		graphUniverse;	// 宇宙画像ハンドル

};







