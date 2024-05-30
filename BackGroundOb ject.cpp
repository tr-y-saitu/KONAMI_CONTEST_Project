#include "BackGroundObject.h"

/// <summary>
/// コンストラクタ
/// </summary>
BGObj::BGObj()
    :returnPosX     (3000)
    ,scrollSpeed   (4)
{
    // 座標設定
    pos = VGet(0, 100, 800);
    // 方向設定
    dir = VGet(0, 0, 0);
    // スケールを設定
    scale = VGet(1, 1, 1);

    pos2 = VGet(0, 0, 0);

    // 背景画像の読み込み
    graphHandle = LoadGraph("data/texture/スクリーンショット (4).png");
    graphUniverse= LoadGraph("data/texture/OIP (10).jpg");
}

/// <summary>
/// デストラクタ
/// </summary>
BGObj::~BGObj()
{
    // モデルハンドルの削除
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="graphHnadle">グラフハンドル</param>
void BGObj::Initialize(int graph, int texture,VECTOR initVec,int speed)
{
    // モデルハンドルの設定
    modelHandle = graph;

    // テクスチャの設定
    texrureHandle = texture;

    // モデルハンドルに設定したいテクスチャを貼り付け
    MV1SetTextureGraphHandle(modelHandle, 0, texrureHandle, true);

    // モデルのスケールを設定
    MV1SetScale(modelHandle, scale);

    // 座標設定
    pos = initVec;

    // 方向設定
    dir = VGet(0, 0, 0);

    pos2 = VGet(0, 0, 0);

    // 行列に単位行列を代入
    matrix = MGetIdent();

}

/// <summary>
/// 更新
/// </summary>
void BGObj::Update()
{
    // ずっと回転移動していてほしい
    
    // MATRIXに角度を指定
    //matrix = MGetRotY(DX_PI_F / 4.0f);  // (45度回転する行列)
    // MATRIX分、自分のposを変換させる 
    //pos = VTransform(pos, matrix);  // matrixには回転行列を入れているので回転する
    

    //// 指定軸を軸に回転する行列を取得
    //matrix = MGetRotAxis(VGet(0, 0, 0), DX_PI_F / 180.0f);
    //// matrix分、自分の座標を変換（回転）
    //pos = VTransform(pos, matrix);

    dir = VGet(-1, 0, 0);


    // 正規化
    if (VSquareSize(dir) > 0)
    {
        dir = VNorm(dir);
    }

    auto velocity = VScale(dir, scrollSpeed);
         
    // 画面端に行っていまったら
    if (pos.x <= -returnPosX)
    {
        pos.x = returnPosX;
    }

    pos = VAdd(pos, velocity);

    // モデルの拡大率をセット
    //MV1SetScale(modelHandle, VGet(2, 2, 2));

    // 3Dモデルのポジションを設定
    MV1SetPosition(modelHandle,pos);
    

}


/// <summary>
/// 描画
/// </summary>
void BGObj::Draw()
{
    // モデルの描画
    MV1DrawModel(modelHandle);

    //MV1DrawMesh(modelHandle, 0);

    // 3D空間に画像を描画
    //DrawBillboard3D(VGet(3000, 0, 500), 0.5f, 0.5f, 2000.0f, 0.0f, graphHandle, true);

    // 3D空間上に2次元的な変形を加えた画像を描画
   /* DrawModiBillboard3D(VGet(320.0f, 240.0f, 100.0f),
        -100.0f, 200.0f,
        100.0f, 200.0f,
        100.0f, -200.0f,
        -100.0f, -200.0f, graphUniverse, TRUE);*/


}
