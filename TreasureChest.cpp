#include "DxLib.h"
#include "Gem.h"
#include "TreasureChest.h"

// コンストラクタ
TreasureChest::TreasureChest()
	: modelHanlde		(-1)
	, width				(0)
	, height			(0)
	, isHitGem			(false)
	, radius			(0)
{
	modelHanlde = MV1LoadModel("data/model/TreasureChest/TreasureChest.mv1");
	pos = VGet(7, 0, 0);
	scale = VGet(0.005f, 0.005f, 0.005f);
	// モデルの回転(違和感ない位置に修正)
	MV1SetRotationXYZ(modelHanlde, VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
}

// デストラクタ
TreasureChest::~TreasureChest()
{
	// モデルハンドルの削除
	MV1DeleteModel(modelHanlde);
}

// 初期化
void TreasureChest::Initialize()
{
	pos = VGet(7, 0, -5);
	// スケールの設定
	MV1SetScale(modelHanlde, scale);
	radius = 3.0f;
}

// 更新
void TreasureChest::Update(Gem& gem)
{
	// 3Dモデルの座標設定
	MV1SetPosition(modelHanlde, pos);
}

// 描画
void TreasureChest::Draw()
{
	// 3Dモデルの描画
	MV1DrawModel(modelHanlde);

	// 球型の当たり判定の描画
	DrawSphere3D(pos, radius, 32, GetColor(0, 0, 255), GetColor(255, 255, 255), false);
}


