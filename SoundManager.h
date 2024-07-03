#pragma once
#include "Common.h"

/// <summary>
/// サウンドマネージャー
/// </summary>
/// MEMO:シングルトンクラス
class SoundManager
{
public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~SoundManager();

    /// <summary>
    /// インスタンス作成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// サウンドマネージャーのインスタンスのポインタを渡す
    /// </summary>
    /// <returns>SoundManagerのポインタ</returns>
    static SoundManager* GetInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// サウンドデータの読み込み
    /// </summary>
    void LoadData();

    /// <summary>
    /// 更新ん
    /// </summary>
    void Update();

private:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    SoundManager();

    // 管理用
    static SoundManager* soundManager;      // サウンドマネージャークラスのインスタンス
    int playingSoundHandle;                 // 現在再生中のサウンド
    vector<int> playingList;                // 現在再生中のサウンドリスト

    //                  サウンドデータ                  //
    // 共通
    int     pushuSE;            // ボタンを押したときの音

    // タイトルシーン
    int     titleSceneBGM;      // タイトルシーンのBGM

    // ゲームシーン
    int     gameSceneBGM;       // ゲームシーンのBGM
    int     gemHitSE;           // 宝石とプレイヤーが当たった時の音
    int     gemGetSE;           // 宝石を獲得した時の音
    int     rainSE;             // 雨の音
    int     wavesSE;            // 波の音
    int     burningSE;          // 燃える音

    // クリアシーン
    int     clearSceneBGM;      // クリアシーンのBGM
    int     fireworksSE;        // 花火の音




};


