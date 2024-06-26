#pragma once

class BoatWithChest;
class PirateShip;
class Sea;

/// <summary>
/// ステージ管理クラス
/// </summary>
class StageManager
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    StageManager();

    /// <summary>
    /// コンストラクタ
    /// </summary>
    ~StageManager();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:
    BoatWithChest* boatWithChest;
    PirateShip* pirateShip;
    Sea* sea;
};


