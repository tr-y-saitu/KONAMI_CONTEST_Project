#pragma once
#include "DxLib.h"
#include "GemManager.h"

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

    /// <summary>
    /// 宝石のタイプごとの移動アルゴリズムの設定
    /// </summary>
    /// <param name="gemTyep">宝石の種類</param>
    /// <returns>そのタイプの移動方向</returns>
	VECTOR SettingMoveType(int gemType);

    /// <summary>
    /// 宝石のタイプ別で落下速度を設定
    /// </summary>
    /// <param name="gemType">宝石のタイプ</param>
    /// <returns>落下速度</returns>
    float SettingFallSpeedType(int gemType);

    /// <summary>
    /// 宝石の初期化
    /// </summary>
    /// <param name="initPos">初期座標</param>
    /// <param name="gemManager">宝石管理クラス</param>
    void Initialize(VECTOR initPos,GemManager gemManager);

    /// <summary>
    /// 宝石の更新
    /// </summary>
    /// <param name="cal">計算クラス</param>
    /// <param name="nowTimer">現在の経過時間</param>
    void Update(Calculation& cal,float nowTimer);

    /// <summary>
    /// 宝石の２次元での当たり判定を3D空間上で表示
    /// </summary>
    void Draw2DBOXCollision();

	/// <summary>
	/// 宝石の描画
	/// </summary>
	void Draw();

	// ポジションのgetter/setter.
	int GetModelHandle() const { return modelHandle; }
	const VECTOR& GetPos() const { return pos; }
	const float GetWidth() const{ return width; }
	const float GetHeight() const { return height; }
	const bool GetVisibleFlag() const { return visibleFlag; }
	const bool GetIsHitPlayer() const { return isHitPlayer; }
	const bool GetIsHitGround() const { return isHitGround; }
	const bool GetIsHitChest() const { return isHitTreasureChest; }
	const float GetRadius() const { return radius; }
	const float GetEntyrTime()const { return entryTime; }
    const int GetGemType()const { return gemType; }

	// setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitPlayer(const bool set) { isHitPlayer = set; }
	void SetIsHitGround(const bool set) { isHitGround = set; }
	void SetIsHitChest(const bool set) { isHitTreasureChest = set; }
	void SetEntryTime(const float set) { entryTime = set; }
	void SetEntryPosition(const VECTOR set) { entryPosition = set; }
    void SetVisibleFlag(const bool set) { visibleFlag = set; }
    void SetDirection(const VECTOR set) { dir = set; }

private:
	// 定数
	const float GRAVITY_POWER = 0.002f;		// 宝石にかかる重力の値
	const float GRAVITY_POWER_LIMIT = 0.3f;// 宝石にかかる重力の限界値
	const float MOVE_SPEED = 0.15f;			// 移動速度
	const float JUMP_POWER = 0.1f;			// プレイヤーに当たった時のジャンプ量

	// 変数

	// モデル関係
	int		modelHandle;	// モデルハンドル
    int     collisionGraph; // 当たり判定の２次元画像

	// ステータス
	int		gemType;		// 宝石の種類(ダイア,ルビー,サファイア,エメラルド)
	VECTOR	pos;			// ポジション
	VECTOR	dir;			// 方向
	VECTOR	contactDir;		// 接触時の方向
	float	width;			// 幅
	float	height;			// 高さ
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

	// エントリー情報
	float	entryTime;			// 登場する時間
	VECTOR	entryPosition;		// 登場する位置
};

