#include "SceneBase.h"
#include "Game.h"
#include "MenuSceneUI.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "OverScene.h"
#include "ClearScene.h"
#include "SceneManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
Game::Game()
    : sceneState(SCENE_MENU)
    , previousTime(0)
    , timer(0)
    , nowTimer(0)
    , score(0)
    , keyOn(false)
    , keyRelease(false)
    , prevKeyOn(false)
{
    // 最初のシーンの設定
    nowScene = SceneBase::InitializeBase();
    // 次のシーンの初期化
    nextScene = NULL;
}

/// <summary>
/// デストラクタ
/// </summary>
Game::~Game()
{
    delete(menuScene);
    delete(gameScene);
    delete(clearScene);
    delete(overScene);
}

/// <summary>
/// 実際のゲームループ
/// </summary>
void Game::GameLoop()
{
    ClearDrawScreen();

    nextScene = nowScene->UpdateScene();
    nowScene->Draw();
    nowScene->DrawUI();

    ScreenFlip();

    if (nowScene != nextScene)
    {
        SceneChange();
    }

}

/// <summary>
/// シーンの切り替え
/// </summary>
void Game::SceneChange()
{
    // 現在のシーンを削除
    delete(nowScene);

    // 現在のシーンを切り替え
    nowScene = nextScene;

    // 初期関数を呼ぶ
    nowScene->Initialize();

    // 次のシーンを初期化S
    nextScene = NULL;
}

/// <summary>
/// 初期化
/// </summary>
void Game::Initialize()
{
    // ゲームが始まる前のGetNowCountを取得
    previousTime = GetNowHiPerformanceCount();
    nowTimer = 1;
    score = 0;

    menuScene->Initialize();
    gameScene->Initialize();
    clearScene->Initialize();
    overScene->Initialize();
}

/// <summary>
/// 現在のシーンの切り替え
/// </summary>
void Game::ChangeNowScene()
{
    // ステートが切り替わった瞬間、キーを離した判定をリセット
    keyOn = false;
    keyRelease = false;

    // ステート切り替え処理
    switch (sceneState)
    {
        // タイトル
    case SCENE_MENU:
        break;

        // ゲーム中
    case SCENE_GAME:
        Initialize();
        break;

        // クリア画面
    case SCENE_CLEAR:
        break;

        // ゲームオーバー
    case SCENE_OVER:
        break;

    default:
        break;
    }
}

/// <summary>
/// 更新
/// </summary>
void Game::Update()
{
    // キー入力処理
    ProcessKey();

    switch (sceneState)
    {
        // タイトルシーン
    case SCENE_MENU:
        // 更新処理
        menuScene->Update();

        // スペースキーが押されたらシーン切り替え
        if (keyRelease)
        {
            sceneState = SCENE_GAME;
            ChangeNowScene();
        }

        break;

        // ゲームシーン
    case SCENE_GAME:
        // 更新処理
        gameScene->Update();

        // 次のシーンに行く指示が出たら
        if (gameScene->GetIsNextScene())
        {
            sceneState = SCENE_CLEAR;
            ChangeNowScene();
        }
        break;

        // クリアシーン
    case SCENE_CLEAR:
        // 更新処理
        clearScene->Update();

        // スペースキーが押されたらシーン切り替え
        if (keyRelease)
        {
            sceneState = SCENE_MENU;
            ChangeNowScene();
        }
        break;

        // オーバーシーン
    case SCENE_OVER:
        // 更新処理
        overScene->Update();
        break;



    default:
        break;
    }
}

/// <summary>
/// 描画
/// </summary>
void Game::Draw()
{
    switch (sceneState)
    {
        // タイトルシーン
    case SCENE_MENU:
        // UIの描画
        menuScene->DrawUI();
        break;

        // ゲームシーン
    case SCENE_GAME:
        gameScene->Draw();
        // UIの描画
        gameScene->DrawUI();
        break;

        // クリアシーン
    case SCENE_CLEAR:
        clearScene->Draw();
        // UIの描画
        clearScene->DrawUI();
        break;

        // オーバーシーン
    case SCENE_OVER:
        overScene->Draw();
        // UIの描画
        overScene->DrawUI();
        break;

    default:
        break;
    }
}

/// <summary>
/// 入力処理
/// </summary>
void Game::ProcessKey()
{
    // キーを離した瞬間をとる
    if (keyOn)
    {
        if (CheckHitKey(KEY_INPUT_SPACE) == 0)
        {
            keyOn = false;
            keyRelease = true;
        }
    }
    else if (prevKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        keyRelease = false;
        keyOn = true;
    }
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        prevKeyOn = true;
    }
    else
    {
        prevKeyOn = false;
    }
}

/// <summary>
/// 現在制限時間の描画
/// </summary>
void Game::DrawTimer()
{
    // フォントサイズ設定
    SetFontSize(100);

    // 色保持
    int _color = GetColor(200, 200, 200);

    // 時間を保持する
    timer = (GetNowHiPerformanceCount() - previousTime);		// 現在時間 - 最初の計測時間
    int _nowTimer = (timer % 1000000000) / 1000000;				// 一桁の秒数
    nowTimer = (timer % 1000000000) / 1000000;
    char timerStr[256];
    sprintf_s(timerStr, "TIME: %d / 90", _nowTimer);
    DrawString(850, 0, timerStr, _color, true);
    nowTimer = _nowTimer;

    // 20秒経過ごとに(_nowTimerが０ではないとき。開始直後の時は無視)
    if (_nowTimer % 20 == 0 && _nowTimer != 0)
    {
        char _timeCount[256];
        sprintf_s(_timeCount, "～～～%f秒経過～～～", nowTimer);
        DrawString(250, 400, _timeCount, GetColor(255, 100, 100), true);
    }
}






