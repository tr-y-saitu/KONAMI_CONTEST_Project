//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
//#include "EffekseerForDXLib.h"
#include "Player.h"
#include "BackGroundObject.h"
#include "Camera.h"
#include "Enemy.h"
#include "Map.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
{
    // 描画範囲の設定
    SetCameraNearFar(0.1f, 1500.0f);

	// カメラのポジション
	pos = VGet(0, 3, -10);

    //(0,10,-20)の視点から(0,10,0)のターゲットを見る角度にカメラを設置
    //SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 200.0f));

	// 視野角の設定
	//SetupCamera_Perspective(90 * DX_PI_F / 180.0f);

	// Effekseerのカメラと同期する
	//Effekseer_Sync3DSetting();
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Camera::Update(Player& player,Enemy& enemy, BGObj& bgobj)
{
	// プレイヤーを追いかけるカメラ //////////////////////////////////////////////////////////////////
	//// プレイヤーの座標を取得
	//VECTOR playerPos = player.GetPos();
	//// カメラのポジションを設定
	//VECTOR cameraPos = VGet(playerPos.x, Map::ChipSize * (16 - 2) * 0.5f, playerPos.z - 10.0f);
	//// カメラと平行にまっすぐ z = 0 の地点を見つめる
	//VECTOR cameraLookPos = VGet(cameraPos.x, cameraPos.y, 0.0f);
	//// カメラの座標を更新
	//pos = cameraPos;
	//// カメラに位置を反映
	//SetCameraPositionAndTarget_UpVecY(pos, cameraLookPos);

	// カメラを設定
	SetCameraPositionAndTarget_UpVecY(pos, VGet(0, 2, 20));


}