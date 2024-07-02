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

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Camera();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Camera();

    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name="initializePosition">カメラの座標</param>
    /// <param name="targetPosition">カメラの見ている座標</param>
    void Initialize(VECTOR initializePosition,VECTOR targetPosition);

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// メニューシーンでの更新
    /// </summary>
    void UpdateMenuScene();

    /// <summary>
    /// 回転移動
    /// </summary>
    void MovementRotaitionl();

private:
    // Cameraをインスタンス化しなくても参照できる　static
    // 完全なる定数 constexpr
    static constexpr float ANGLE_SPEED = 0.05f;                     // 旋回速度
    static constexpr float CAMERA_PLAYER_TARGET_HIEGHT = 400.0f;    // プレイヤー座標からどれだけ高い位置を注視点とするか
    static constexpr float TO_PLAYR_LENGTH = 1600.0f;               // プレイヤーとの距離
    static constexpr float COLLISION_SIZE = 50.0f;                  // カメラの当たり判定のサイズ
    static constexpr float ROTATIONAL_SPEED = 0.01f;                // カメラ回転速度
    static constexpr int START_POSITION_X = 150;                    // カメラが回転し始めるポジションX
    static constexpr int START_POSITION_Y = 50;                     // カメラが回転し始めるポジションY
    static constexpr int START_POSITION_Z = 150;                    // カメラが回転し始めるポジションZ

    // 変数
    VECTOR  position;           // ポジション
    float   angle;              // 角度

};
