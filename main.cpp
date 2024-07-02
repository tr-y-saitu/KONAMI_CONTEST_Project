// 標準ライブラリ
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "math.h"
// 追加外部ライブラリ
#include "DxLib.h"
#include "EffekseerForDXLib.h"
// 自作ヘッダー
#include "Common.h"
#include "GemManager.h"
#include "TreasureChest.h"
#include "Calculation.h"
#include "Enemy.h"
#include "Player.h"
#include "Camera.h"
#include "Collision.h"
#include "EffectManager.h"
#include "SoundManager.h"
#include "FPSSetting.h"
#include "Room.h"
#include "Gem.h"
// シーン
#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"
#include "OverScene.h"
// Game.hの上にすべての自作ヘッダーをインクルードする
#include "Game.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
    // シングルトンクラスのインスタンス化
    EffectManager::CreateInstance();    // エフェクト
    SoundManager::CreateInstance();     // サウンド

    // インスタンス化
    Game* game = new Game();            // ゲームループ

    // エスケープキーが押されるかウインドウが閉じられるまでループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ゲームループ
        game->Update();

        // Windows 特有の面倒な処理をＤＸライブラリにやらせる
        // マイナスの値（エラー値）が返ってきたらループを抜ける
        if (ProcessMessage() < 0)
        {
            break;
        }
        // もしＥＳＣキーが押されていたらループから抜ける
        else if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }
    }

    // シングルトンクラスの削除
    EffectManager::DeleteInstance();
    SoundManager::DeleteInstance();

    // ゲームの削除
    delete(game);

    // Effekseerを終了する。
    Effkseer_End();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
