#include "Room.h"


/// <summary>
/// コンストラクタ
/// </summary>
Room::Room()
	:	modelHandle		(0)
	,	w				(0)
	,	h				(0)
	,	speed			(0)
	,	r				(0)
{
	modelHandle = MV1LoadModel("data/model/Room/RoomFloorModel.mv1");
	scale = VGet(0.02f ,0.02f, 0.02f);
	// スケールの設定
	MV1SetScale(modelHandle, scale);
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
}

/// <summary>
/// デストラクタ
/// </summary>
Room::~Room()
{
	// モデルのアンロード
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void Room::Initialize()
{
	pos = VGet(6, 0, 9);		// 座標のセット
	dir = VGet(0, 0, 0);		// 方向のセット

}



/// <summary>
/// 更新
/// </summary>
void Room::Update()
{
	// 3Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

}


/// <summary>
/// 描画
/// </summary>
void Room::Draw()
{
	// 3Dモデルの描画
	MV1DrawModel(modelHandle);
}