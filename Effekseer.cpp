#include "DxLib.h"
//#include "EffekseerForDXLib.h"
#include "Effekseer.h"


Effekseer1::Effekseer1()
	:	effectResourceHandle	(0)
	,	graphBackGroundHandle	(0)
	,	graphFrontHandle		(0)
	,	time					(0)
	,	isFullScreen			(false)
	,	playingEffectHandle		(0)
{
	pos = VGet(0, 0, 0);
}

Effekseer1::~Effekseer1()
{
	// エフェクトリソースを削除する。(Effekseer終了時に破棄されるので削除しなくてもいい)
	//DeleteEffekseerEffect(effectResourceHandle);
}

// エフェクシアを使うための準備
void Effekseer1::ReadyEffekseerForDXLib()
{
	//// 描画先を裏画面に設定する
	//SetDrawScreen(DX_SCREEN_BACK);

	//// DirectX11を使用するようにする。(DirectX9も可、一部機能不可)
	//// Effekseerを使用するには必ず設定する。
	//SetUseDirect3DVersion(DX_DIRECT3D_11);

	//// Zバッファを有効にする。
	//// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	//SetUseZBuffer3D(TRUE);

	//// Zバッファへの書き込みを有効にする。
	//// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	//SetWriteZBuffer3D(TRUE);

}

// 初期化
void Effekseer1::Initialize()
{
	// エフェクトリソースの読み込み
	//effectResourceHandle = LoadEffekseerEffect("Laser01.efkefc", 25.0f);

	// なんでもいいので画像を読み込む
	graphBackGroundHandle = LoadGraph(_T("Texture/Background.png"));
	graphFrontHandle = LoadGraph(_T("Texture/Front.png"));

	// 時間を初期化（定期的にエフェクトを再生するため）
	time = 0;

	// フルスクリーン切り替えフラグを設定する
	isFullScreen = false;

	// エフェクトを表示する位置を設定
	pos = VGet(100.0f, 250.0f, 0.0f);

	// ワールド座標をスクリーン座標に変換する
	pos = ConvWorldPosToScreenPos(VGet(0,10,20));

	// スクリーン座標をワールド座標に変換する
	//pos = ConvScreenPosToWorldPos(pos);

	// 再生中のエフェクトのハンドルを初期化する
	playingEffectHandle = -1;

}

void Effekseer1::Update()
{
	// 定期的にエフェクトを再生する
	if (time % 60 == 0)
	{
		// エフェクトを再生する。
		//playingEffectHandle = PlayEffekseer2DEffect(effectResourceHandle);
		
		// エフェクトの位置をリセットする。
		pos.x = 100.0f;
	}


	// 再生中のエフェクトを移動する。
	//SetPosPlayingEffekseer2DEffect(playingEffectHandle, pos.x, pos.y, 0);
	pos.x += 2.0f;

	// Effekseerにより再生中のエフェクトを更新する。
	//UpdateEffekseer2D();

	// 時間を経過させる
	time++;

	//// ワールド座標をスクリーン座標に変換する
	//pos = ConvWorldPosToScreenPos(pos);

	// ()内の座標がカメラの視界に入っていないかどうかを判断する
	int flag = CheckCameraViewClip(pos);
	int gg = 0;
}


void Effekseer1::Draw()
{
	// 何でもいいので画像を描画する。
	// こうして描画した後でないと、Effekseerは描画できない。
	DrawGraph(0, 0, graphBackGroundHandle, TRUE);

	// Effekseerにより再生中のエフェクトを描画する。
	//DrawEffekseer2D();

	// エフェクトの上にも画像を描画できる。
	DrawGraph(0, 0, graphFrontHandle, TRUE);
}
