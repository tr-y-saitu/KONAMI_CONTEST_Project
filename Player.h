#define _PLAYER_H_

#include "DxLib.h"

class Game;
class Enemy;

/// <summary>
/// プレイヤークラス
/// </summary>
class Player final
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Initialize();				// 初期化
	void Update(Enemy& enemy);		// 更新
	void Draw(int gameFrameCount);	// 描画

	// モデルハンドルの取得.
	int GetModelHandle(){ return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const int GetWidth() { return w; }
	const int GetHeight() { return h; }
	const bool GetIsHitEnemy(){ return isHitEnemy; }
	const bool GetIsGreatJump() { return isGreatJump; }
	const float GetRadius() { return r; }
	const bool GetIsHitGem() { return isHitGem; }

	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitEnemy(const bool set) { isHitEnemy = set; }
	void SetGraetJump(const bool set) { isGreatJump = set; }
	void SetIsHitGem(const bool set) { isHitGem = set; }
	

	int		greatJumpCount;	// 描画時間
private:
	// 定数
	const float GRAVITY = 0.5f;			// キャラに掛かる重力加速度
	const float JUMP_POWER = 25.0f;		// キャラのジャンプ力
	const float SMALL_JUMP_POWER = 17.0f;	// 小ジャンプ力
	const float SPEED = 0.1f;			// キャラの移動スピード
	const int	MOVE_LIMIT_Y = 820;		// キャラのY座標の移動制限
	const int	MOVE_LIMIT_X = 1600;

	// 変数
	// ハンドル
	int		graphHandle;	// 2D画像ハンドル
	int		modelHandle;	// モデルハンドル
	int		divGraphHandle[16];	// 分割画像ハンドル
	int		animeIndex;		// 画像の添え字
	int		moveFrameCount;	// 添え字を変更するためにカウントする
	// 情報
	VECTOR	pos;			// ポジション.
	VECTOR	dir;			// 方向
	VECTOR	scale;			// スケール
	int		w;				// 幅
	int		h;				// 高さ
	float	fallSpeed;		// 落下速度
	float	speed;			// 移動スピード
	// フラグ
	bool	isGround;		// プレイヤーが接地中か
	bool	isHitTop;		// プレイヤーの頭が天井に当たっているか
	bool	isGreatJump;	// ジャンプが成功したか
	// 当たり判定
	float		r;			// 球型当たり判定の半径
	bool	isHitEnemy;		// エネミーと接触したか
	bool	isHitGem;		// ジェムと接触したか
};

