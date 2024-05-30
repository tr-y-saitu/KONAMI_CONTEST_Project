#include "Calculation.h"
#include "Gem.h"



/// <summary>
/// コンストラクタ
/// </summary>
Gem::Gem()
	: modelHandle			(0)
	, width					(0)
	, height				(0)
	, speed					(0)
	, radius				(0.5f)
	, isHitPlayer			(false)
	, isHitGround			(false)
	, previousIsHitPlayer	(false)
	, boundPower			(0)
{
	modelHandle = MV1LoadModel("data/model/Gem/GemRed.mv1");
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
	scale = VGet(1,1,1);
}

/// <summary>
/// デストラクタ
/// </summary>
Gem::~Gem()
{
	// 3Dモデルの削除
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void Gem::Initialize(VECTOR initPos)
{
	pos = initPos;
	//pos = VGet(0, 0, 0);		// 座標の設定
	//dir = VGet(0, 0, 0);		// 方向の設定
	dir = VGet(0, 0, 0);		// 方向の設定
	isHitPlayer = false;		// プレイヤーと接触したか
	visibleFlag = true;			// 存在しているか
	radius = 0.1;				// 球型のあたり判定の半径
	isHitGround = false;		// 地上と接触したか
	previousIsHitPlayer = false;// 前のフレームでプレイヤーと接触したか
	isHitPlayer = false;		// プレイヤーと接触中か
	boundPower = 1.5f;			// バウンドする値
}

/// <summary>
/// 更新
/// </summary>
/// <param name="cal">計算クラス</param>
void Gem::Update(Calculation& cal)
{

	// 移動処理 ///////////////////////////////////////////////////
	// 方向を設定
	//dir = VGet(0.0f, 0.0f, 0.0f);

	// 正規化
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}

	// 移動量を出す
	auto velocity = VScale(dir, MOVE_SPEED);

	// 移動
	pos = VAdd(pos, velocity);

	// 方向調整
	/*if (VSize(velocity) != 0)
	{
		dir = VNorm(dir);
	}*/
	///////////////////////////////////////////////////////////////
	// 重力処理 ////////////////////////////////////////////
	// 地面についていない時に作動
	if (isHitGround == false)
	{
		pos.y -= GRAVITY_POWER;
	}

	// 床より下には落ちない
	if (pos.y <= 0 && isHitGround == false)
	{
		pos.y = 0;
		isHitGround = true;
	}
	///////////////////////////////////////////////////////////////
	// バウンド処理 ////////////////////////////////////////////
	// 床についたら跳ねる
	if (isHitGround == true)
	{
		dir.y = 1;
		//isHitGround = false;
	}
	// 線形補間でバウンドする値を決める
	boundPower= cal.Lerp_F(boundPower, 0.0f, 0.01);
	if (pos.y >= boundPower)
	{
		// バウンドが細かすぎたらなくす
		if (boundPower <= 0.3)
		{
			boundPower = 0;
		}
		isHitGround = false;
	}
	
	// プレイヤーと接触したら
	if (isHitPlayer)
	{
		dir = VGet(1000.0f, 5000.0f, 0.0f);
		isHitGround = false;
	}

	/////////////////////////////////////////////////////////////////
	
	// 3Dモデルの座標設定
	MV1SetPosition(modelHandle, pos);
}

/// <summary>
/// 描画
/// </summary>
void Gem::Draw()
{
	// 3Dモデルの描画
	MV1DrawModel(modelHandle);

	// 球型の当たり判定の描画
	DrawSphere3D(pos, radius, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);

	// プレイヤーと接触したら
	if (isHitPlayer)
	{
		DrawFormatString(100, 100, GetColor(255, 255, 255), "Gem Hit", true);
	}
}