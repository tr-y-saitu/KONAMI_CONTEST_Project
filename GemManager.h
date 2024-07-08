#pragma once
#include "Common.h"
#include "Calculation.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;


class Gem;
enum WAVE_STATE;
class Calculation;
class Collision;
class WaveConstants;
class Player;
class TreasureChest;

/// <summary>
/// 宝石マネージャークラス
/// </summary>
class GemManager final
{
public:
    /// <summary>
    /// 宝石のタイプ
    /// </summary>
    enum GemType
    {
        EMERALD,	// エメラルド
        RUBY,		// ルビー
        SAPPHIRE,	// サファイア
        DIAMOND	    // ダイアモンド
    };

    /// <summary>
    /// ウェーブの名称
    /// </summary>
    enum WAVE_STATE
    {
        WAVE_FIRST,     // ファーストステージ
        WAVE_SECOND,    // セカンドステージ
        WAVE_THIRD,     // サードステージ
        WAVE_END        // 終了
    };

    // 宝石が登場するデータ
    struct EntryGemDataBase
    {
        float   entryTime;          // 登場する時間
        VECTOR  entryPosition;      // 登場する位置
    };

    // メソッド
    GemManager();
    virtual ~GemManager();

    /// <summary>
    /// 宝石の生成
    /// </summary>
    void CreateGem();

    /// <summary>
    /// 宝石の削除
    /// </summary>
    void DeleteGem();

    /// <summary>
    /// 宝石モデルのハンドルをロード
    /// </summary>
    void LoadModle();

    /// <summary>
    /// 宝石の初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 宝石のモデルを設定
    /// </summary>
    /// <param name="type">宝石の種類</param>
    /// <returns>その種類のモデルハンドル</returns>
    int SettingGemModle(int type);

    /// <summary>
    /// 宝石のエントリー情報の作成
    /// </summary>
    void CreateEntyrInformation();

    /// <summary>
    /// 宝石のエントリー情報を設定
    /// </summary>
    /// <param name="gem">宝石クラス</param>
    /// <param name="size">宝石の総数</param>
    void SettingEntryDataBase(Gem& gem, int index);

    /// <summary>
    /// 宝石の当たり判定更新
    /// </summary>
    /// <param name="player">プレイヤー</param>
    /// <param name="chest">宝箱</param>
    /// <returns>スコアアップのタイミングどうか</returns>
    bool IsCollisionGem(Player& player, TreasureChest& chest, Collision& collision);

    /// <summary>
    /// 宝石のデータのリセット
    /// </summary>
    void ResetGemData();

    /// <summary>
    /// 次のウェーブに行くための準備
    /// </summary>
    void ReadyingNextWave();

    /// <summary>
    /// 宝石のウェーブ更新
    /// </summary>
    void UpdateWaveGem(float nowTimer);

    /// <summary>
    /// 宝石の描画
    /// </summary>
    void DrawGems();

    // getter
    int GetGemWaveState() const { return gemWaveState; }
    int GetResetTimer() const { return resetTimer; }
    int GetIsResetEntyrData()const { return isResetEntryData; }
    bool GetIsEndOfGemEntry()const { return isEndOfGemEntry; }

    // setter
    void SetGemWaveState(const int set) { gemWaveState = set; }
    void SetResetTimer(const bool set) { resetTimer = set; }
    void SetIsResetEntryData(const bool set) { isResetEntryData = set; }

    // 定数
    static constexpr int GEM_TOTAL_NUM = 100;   // 総合の宝石の数

    // 変数
    // 宝石のベースモデルハンドル
    int modelHandleDiamond;     // ダイアモンド
    int modelHandleRuby;        // ルビー
    int modelHandleSapphire;    // サファイア
    int	modelHandleEmerald;     // エメラルド
    Calculation calculation;    // 計算用

    // 実際のデータ
    EntryGemDataBase entryGemDataBase[GEM_TOTAL_NUM];   // 宝石のエントリー情報を格納するための構造体
    map<WAVE_STATE, WaveConstants*> waveConstantsTable; // ウェーブごとの定数
    vector<Gem*> gems;

private:
    const VECTOR GEM_ENTRYR_POSITION = VGet(-18, 16, -5);

    int     gemWaveState;       // 現在のウェーブステート
    bool    resetTimer;         // 時間をリセットするフラグ
    bool    isResetEntryData;   // エントリーデータをリセットする
    bool    isEndOfGemEntry;    // 宝石の出現が終了したかどうか
};

