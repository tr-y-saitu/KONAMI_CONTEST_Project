#include "Player.h"
#include "Enemy.h"
#include "EffectManager.h"
#include "Game.h"
#include "PlayerOar.h"
#include "PlayerBoat.h"
#include "PlayerCuhion.h"

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
	:	isGreatJump		        (false)
	,	isGround		        (false)
	,	isHitEnemy		        (false)
	,	isHitTop		        (false)
	,	isHitGem		        (false)
	,	speed			        (5)
	,	r				        (1)
    ,   width                   (4.5f)
    ,   height                  (1.0f)
    ,   collisionGraph          (-1)
    ,   animationPlayTime       (0)
{
    effectManager = EffectManager::GetInstance();
    modelHandle = MV1LoadModel("data/model/player/SittingPlayer.mv1");
    animationAttachIndex = MV1AttachAnim(modelHandle, 0, -1, false);
    animationPlayTotalTime = MV1GetAttachAnimTotalTime(modelHandle, animationAttachIndex);
    collisionGraph = LoadGraph("data/texture/Debug/TestHitGraph100x100Red.png");
    pos = VGet(0, 50, 0);
	dir = VGet(0,0,0);
	fallSpeed = 0.0f;
	scale = VGet(0.02f, 0.02f, 0.02f);
	MV1SetScale(modelHandle, scale);
    // プレイヤー装備品
    playerOar = new PlayerOar();
    playerBoat = new PlayerBoat();
    playerCushion = new PlayerCushion();
}

/// <summary>
/// デストラクタ
/// </summary>
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
	speed = 1;				// 移動スピード
}

/// <summary>
/// プレイヤーの更新
/// </summary>
void Player::Update()
{
    // 移動
    UpdateMovement();

    // 宝石と接触したらエフェクト
    if (isHitGem)
    {
        effectManager->PlayPlayerHitEffect(pos);
    }

    // アニメーションの更新
    UpdateAnimation();

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
/// 移動更新
/// </summary>
void Player::UpdateMovement()
{
    // キー入力取得
    auto input = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // 無限に移動しないように停止
    dir = VGet(0, 0, 0);

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
    LimitingMovement();

}

/// <summary>
/// 移動制限
/// </summary>
void Player::LimitingMovement()
{
    if (pos.x >= MOVE_SIDE_LIMIT_MAX)
    {
        pos.x = MOVE_SIDE_LIMIT_MAX;
    }
    if (pos.x <= MOVE_SIDE_LIMIT_MIN)
    {
        pos.x = MOVE_SIDE_LIMIT_MIN;
    }
}

/// <summary>
/// アニメーションの更新
/// </summary>
void Player::UpdateAnimation()
{
    // 再生時間を進める
    animationPlayTime += ANIMATION_PLAYBUCK_SPEED;

    // 現在の再生時間が総再生時間に達したらゼロに戻す
    if (animationPlayTime >= animationPlayTotalTime)
    {
        animationPlayTime = 0;
    }

    // 再生時間のセット
    MV1SetAttachAnimTime(modelHandle, animationAttachIndex, animationPlayTime);
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
