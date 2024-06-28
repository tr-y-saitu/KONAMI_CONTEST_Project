//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Player.h"
#include "Enemy.h"
#include "EffectManager.h"
#include "Game.h"
#include "PlayerOar.h"
#include "PlayerBoat.h"
#include "PlayerCuhion.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
	:	isGreatJump		(false)
	,	greatJumpCount	(0)
	,	isGround		(false)
	,	isHitEnemy		(false)
	,	isHitTop		(false)
	,	isHitGem		(false)
	,	speed			(5)
	,	r				(1)
    ,   width           (4.5f)
    ,   height          (1.0f)
    ,   collisionGraph  (-1)
{
    effectManager = EffectManager::GetInstance();
	// ３Ｄモデルの読み込み
	modelHandle = MV1LoadModel("data/model/player/trampoline.mv1");
    collisionGraph = LoadGraph("data/texture/Debug/TestHitGraph100x100Red.png");
    pos = VGet(0, 50, 0);
	dir = VGet(0,0,0);
	fallSpeed = 0.0f;
	animeIndex = 8;
	scale = VGet(0.02f, 0.02f, 0.02f);
	MV1SetScale(modelHandle, scale);
    // プレイヤー装備品
    playerOar = new PlayerOar();
    playerBoat = new PlayerBoat();
    playerCushion = new PlayerCushion();
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Player::~Player()
{
	MV1DeleteModel(modelHandle);
    delete(playerOar);
    delete(playerBoat);
    delete(playerCushion);
}

/// <summary>
/// 初期化
/// </summary>
void Player::Initialize()
{
	pos = VGet(-18, 1, -5);	// 座標のセット
	dir = VGet(0, 0, 0);	// 方向のセット
	fallSpeed = 0.0f;		// 落下速度
	isGround = false;		// 地面にいるか
	isHitTop = false;		// 頭が当たっているか
	isHitEnemy = false;		// エネミーと接触したか
	isHitGem = false;		// ジェムとの当たり判定
	isGreatJump = false;	// よいジャンプ判定
	greatJumpCount = 0;		// よいジャンプ判定されてからのカウント
	speed = 1;				// 移動スピード
}


/// <summary>
/// プレイヤーの更新
/// </summary>
/// <param name="enemy"></param>
void Player::Update()
{
	// キー入力取得
	auto input = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// 無限に移動しないように停止
	dir = VGet(0, 0, 0);

	// 方向キー入力
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		dir = VAdd(dir, VGet(0, 1, 0));
		speed = SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		dir = VAdd(dir, VGet(0, -1, 0));
		speed = SPEED;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
	{
		dir = VAdd(dir, VGet(-1, 0, 0));
		speed = SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
	{
		dir = VAdd(dir, VGet(1, 0, 0));
		speed = SPEED;
	}

	// 正規化
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}

	// 移動量を出す
	auto velocity = VScale(dir, speed);
	// 移動
	pos = VAdd(pos, velocity);

	// 方向調整
	if (VSize(velocity) != 0)
	{
		dir = VNorm(velocity);
	}

	// 移動制限
	//if (pos.y >= MOVE_LIMIT_Y)
	//{
	//	pos.y = MOVE_LIMIT_Y;
	//}
	//if (pos.y == MOVE_LIMIT_Y)
	//{
	//	isGround = true;
	//}
	//else
	//{
	//	isGround = false;
	//}
	//if (pos.x >= MOVE_LIMIT_X)
	//{
	//	pos.x = MOVE_LIMIT_X;
	//}
	//if (pos.x <= 0)
	//{
	//	pos.x = 0;
	//}

    // 宝石と接触したらエフェクト
    if (isHitGem)
    {
        effectManager->PlayPlayerHitEffect(pos);
    }

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

    // プレイヤー装備品のポジション設定
    SetPositionAssetModle();
}

/// <summary>
/// 装備品モデルの座標設定
/// </summary>
void Player::SetPositionAssetModle()
{
    playerOar->Update(pos);     // オール
    playerBoat->Update(pos);    // ボート
    playerCushion->Update(pos); // クッション
}

/// <summary>
 /// プレイヤーの当たり判定描画2DBOX
 /// </summary>
void Player::Draw2DBOXCollision()
{
    DrawBillboard3D(pos, 0.5f, 0.9f, 4.0f, 0, collisionGraph, true);
}


/// <summary>
/// プレイヤーの描画
/// </summary>
void Player::Draw()
{
    // プレイヤー
	MV1DrawModel(modelHandle);
    // プレイヤー装備品
    DrawPlayerAssetModel();
}

/// <summary>
/// プレイヤー装備品描画
/// </summary>
void Player::DrawPlayerAssetModel()
{
    playerOar->Draw();      // オール
    playerBoat->Draw();     // ボート
    playerCushion->Draw();  // クッション
}
