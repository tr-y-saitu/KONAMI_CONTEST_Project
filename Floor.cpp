#include "Floor.h"

/// <summary>
/// コンストラクタ
/// </summary>
Floor::Floor()
	:	modelHandle		(0)
	,	w				(0)
	,	h				(0)
	,	speed			(0)
	,	r				(0)
{
	// モデルの読み込み
	modelHandle = MV1LoadModel("data/model/Room/RoomFloorModel.mv1");
	// スケールの設定
	scale = VGet(0.01f, 0.01f, 0.01f);
	MV1SetScale(modelHandle, scale);
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
}


/// <summary>
/// デストラクタ
/// </summary>
Floor::~Floor()
{
	// モデルハンドルの削除
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void Floor::Initialize(VECTOR initPos)
{
	// initPos
	// 床にタイルを並べるために初期座標を引数でもらう

	// ポジションの初期化
	// ここで床を並べる
	pos = initPos;
	dir = VGet(0, 0, 0);
}

/// <summary>
/// 更新
/// </summary>
void Floor::Update()
{
	// 3Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);
}

/// <summary>
/// 描画
/// </summary>
void Floor::Draw()
{
	// 3Dモデルの描画
	MV1DrawModel(modelHandle);
}


