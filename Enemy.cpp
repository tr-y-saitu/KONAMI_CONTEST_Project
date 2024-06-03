// エネミークラス

#include "Enemy.h"

Enemy::Enemy()
	:	speedBuf		(0)
	,	modelHandle		(0)
	,	visibleFlag		(false)
	,	sizeBuf			(0.0)
	,	w				(0)
	,	h				(0)
	,	graphSize		(1)
	,	r				(2)
{
	// モデルハンドルの設定
	modelHandle = MV1LoadModel("data/model/enemy/KillerModel1.mv1");
	// ポジションの設定
	pos = VGet(0, 0, 0);
	// 方向の設定
	dir = VGet(0, 0, 0);
	// サイズの調整
	scale = VGet(0.05f, 0.05f, 0.05f);
	MV1SetScale(modelHandle, scale);


}

// デストラクタ
Enemy::~Enemy()
{
	// モデルのアンロード

}

/// <summary>
/// 初期化
/// </summary>
void Enemy::Initialize()
{
	// ポジションの設定
	pos = VGet(0, 0, 0);

	// 方向の設定
	dir = VGet(0, 0, 0);
	
	// サイズを得る
	GetGraphSize(graphHandle, &w, &h);

	
	visibleFlag = true;
	speedBuf = 0;
	graphSize = 1;
	sizeBuf = 0;
}


// エネミーの更新
void Enemy::Update(int timer)
{
	// 座標を設定
	//pos = VGet(20, 10, 20);

	// 右から左に移動
	dir = VGet(0, 0, 0);

	// 正規化
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}

	auto velocity = VScale(dir, SPEED );

	// 実移動
	pos = VAdd(pos, velocity);

	// 3Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

}


// エネミーの描画
void Enemy::Draw()
{
	// エネミーの描画
	MV1DrawModel(modelHandle);

	// エネミーの当たり判定を描画
	DrawSphere3D(pos, r, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);
}






