#pragma onecL

#include "DxLib.h"

class Player;
class Enemy;
class BGObj;
class Car;

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

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Camera();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Camera();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

private:
	VECTOR	pos;			// ポジション.

};
