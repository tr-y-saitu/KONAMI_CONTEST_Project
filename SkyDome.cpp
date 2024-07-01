#include "SkyDome.h"


/// <summary>
/// コンストラクタ
/// </summary>
SkyDome::SkyDome()
    : modelHandle       (-1)
    , textureHandle     (-1)
    , w                 (0)
    , h                 (0)
    , scale             (VGet(0.1,0.1,0.1))
{
    modelHandle = MV1LoadModel("data/model/skyDome/skyDome.mv1");
    MV1SetScale(modelHandle, VGet(0.4f, 0.4f, 0.4f));
    pos = VGet(0, 0, 0);
}

/// <summary>
/// デストラクタ
/// </summary>
SkyDome::~SkyDome()
{
    // モデルハンドルの削除
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void SkyDome::Initialize()
{
    // モデルハンドルの読み込み
    modelHandle = MV1LoadModel("data/model/skyDome/Sky_Twilight01.pmx");

    // テクスチャのハンドル読み込み
    textureHandle = LoadGraph("data/model/skyDome/Tex_SkyDome_Twilght01.png");

    // モデルハンドルに設定したいテクスチャを貼り付け
    MV1SetTextureGraphHandle(modelHandle, 0, textureHandle, true);

    // モデルの拡大率をセット
    MV1SetScale(modelHandle, VGet(0.1f, 0.1f, 0.1f));

    // 座標設定
    pos = VGet(0, 0, 0);

    // 方向設定
    dir = VGet(0, 0, 0);
}

/// <summary>
/// 更新
/// </summary>
void SkyDome::Update()
{
    // 3Dモデルのポジションを設定
    MV1SetPosition(modelHandle,pos);
}

/// <summary>
/// 描画
/// </summary>
void SkyDome::Draw()
{
    // 3Dモデルの描画（空）
    MV1DrawModel(modelHandle);
}


