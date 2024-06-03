#include "Calculation.h"
#include "GemManager.h"
#include "Gem.h"




/// <summary>
/// コンストラクタ
/// </summary>
Gem::Gem()
	: modelHandle			(-1)
	, visibleFlag			(false)
	, width					(0)
	, height				(0)
	, speed					(0)
	, radius				(0.5f)
	, isHitPlayer			(false)
	, isHitGround			(false)
	, previousIsHitPlayer	(false)
	, boundPower			(0)
	, fallSpeed				(0)
	, rotateCount			(0)
	, gemType				(0)
	, scaleAdjust			(0.02f)
{
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
	contactDir = VGet(0, 0, 0);
	scale = VGet(0.02f, 0.02f, 0.02f);
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
/// タイプごとの移動アルゴリズムの設定
/// </summary>
/// <param name="gemTyep">宝石の種類</param>
/// <returns>そのタイプの移動方向</returns>
VECTOR Gem::SettingMoveType(int gemTyep)
{
	// 返り値用方向
	VECTOR reDir = VGet(0, 0, 0);

	// 宝石のタイプを受けて方向を設定
	switch (gemType)
	{
		// ダイアモンド
	case GemManager::DIAMOND:
		reDir = VGet(0.3f, 0.7f, 0.0f);	// 斜め右
		break;

		// ルビー
	case GemManager::RUBY:
		reDir = VGet(0.5f, 1.0f, 0.0f);	// 斜め右（上強め）
		break;
		
		// サファイア
	case GemManager::SAPPHIRE:
		reDir = VGet(0.2f, 1.0f, 0.0f);	// 斜め右(右弱め)
		break;
		
		// エメラルド
	case GemManager::EMERALD:
		reDir = VGet(1.0f, 0.1f, 0.0f);	// 斜め右(右強め)
		break;

		// その他
	default:
		break;
	}

	// そのタイプの方向を返す
	return reDir;
}


/// <summary>
/// 宝石のタイプ別で落下速度を設定
/// </summary>
/// <param name="gemType">宝石のタイプ</param>
/// <returns>落下速度</returns>
float Gem::SettingFallSpeedType(int gemType)
{
	// 返り値
	float reFallSpeed = 0;
	
	// タイプ別に落下速度を設定
	switch (gemType)
	{
		// ダイアモンド
	case GemManager::DIAMOND:
		fallSpeed = 0.05f;
		break;

		// ルビー
	case GemManager::RUBY:
		fallSpeed = 0.001f;
		break;

		// サファイア
	case GemManager::SAPPHIRE:
		fallSpeed = 0.001f;
		break;

		// エメラルド
	case GemManager::EMERALD:
		fallSpeed = 0.01f;
		break;

		// その他
	default:	
		break;
	}

	// 設定した落下速度
	return reFallSpeed;
}

/// <summary>
/// 初期化
/// </summary>
void Gem::Initialize(VECTOR initPos, GemManager gemManager)
{
	// 3Dモデル設定
	gemType = GetRand(3);					// 宝石の種類を乱数で設定
	// ベースのモデルの情報をもとにモデルをロード
	modelHandle = MV1DuplicateModel(gemManager.SettingGemModle(gemType));	

	// ステータス情報
	pos = initPos;							// 座標を引数で設定
	dir = VGet(0, 0, 0);					// 方向の設定
	contactDir = SettingMoveType(gemType);	// 宝石のタイプのプレイヤーと当たった時の方向を設定
	radius = 0.1;							// 球型のあたり判定の半径
	boundPower = 1.5f;						// バウンドする値
	fallSpeed = SettingFallSpeedType(gemType);	// 落下速度をタイプごとに設定
	MV1SetScale(modelHandle, scale);		// スケールの設定
	scaleAdjust = 0.02f;					// スケールの調整用
	rotateCount = 0;						// 回転率

	// フラグ
	isHitPlayer = false;		// プレイヤーと接触したか
	visibleFlag = true;			// 存在しているか
	isHitGround = false;		// 地上と接触したか
	previousIsHitPlayer = false;// 前のフレームでプレイヤーと接触したか
	isHitPlayer = false;		// プレイヤーと接触中か
}

/// <summary>
/// 更新
/// </summary>
/// <param name="cal">計算クラス</param>
void Gem::Update(Calculation& cal)
{
	// 少しずつ回転１フレームずつ1度回転する
	if (rotateCount <= 360)
	{
		rotateCount++;
	}
	if (rotateCount >= 360)
	{
		rotateCount = 0;
	}
	// 少しずつ回転する
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, rotateCount * DX_PI_F / 180.0f, 0.0f));

	

	///////////////////////////////////////////////////////////////
	// 重力処理 ////////////////////////////////////////////
	// 落下速度に重力を加算
	fallSpeed -= GRAVITY_POWER;
	
	//// 地面についていない時に作動
	//if (isHitGround == false)
	//{
	//	// 重力を落下速度に加算する
	//	fallSpeed = -JUMP_POWER;
	//}

	// 床より下には落ちない
	if (pos.y <= 0.1 && isHitGround == false)
	{
		pos.y = 0.1;				// 座標を地面に固定
		isHitGround = true;		// 地面についている状態
		visibleFlag = false;	// 存在を消す
		
	}

	///////////////////////////////////////////////////////////////
	// バウンド処理 ////////////////////////////////////////////
	// 床についたら跳ねる
	if (isHitGround == true)
	{
		pos.y = 0.1;
		// 重力に逆らう（これやらないと地面貫通する）
		fallSpeed += GRAVITY_POWER * 1.2f;
		//dir = VAdd(dir, VGet(0, 1, 0));
		//isHitGround = false;
		scaleAdjust -= 0.0005f;		// 少しづつスケールを小さくする
		// スケールを設定
		MV1SetScale(modelHandle, VGet(scaleAdjust, scaleAdjust, scaleAdjust));
	}
	// スケールがゼロ以下になったら修正
	if (scaleAdjust <= 0)
	{
		scaleAdjust = 0;
	}
	
	// バウンドさせるならコメントはずせ
	//// 線形補間でバウンドする値を決める
	//boundPower= cal.Lerp_F(boundPower, 0.0f, 0.01);
	//if (pos.y >= boundPower)	// 地面よりも上なら
	//{
	//	// バウンドが細かすぎたらなくす
	//	if (boundPower <= 0.3)
	//	{
	//		boundPower = 0;
	//	}
	//	isHitGround = false;
	//}
	
	// プレイヤーと接触したら
	if (isHitPlayer)
	{
		fallSpeed = +JUMP_POWER;
		dir = VAdd(dir, contactDir);	// 宝石ごとに違う方向
		isHitGround = false;
		isHitPlayer = false;
	}

	// 移動処理 /////////////////////////////////////////////////////
	
	// 正規化
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}
	// 方向設定処理 ///////////////////////////////////////////////////
	
	// 移動量を出す
	auto velocity = VScale(dir, MOVE_SPEED);

	// 方向の正規化
	/*if (VSize(velocity) != 0)
	{
		dir = VNorm(dir);
	}*/

	
	// 落下速度を移動量に加える
	auto fallVelocity = VGet(0, fallSpeed, 0);
	velocity = VAdd(velocity, fallVelocity);

	// ポジションの更新
	pos = VAdd(pos, velocity);


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