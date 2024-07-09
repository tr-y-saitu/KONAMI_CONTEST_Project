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
    /// タイトルシーンでの更新
    /// </summary>
    void UpdateTitleScene();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:

    BoatWithChest* boatWithChest;       // 宝箱を乗せる船
    PirateShip* pirateShip;             // 海賊船
    Sea* sea;                           // 海
};


