//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"

class Player;

/// <summary>
/// カメラクラス
/// </summary>
class Camera
{
public:
	// Cameraをインスタンス化しなくても参照できる　static
	// 完全なる定数 constexpr
	static constexpr float ANGLE_SPEED = 0.05f;						// 旋回速度
	static constexpr float CAMERA_PLAYER_TARGET_HIEGHT = 400.0f;	// プレイヤー座標からどれだけ高い位置を注視点とするか
	static constexpr float TO_PLAYR_LENGTH = 1600.0f;				// プレイヤーとの距離
	static constexpr float COLLISION_SIZE = 50.0f;					// カメラの当たり判定のサイズ


	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.-

	/// <summary>
	/// カメラの更新
	/// </summary>
	/// <param name="player">プレイヤークラス</param>
	void Update(Player& player);

private:
	VECTOR	pos;			// ポジション.

};

#endif // _CAMERA_H_