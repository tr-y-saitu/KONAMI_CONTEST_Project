#pragma once

class BoatWithChest;
class PirateShip;
class Sea;

/// <summary>
/// ステージ管理クラス
/// </summary>
class StageObjectSet
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    StageObjectSet();

    /// <summary>
    /// コンストラクタ
    /// </summary>
    ~StageObjectSet();

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


