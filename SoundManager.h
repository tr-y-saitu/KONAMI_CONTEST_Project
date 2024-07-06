#pragma once
#include "Common.h"

/// <summary>
/// サウンドマネージャー
/// </summary>
/// MEMO:シングルトンクラス
class SoundManager  final
{
public:
    /// <summary>
    /// 再生する効果音
    /// </summary>
    enum PLAY_SOUND_SE
    {
        PUSH_SE,        // ボタン入力音
        GEM_BOUND_SE,   // 宝石が跳ねた時の音
        GEM_GET_SE,     // 宝石を獲得した時の音
        FIREWORKS_SE,   // 花火が上がる音
        THUNDER_SE,     // 雷が落ちる音
    };

    /// <summary>
    /// 再生するBGM
    /// </summary>
    enum PLAY_SOUND_BGM
    {
        TITLE_SCENE_BGM,    // タイトルシーンのBGM
        GAME_SCENE_BGM,     // ゲームシーンのBGM
        CLEAR_SCENE_BGM,    // クリアシーンのBGM
    };

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
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 再生中の音をすべて止める
    /// </summary>
    void StopAllSounds();

    /// <summary>
    /// 読み込んだサウンドリストから効果音再生
    /// </summary>
    /// <param name="soundType">再生したい効果音の種類</param>
    void PlaySoundListSE(PLAY_SOUND_SE soundType);

    /// <summary>
    /// 読み込んだサウンドリストからBGM再生
    /// </summary>
    /// <param name="soundType">再生したいBGMの種類</param>
    void PlaySoundListBGM(PLAY_SOUND_BGM soundType);

private:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    SoundManager();

    // 管理用
    static SoundManager* soundManager;      // サウンドマネージャークラスのインスタンス
    int playingSoundHandle;                 // 現在再生中のサウンド
    vector<int> playingList;                // 現在再生中のサウンドリスト
    map<PLAY_SOUND_SE, int> soundListSE;    // 再生する効果音のリスト
    map<PLAY_SOUND_BGM, int> soundListBGM;  // 再生するBGMのリスト

    //                  サウンドデータ                  //
    // 共通
    int     pushuSE;            // ボタンを押したときの音

    // タイトルシーン
    int     titleSceneBGM;      // タイトルシーンのBGM
    int     thunderSE;          // 雷が落ちる効果音

    // ゲームシーン
    int     gameSceneBGM;       // ゲームシーンのBGM
    int     gemBoundSE;         // 宝石とプレイヤーが当たった時の音
    int     gemGetSE;           // 宝石を獲得した時の音
    int     rainSE;             // 雨の音
    int     wavesSE;            // 波の音
    int     burningSE;          // 燃える音

    // クリアシーン
    int     clearSceneBGM;      // クリアシーンのBGM
    int     fireworksSE;        // 花火の音
};


