#include "SceneBase.h"
#include "ClearScene.h"
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
#include "WaveConstants.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameScene::GameScene(int _highScore)
    : previousTime      (0)
    , timer             (0)
    , nowTimer          (0)
    , isScoreUp         (false)
    , isNextScene       (false)
{
    highScore = _highScore;
    score = 0;
    // newインスタンス
    player = new Player();
    treasureChest = new TreasureChest();
    collision = new Collision();
    camera = new Camera();
    skyDome = new SkyDome();
    room = new Room();
    gameSceneUI = new GameSceneUI();
    gemManager = new GemManager();
}

/// <summary>
/// デストラクタ
/// </summary>
GameScene::~GameScene()
{
    // newインスタンスの削除
    delete(player);
    delete(treasureChest);
    delete(collision);
    delete(camera);
    delete(skyDome);
    delete(room);
    delete(gameSceneUI);
    delete(gemManager);
}


/// <summary>
/// 初期化
/// </summary>
void GameScene::Initialize()
{
    // ゲームが始まる前のGetNowCountを取得
    previousTime = GetNowHiPerformanceCount();
    timer = 0;
    nowTimer = 0;
    score = 0;
    isScoreUp = false;
    isNextScene = false;
    // 宝石のWAVE_STATEをFIRSTにする
    gemManager->SetGemWaveState(GemManager::WAVE_FIRST);

    // 各シーン初期関数呼び出し
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
    isScoreUp = gemManager->IsCollisionGem(*player, *treasureChest, *collision);
    if (isScoreUp)
    {
        // 当たった時の演出を出す指令をセット
        gameSceneUI->SetIsHitGemToChest(true);

        // スコアをアップさせる
        UpdateScore(*treasureChest);
    }
    // キャラクター更新
    player->Update();	// プレイヤー

    // カメラ更新
    camera->Update();// カメラ

    // オブジェクト更新
    skyDome->Update();		                // 背景
    room->Update();			                // 部屋
    gemManager->UpdateWaveGem(nowTimer);    // 宝石
    treasureChest->Update();			    // 宝箱更新

    // データのリセットフラグがたったら宝石のデータをリセットさせる
    gemManager->ResetGemData();

    // 終了時間になったらSCENE_CLEARに移行
    if (nowTimer >= STATE_GAME_TIME_LIMIT)
    {
        isNextScene = true;
    }

    //effekseer1->Update();
}

/// <summary>
/// シーンの更新
/// </summary>
/// <returns>次のシーンのポインタ</returns>
SceneBase* GameScene::UpdateScene()
{
    // フェードイン
    // スクリーンをフェードインした後UIをフェードイン
    if (gameSceneUI->GetFadeState() == SceneUIBase::FADE_NONE)
    {
        gameSceneUI->SetFadeState(SceneUIBase::FADE_IN_SCREEN_PLAYING);
    }
    if (gameSceneUI->GetFadeState() == SceneUIBase::FADE_IN_SCREEN_PLAYING)
    {
        gameSceneUI->StartFadeInScreen();
    }
    if (gameSceneUI->GetFadeState() == GameSceneUI::FadeState::FADE_IN_SCREEN_END)
    {
        gameSceneUI->StartFadeInUI();
    }

    // ゲームが開始してからの時間を計測
    SettingTimer(*gemManager);

    // ゲームアップデート
    // 当たり判定処理
    isScoreUp = gemManager->IsCollisionGem(*player, *treasureChest, *collision);
    if (isScoreUp)
    {
        // 当たった時の演出を出す指令をセット
        gameSceneUI->SetIsHitGemToChest(true);

        // スコアをアップさせる
        UpdateScore(*treasureChest);
    }
    // キャラクター更新
    player->Update();	// プレイヤー

    // カメラ更新
    camera->Update();// カメラ

    // オブジェクト更新
    skyDome->Update();		                // 背景
    room->Update();			                // 部屋
    gemManager->UpdateWaveGem(nowTimer);    // 宝石
    treasureChest->Update();			    // 宝箱更新
    //effekseer1->Update();
    // データのリセットフラグがたったら宝石のデータをリセットさせる
    gemManager->ResetGemData();

    // 終了時間になったらSCENE_CLEARに移行
    if (nowTimer >= STATE_GAME_TIME_LIMIT && !isFadeOutStart)
    {
        return new ClearScene(score,highScore);
    }


    // シーン終了判定がなければそのまま
    return this;
}

/// <summary>
/// 描画
/// </summary>
void GameScene::Draw()
{
    bool _fadeInScreen = gameSceneUI->GetFadeState() != GameSceneUI::FadeState::FADE_IN_SCREEN_PLAYING;
    bool _fadeOutScreen = gameSceneUI->GetFadeState() != GameSceneUI::FadeState::FADE_OUT_SCREEN_PLAYING;

    // オブジェク描画画
    player->Draw();         // プレイヤー
    room->Draw();           // 部屋
    gemManager->DrawGems(); // 宝石たち
    treasureChest->Draw();  // 宝箱
    // フェード処理中は描画しない
    if (_fadeInScreen && _fadeOutScreen)
    {
        DrawUI();               // UI描画
    }
}

/// <summary>
/// UIの描画
/// </summary>
/// OPTIMIZE:_waveEndTimeのコード行数が長いのでGetGemWaveState()を説明変数で置き換えたが、
///          キャストが上手く行かず、意図していない値が入るためそのままにしてます。
void GameScene::DrawUI()
{
    // WAVEごとの終了時間,説明文を渡す
    auto _waveText = gemManager->waveConstantsTable[(GemManager::WAVE_STATE)gemManager->GetGemWaveState()]->uiWaveStateText;
    auto _waveEndTime = gemManager->waveConstantsTable[(GemManager::WAVE_STATE)gemManager->GetGemWaveState()]->waveEndTime;
    gameSceneUI->Draw(score,nowTimer,
                      gemManager->GetGemWaveState(),false,
                      _waveEndTime, _waveText);
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

    if (highScore <= score)
    {
        highScore = score;
    }
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
