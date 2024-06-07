#include "DxLib.h"
#include "Gem.h"
#include "GemManager.h"
#include "Calculation.h"


// コンストラクタ
GemManager::GemManager()
	: modelHandleDiamond	(-1)
	, modelHandleRuby		(-1)
	, modelHandleSapphire	(-1)
	, modelHandleEmerald	(-1)
    , gemWaveState          (WAVE_FIRST)
{

}

// デストラクタ
GemManager::~GemManager()
{
	// 処理なし
}


// モデルのロード
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
/// <param name="waveState">現在のウェーブステート</param>
void GemManager::CreateEntryData(EntryGemDataBase data[],int size, int waveState)
{
	// 宝石の登場情報を書き込む
	for (int i = 0; i < size; i++)
	{
		// 登場時間を設定
		data[i].entryTime = i * 5;  // ５秒に一つ
		// 登場座標の設定
		data[i].entryPosition = VGet(-18, 15 , -5); // カメラ左上
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
/// ウェーブステート切り替え
/// </summary>
/// <param name="gem">宝石</param>
/// <param name="size">宝石の総合数</param>
void GemManager::ChangeGemWaveState(Gem gem[], int size)
{
    // 即座に切り替わりすぎるので、ちょっと時間を止める
    WaitTimer(500);

    // ステート切り替え処理
    switch (gemWaveState)
    {
        // ファーストステージ
    case WAVE_FIRST:
        // 一番最初に初期化行っているので行わない

        break;

        // セカンドステージ
    case WAVE_SECOND:
        // 初期化処理
        // エントリー情報の作成
        CreateEntryData(entryGemDataBase, GEM_TOTAL_NUM, gemWaveState);

        // エントリー情報の書き込み
        for (int i = 0; i < size; i++)
        {
            SettingEntryDataBase(gem[i], i);
        }
        break;

        // サードステージ
    case WAVE_THIRD:
        // 初期化処理
        // エントリー情報の作成
        CreateEntryData(entryGemDataBase, GEM_TOTAL_NUM, gemWaveState);

        // エントリー情報の書き込み
        for (int i = 0; i < size; i++)
        {
            SettingEntryDataBase(gem[i], i);
        }
        break;

    default:
        break;
    }
}


void GemManager::GemWaveUpdate(Gem& gem, int nowTimer)
{
    // ウェーブごとに異なる処理
    switch (gemWaveState)
    {
        // ファーストステージ
    case WAVE_FIRST:
        // このステージは20秒で終わる
        gem.Update(calculation, nowTimer);

        break;

        // セカンドステージ
    case WAVE_SECOND:

        break;

        // サードステージ
    case WAVE_THIRD:

        break;


    default:
        break;
    }
}


