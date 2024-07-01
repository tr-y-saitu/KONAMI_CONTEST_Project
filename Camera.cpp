#include "EffekseerForDXLib.h"
#include "Player.h"
#include "Camera.h"
#include "Enemy.h"
#include "Map.h"

/// <summary>
/// コンストラクタ
/// </summary>
Camera::Camera()
    : angle         (0)
{
    // 描画範囲の設定
    SetCameraNearFar(0.1f, 600.0f);

	// カメラのポジション
    position = VGet(-7, 5, -23);

    // カメラを設定
    SetCameraPositionAndTarget_UpVecY(position, VGet(-7, 5, 20));
}

/// <summary>
/// デストラクタ
/// </summary>
Camera::~Camera()
{
	// 処理なし
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="initializePosition">カメラの座標</param>
/// <param name="targetPosition">カメラの見ている座標</param>
void Camera::Initialize(VECTOR initializePosition, VECTOR targetPosition)
{
    // カメラ設定
    // initializePositionからtargetPositionを見る
    SetCameraPositionAndTarget_UpVecY(initializePosition, targetPosition);
}

/// <summary>
/// 更新
/// </summary>
void Camera::Update()
{
    // DXライブラリのカメラとEffekseerのカメラを同期する。
    Effekseer_Sync3DSetting();
}

/// <summary>
/// メニューシーンでの更新
/// </summary>
void Camera::UpdateMenuScene()
{
    // 回転移動
    MovementRotaitionl();

    // DXライブラリのカメラとEffekseerのカメラを同期する。
    Effekseer_Sync3DSetting();

}

/// <summary>
/// 回転移動
/// </summary>
void Camera::MovementRotaitionl()
{
    position.x = START_POSITION_X * cosf(angle);
    position.y = START_POSITION_Y;
    position.z = START_POSITION_Z * sinf(angle);

    SetCameraPositionAndTarget_UpVecY(position, VGet(0, 0, 0));

    // 角度を加算
    angle += ROTATIONAL_SPEED;

    // 360度を越えたらゼロに戻す
    if (angle >= DX_TWO_PI)
    {
        angle -= DX_TWO_PI;
    }
}
