#pragma once

#include "DxLib.h"

class Calculation;
class GemManager;


/// <summary>
/// 宝石（ジェム）
/// </summary>
class Gem final
{
public:
	Gem();
	virtual ~Gem();

	// メソッド
	VECTOR SettingMoveType(int gemType);	// タイプごとの移動アルゴリズムの設定
	float SettingFallSpeedType(int gemType);// タイプごとの落下速度指定
	void Initialize(VECTOR initPos,GemManager gemManager);		// 初期化
	void Update(Calculation& cal);		// 更新
	void Draw();						// 描画

	// モデルハンドルの取得.
	int GetModelHandle() const { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() const{ return width; }
	const int GetHeight() const { return height; }
	const bool GetVisibleFlag() const { return visibleFlag; }
	const bool GetIsHitPlayer() const { return isHitPlayer; }
	const bool GetIsHitGround() const { return isHitGround; }
	const bool GetIsHitChest() const { return isHitTreasureChest; }
	const float GetRadius() const { return radius; }
	
	// setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitPlayer(const bool set) { isHitPlayer = set; }
	void SetIsHitGround(const bool set) { isHitGround = set; }
	void SetIsHitChest(const bool set) { isHitTreasureChest = set; }

private:
	// 定数
	const float GRAVITY_POWER = 0.002f;		// 宝石にかかる重力の値
	const float MOVE_SPEED = 0.13f;			// 移動速度
	const float JUMP_POWER = 0.1f;			// プレイヤーに当たった時のジャンプ量

	// 変数
	// モデル関係
	int		modelHandle;	// モデルハンドル

	// ステータス
	int		gemType;		// 宝石の種類(ダイア,ルビー,サファイア,エメラルド)
	VECTOR	pos;			// ポジション
	VECTOR	dir;			// 方向
	VECTOR	contactDir;		// 接触時の方向
	int		width;			// 幅
	int		height;			// 高さ
	VECTOR	scale;			// スケール
	float	scaleAdjust;	// スケールの調整
	float	speed;			// 移動スピード
	float	radius;			// 球型当たり判定の半径
	float	fallSpeed;		// 落下速度
	float	boundPower;		// バウンドする値
	float	rotateCount;	// ゲーム中に少しづつ回転させるためのカウント

	// フラグ
	bool	visibleFlag;	// 存在しているか
	bool	isHitPlayer;	// プレイヤーと接触中か
	bool	isHitGround;	// 床と接触したか
	bool	previousIsHitPlayer;	// 前のフレームでプレイヤーと接触していたか
	bool	isHitTreasureChest;	// 宝箱と接触したか
};

