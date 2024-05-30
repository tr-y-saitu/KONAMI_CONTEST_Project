#pragma once

#include "DxLib.h"

class Calculation;


/// <summary>
/// 宝石（ジェム）
/// </summary>
class Gem
{
public:
	Gem();
	~Gem();

	// メソッド
	void Initialize(VECTOR initPos);		// 初期化
	void Update(Calculation& cal);	// 更新.
	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const bool GetVisibleFlag() { return visibleFlag; }
	const int GetWidth() { return width; }
	const int GetHeight() { return height; }
	const float GetRadius() { return radius; }
	const bool GetIsHitPlayer() { return isHitPlayer; }
	const bool GetIsHitGround() { return isHitGround; }
	// setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitPlayer(const bool set) { isHitPlayer = set; }
	void SetIsHitGround(const bool set) { isHitGround = set; }

private:
	// 定数
	const float GRAVITY_POWER = 0.1f;		// 宝石にかかる重力の値
	const float MOVE_SPEED = 0.05f;			// 移動速度

	// 変数
	int		modelHandle;	// モデルハンドル
	VECTOR	pos;			// ポジション.
	VECTOR	dir;			// 方向
	int		width;			// 幅
	int		height;			// 高さ
	VECTOR	scale;			// スケール
	float	speed;			// 移動スピード
	float	radius;			// 球型当たり判定の半径
	bool	visibleFlag;	// 存在しているか
	bool	isHitPlayer;	// プレイヤーと接触中か
	bool	previousIsHitPlayer;	// 前のフレームでプレイヤーと接触していたか
	bool	isHitGround;	// 床と接触したか
	float	boundPower;		// バウンドする値
};

