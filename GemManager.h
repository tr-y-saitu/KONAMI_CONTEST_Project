#pragma once
#include "Calculation.h"
#include <iostream>
#include <map>
using namespace std;


class Gem;
enum WAVE_STATE;
class Calculation;
class WaveConstants;

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
        DIAMOND,	// ダイアモンド
        RUBY,		// ルビー
        SAPPHIRE,	// サファイア
        EMERALD		// エメラルド
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
        float	entryTime;			// 登場する時間
        VECTOR	entryPosition;		// 登場する位置
    };

    // メソッド
    GemManager();
    virtual ~GemManager();

    /// <summary>
    /// 宝石モデルのハンドルをロード
    /// </summary>
    void LoadModle();

    /// <summary>
    /// 宝石のモデルを設定
    /// </summary>
    /// <param name="type">宝石の種類</param>
    /// <returns>その種類のモデルハンドル</returns>
    int SettingGemModle(int type);

    /// <summary>
    /// 宝石のエントリー情報を作成
    /// </summary>
    /// <param name="data">宝石のエントリー情報を格納する多次元配列</param>
    /// <param name="size">多次元配列の添え字数</param>
    /// <param name="waveState">現在のウェーブステート</param>
    void CreateEntryData(EntryGemDataBase data[], int size);

    /// <summary>
    /// 宝石のエントリー情報を設定
    /// </summary>
    /// <param name="gem">宝石クラス</param>
    /// <param name="size">宝石の総数</param>
    void SettingEntryDataBase(Gem& gem, int index);

    /// <summary>
    /// 宝石のウェーブ更新
    /// </summary>
    /// <param name="gem">宝石</param>
    /// <param name="index">宝石の添え字</param>
    /// <param name="nowTimer">現在の時間</param>
    void GemWaveUpdate(Gem& gem, int index, float nowTimer);

    // getter
    const int GetGemWaveState()const { return gemWaveState; }
    const int GetResetTimer()const { return resetTimer; }
    const int GetIsResetEntyrData()const { return isResetEntryData; }

    // setter
    void SetGemWaveState(const int set) { gemWaveState = set; }
    void SetResetTimer(const bool set) { resetTimer = set; }
    void SetIsResetEntryData(const bool set) { isResetEntryData = set; }

    // 定数
    const int GEM_TOTAL_NUM = 100;  // 総合の宝石の数
    const int WAVE_TIME_FIRST = 20;  // ファーストステージの時間
    const int WAVE_TIME_SECOND = 30;// セカンドステージの時間
    const int WAVE_TIME_THIRD = 40; // サードステージの時間

	// 変数
	// 宝石のベースモデルハンドル
	int modelHandleDiamond;		// ダイアモンド
	int modelHandleRuby;		// ルビー
	int modelHandleSapphire;	// サファイア
	int	modelHandleEmerald;		// エメラルド
    Calculation calculation;    // 計算用

	// 実際のデータ
	EntryGemDataBase entryGemDataBase[100];	// 宝石のエントリー情報を格納するための構造体
    map<WAVE_STATE, WaveConstants*> waveConstantsTable;  // ウェーブごとの定数

private:
    int     gemWaveState;       // 現在のウェーブステート
    bool    resetTimer;         // 時間をリセットするフラグ
    bool    isResetEntryData;     // エントリーデータをリセットする
};

