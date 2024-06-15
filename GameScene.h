#pragma once

#include "SceneBase.h"

class SceneBase;
class Player;
class TreasureChest;
class GemManager;
class Collision;
class Camera;
class SkyDome;
class Room;
class Calculation;
class GameSceneUI;

/// <summary>
/// ゲームシーンクラス
/// </summary>
class GameScene : public SceneBase
{
public:
    // SceneBaseクラスを継承。内容が異なるものだけoverrideする

    GameScene();
    ~GameScene() override;

    void Update() override;

    void Draw() override;


private:

    // インスタンス
    Player* player;
    TreasureChest* treasureChest;
    GemManager* gemManager;
    Collision* collision;
    Camera* camera;
    SkyDome* skyDome;
    Room* room;
    GameSceneUI* gameSceneUI;




};


