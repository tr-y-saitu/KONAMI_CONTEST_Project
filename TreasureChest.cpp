#include "DxLib.h"
#include "Gem.h"
#include "TreasureChest.h"
#include "EffectManager.h"

// コンストラクタ
TreasureChest::TreasureChest()
	: modelHanlde		(-1)
	, width				(5)
	, height			(5)
	, isHitGem			(false)
	, radius			(0)
    , hitGemType      (0)
{
    effectManager = EffectManager::GetInstance();
	modelHanlde = MV1LoadModel("data/model/TreasureChest/TreasureChest.mv1");
	pos = VGet(0, 0, 0);
	scale = VGet(0.007f, 0.007f, 0.007f);
	// モデルの回転(違和感ない位置に修正)
	MV1SetRotationXYZ(modelHanlde, VGet(0.0f, -50.0f * DX_PI_F / 180.0f, 0.0f));
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
	pos = VGet(5, 0, -5);
	// スケールの設定
	MV1SetScale(modelHanlde, scale);
	radius = 3.0f;
}

// 更新
void TreasureChest::Update()
{
    // 宝石と接触したら
    if (isHitGem)
    {
        effectManager->PlayGemGetEffect(pos);
    }

	// 3Dモデルの座標設定
	MV1SetPosition(modelHanlde, pos);
}

// 描画
void TreasureChest::Draw()
{
	// 3Dモデルの描画
	MV1DrawModel(modelHanlde);
}


