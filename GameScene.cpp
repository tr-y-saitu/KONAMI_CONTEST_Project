#include "SceneBase.h"
#include "Room.h"
#include "TreasureChest.h"
#include "Camera.h"
#include "Collision.h"
#include "SkyDome.h"
#include "Gem.h"
#include "GemManager.h"
#include "Player.h"
#include "GameScene.h"
#include "Calculation.h"
#include "GameSceneUI.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameScene::GameScene()
    : previousTime  (0)
    , timer         (0)
    , nowTimer      (0)
    , score         (0)
    , scoreUpFlag   (false)
    , isBlackOutFlag(false)
{
    // newインスタンス
    player = new Player();
    treasureChest = new TreasureChest();
    gemManager = new GemManager();
    collision = new Collision();
    camera = new Camera();
    skyDome = new SkyDome();
    room = new Room();
    gameSceneUI = new GameSceneUI();
}

/// <summary>
/// デストラクタ
/// </summary>
GameScene::~GameScene()
{
    // newインスタンスの削除
    delete(player);
    delete(treasureChest);
    delete(gemManager);
    delete(collision);
    delete(camera);
    delete(skyDome);
    delete(room);
    delete(gameSceneUI);
}

/// <summary>
/// 初期化
/// </summary>
void GameScene::Initialize()
{
    player->Initialize();
    treasureChest->Initialize();
    gemManager->Initialize();
    skyDome->Initialize();
    room->Initialize();
    gameSceneUI->Initialize();
}

/// <summary>
/// 更新
/// </summary>
void GameScene::Update()
{
    // ゲームが開始してからの時間を計測
    SettingTimer(*gemManager);

    // ゲームアップデート
    // 当たり判定処理
    scoreUpFlag = gemManager->IsCollisionGem(*player, *treasureChest, *collision);
    if (scoreUpFlag)
    {
        // 当たった時の演出を出す指令をセット
        gameSceneUI->SetIsHitGemToChest(true);

        // スコアをアップさせる
        UpdateScore(*treasureChest);
    }
    // キャラクター更新
    player->Update();	// プレイヤー

    // カメラ更新
    camera->Update(*player);// カメラ

    // オブジェクト更新
    skyDome->Update();		                // 背景
    room->Update();			                // 部屋
    gemManager->UpdateWaveGem(nowTimer);    // 宝石
    treasureChest->Update();			        // 宝箱更新

    // データのリセットフラグがたったら宝石のデータをリセットさせる
    gemManager->ResetGemData();

    // STATE_GAMEの終了時間になったらSTATE_CLEARに移行

    //effekseer1->Update();
}

/// <summary>
/// 描画
/// </summary>
void GameScene::Draw()
{
    player->Draw();         // プレイヤー
    room->Draw();           // 部屋
    gemManager->DrawGems(); //　宝石たち
    treasureChest->Draw();  // 宝箱
}

/// <summary>
/// UIの描画
/// </summary>
void GameScene::DrawUI()
{
    gameSceneUI->Draw(score,nowTimer,gemManager->GetGemWaveState(),false);
}

/// <summary>
/// スコアの更新
/// </summary>
/// <param name="chest">宝箱</param>
void GameScene::UpdateScore(TreasureChest& chest)
{
    // 当たった宝石の種類を確認
    auto _hitGemType = chest.GetHitGemType();

    // スコアを計算
    score += (_hitGemType + 1) * 100;
}

/// <summary>
/// 現在経過時間の更新
/// </summary>
/// <param name="resetFlag">計測時間をリセットするかどうかのフラグ</param>
void GameScene::SettingTimer(GemManager& gemManager)
{
    //  時間をリセットするフラグがたったら
    if (gemManager.GetResetTimer())
    {
        // 経過時間をリセット
        previousTime = GetNowHiPerformanceCount();
        // フラグをおろす
        gemManager.SetResetTimer(false);
    }

    // 現在時間 - 最初の計測時間
    timer = (GetNowHiPerformanceCount() - previousTime);
    // 現在経過時間（１桁表示）
    nowTimer = (timer % 1000000000) / 1000000;
}
