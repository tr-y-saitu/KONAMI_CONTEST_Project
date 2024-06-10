#include "DxLib.h"
#include "Gem.h"
#include "GemManager.h"
#include "Calculation.h"


/// <summary>
/// コンストラクタ
/// </summary>
GemManager::GemManager()
	: modelHandleDiamond	(-1)
	, modelHandleRuby		(-1)
	, modelHandleSapphire	(-1)
	, modelHandleEmerald	(-1)
    , gemWaveState          (WAVE_FIRST)
    , resetTimer            (false)
    , isResetEntryData      (false)
{

}

/// <summary>
/// デストラクタ
/// </summary>
GemManager::~GemManager()
{
	// 処理なし
}


/// <summary>
/// 宝石モデルのロード
/// </summary>
void GemManager::LoadModle()
{
	// 宝石のモデルをロード
	if (modelHandleDiamond <= -1)
	{	// ダイアモンド
		modelHandleDiamond	= MV1LoadModel("data/model/Gem/Diamonds.mv1");
	}
	if (modelHandleRuby <= -1)
	{	// ルビー
		modelHandleRuby		= MV1LoadModel("data/model/Gem/Ruby.mv1");
	}
	if (modelHandleSapphire <= -1)
	{	// サファイア
		modelHandleSapphire = MV1LoadModel("data/model/Gem/Sapphire.mv1");
	}
	if (modelHandleEmerald <= -1)
	{	// エメラルド
		modelHandleEmerald	= MV1LoadModel("data/model/Gem/Emerald.mv1");
	}

}

/// <summary>
/// タイプをもらってモデルハンドルを設定
/// </summary>
/// <param name="type">宝石のタイプ</param>
/// <returns>そのタイプのモデルハンドル</returns>
int GemManager::SettingGemModle(int type)
{
	// そのタイプのモデルハンドル
	int reTypeModelHandle = -1;

	// 種類(タイプ)の判定
	switch (type)
	{
	// ダイアモンド
	case DIAMOND:	
		reTypeModelHandle = modelHandleDiamond;
		break;

	// ルビー
	case RUBY:		
		reTypeModelHandle = modelHandleRuby;
		break;

	// サファイア
	case SAPPHIRE:	
		reTypeModelHandle = modelHandleSapphire;
		break;

	// エメラルド
	case EMERALD:	
		reTypeModelHandle = modelHandleEmerald;
		break;

	// それ以外
	default:
		break;
	}
	
	// そのタイプのモデルハンドルを返す
	return reTypeModelHandle;
}


/// <summary>
/// 宝石のエントリー情報を作成
/// </summary>
/// <param name="data">宝石のエントリー情報を格納する多次元配列</param>
/// <param name="size">多次元配列の添え字数</param>
void GemManager::CreateEntryData(EntryGemDataBase data[],int size)
{
    // ウェーブステートごとに異なる登場情報を作成
    switch (gemWaveState)
    {
    case WAVE_FIRST:
        // 宝石の登場情報を作成
        for (int i = 0; i < size; i++)
        {
            // 登場時間を設定
            data[i].entryTime = i * 1;
            // 登場座標の設定
            data[i].entryPosition = VGet(-18, 15, -5); // カメラ左上
        }
        break;

    case WAVE_SECOND:
        // 宝石の登場情報を作成
        for (int i = 0; i < size; i++)
        {
            // 登場時間を設定
            data[i].entryTime = i * 3;
            // 登場座標の設定
            data[i].entryPosition = VGet(-18, 15, -5); // カメラ左上
        }
        break;

    case WAVE_THIRD:
        // 宝石の登場情報を作成
        for (int i = 0; i < size; i++)
        {
            // 登場時間を設定
            data[i].entryTime = i * 1;
            // 登場座標の設定
            data[i].entryPosition = VGet(-18, 15, -5); // カメラ左上
        }
        break;

    default:
        break;
    }

}

/// <summary>
/// 宝石のエントリー情報を作成（一つ分）
/// </summary>
/// <param name="data">宝石のエントリー情報を格納する多次元配列の一つ</param>
/// <param name="index">その添え字</param>
void GemManager::CreateEntryDataBase(EntryGemDataBase& data, int index)
{
    // ウェーブステートごとに異なる登場情報を作成
    switch (gemWaveState)
    {
    case WAVE_FIRST:
        // 登場時間の設定
        data.entryTime = index * 5;
        // 登場座標の設定
        data.entryPosition = VGet(-18, 15, -5);
        break;

    case WAVE_SECOND:
        // 登場時間の設定
        data.entryTime = index * 3;
        // 登場座標の設定
        data.entryPosition = VGet(-18, 15, -5);
        break;

    case WAVE_THIRD:
        // 登場時間の設定
        data.entryTime = index * 1;
        // 登場座標の設定
        data.entryPosition = VGet(-18, 15, -5);
        break;

    default:
        break;
    }

}





/// <summary>
/// 宝石のエントリー情報を設定
/// </summary>
/// <param name="gem">宝石クラス</param>
/// <param name="size">宝石の総数</param>
void GemManager::SettingEntryDataBase(Gem& gem,int index)
{
	// 簡単に変数にする
	float _gemEntryTime = entryGemDataBase[index].entryTime;
	VECTOR _gemPos = entryGemDataBase[index].entryPosition;

	// 実際に書き込み
	gem.SetEntryTime(_gemEntryTime);// 登場時間の設定
	gem.SetEntryPosition(_gemPos);	// 登場座標の設定

}

/// <summary>
/// 宝石のウェーブ更新
/// </summary>
/// <param name="gem">宝石</param>
/// <param name="index">宝石の添え字</param>
/// <param name="nowTimer">現在の時間</param>
/// FiXME: y.saitu  修正が必要
void GemManager::GemWaveUpdate(Gem& gem, int index,float nowTimer)
{
    // ウェーブごとに異なる処理
    switch (gemWaveState)
    {
        // ファーストステージ
    case WAVE_FIRST:
        // 宝石の更新
        gem.Update(calculation, nowTimer);

        // そのウェーブの制限時間が終了したら
        if (nowTimer >= WAVE_TIME_FIRST)
        {
            // タイマーをリセットするフラグを立てる
            resetTimer = true;

            // セカンドステージへ切り替え
            gemWaveState = WAVE_SECOND;
            isResetEntryData = true;
        }

        break;

        // セカンドステージ
    case WAVE_SECOND:
        // 宝石の更新
        gem.Update(calculation, nowTimer);

        // そのウェーブの制限時間が終了したら
        if (nowTimer >= WAVE_TIME_SECOND)
        {
            // タイマーをリセットするフラグを立てる
            resetTimer = true;

            // サードステージへ切り替え
            gemWaveState = WAVE_THIRD;
            isResetEntryData = true;
        }

        break;

        // サードステージ
    case WAVE_THIRD:
        // 宝石の更新
        gem.Update(calculation, nowTimer);

        // そのウェーブの制限時間が終了したら
        
        break;


    default:
        break;
    }
}


