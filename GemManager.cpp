#include "DxLib.h"
#include "Gem.h"
#include "GemManager.h"
#include "Calculation.h"
#include "WaveConstants.h"
#include "Collision.h"

enum GEM_STATE;

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
    // WAVEごとの情報を代入
    waveConstantsTable[WAVE_FIRST] = new WaveConstants(5, 20, "WAVE_FIRST");
    waveConstantsTable[WAVE_SECOND] = new WaveConstants(3, 30, "WAVE_SECOND");
    waveConstantsTable[WAVE_THIRD] = new WaveConstants(1, 40, "WAVE_THIRD");
    modelHandleDiamond = MV1LoadModel("data/model/Gem/Diamonds.mv1");
    modelHandleRuby = MV1LoadModel("data/model/Gem/Ruby.mv1");
    modelHandleSapphire = MV1LoadModel("data/model/Gem/Sapphire.mv1");
    modelHandleEmerald = MV1LoadModel("data/model/Gem/Emerald.mv1");
}

/// <summary>
/// デストラクタ
/// </summary>
GemManager::~GemManager()
{
	// 処理なし
}

/// <summary>
/// 宝石の生成
/// </summary>
void GemManager::CreateGem()
{
    for (int i = 0; i < GEM_TOTAL_NUM; i++)
    {
        gems.push_back(new Gem());
    }
}

/// <summary>
/// 宝石の削除
/// </summary>
void GemManager::DeleteGem()
{
    for (int i = 0; i < GEM_TOTAL_NUM; i++)
    {
        delete(gems[i]);
    }
}

/// <summary>
/// 宝石の初期化
/// </summary>
void GemManager::Initialize()
{
    // 初期化関数の呼び出し
    for (int i = 0; i < GEM_TOTAL_NUM; i++)
    {
        gems[i]->gemType = GetRand(3);
        // 宝石のタイプ別にモデルハンドルを設定する
        int _modelHandle = SettingGemModle(gems[i]->gemType);
        gems[i]->Initialize(_modelHandle);
    }
    // 宝石のエントリー情報の作成
    CreateEntyrInformation();

    // 宝石のエントリー情報の書き込み
    for (int i = 0; i < GEM_TOTAL_NUM; i++)
    {
        gems[i]->entryTime = entryGemDataBase[i].entryTime;         // 登場時間
        gems[i]->entryPosition = entryGemDataBase[i].entryPosition; // 登場座標
    }
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
	// エメラルド
	case EMERALD:	
		reTypeModelHandle = modelHandleEmerald;
		break;

	// ルビー
	case RUBY:		
		reTypeModelHandle = modelHandleRuby;
		break;

	// サファイア
	case SAPPHIRE:	
		reTypeModelHandle = modelHandleSapphire;
		break;

	// ダイアモンド
	case DIAMOND:	
		reTypeModelHandle = modelHandleDiamond;
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
    // 現在のWAVEに必要な情報を引き出す
    // NOTE:(WAVE_STATE)gemWaveStateでキャスト変換しないと使用できない
    auto constant = waveConstantsTable[(WAVE_STATE)gemWaveState];

    for (int i = 0; i < size; i++)
    {
        // 登場時間を設定
        data[i].entryTime = i * constant->entryTime;
        // 登場座標の設定
        data[i].entryPosition = VGet(-18, 15, -5); // カメラ左上
    }
}

/// <summary>
/// 宝石のエントリー情報の作成
/// </summary>
void GemManager::CreateEntyrInformation()
{
    // 現在のWAVEに必要な情報を引き出す
    // NOTE:(WAVE_STATE)gemWaveStateでキャスト変換しないと使用できない
    auto constant = waveConstantsTable[(WAVE_STATE)gemWaveState];

    for (int i = 0; i < GEM_TOTAL_NUM; i++)
    {
        // 登場時間を設定
        entryGemDataBase[i].entryTime = i * constant->entryTime;
        // 登場座標の設定
        entryGemDataBase[i].entryPosition = VGet(-18, 15, -5); // カメラ左上
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
/// 宝石の当たり判定更新
/// </summary>
/// <param name="player">プレイヤー</param>
/// <param name="chest">宝箱</param>
/// <returns>スコアアップのタイミングどうか</returns>
bool GemManager::UpdateGemCollision(Player& player, TreasureChest& chest, Collision& collision)
{
    // スコアアップのタイミングかどうか
    bool _scoreUpFlag = false;

    for (int i = 0; i < 100; i++)
    {
        // プレイヤーと宝石との当たり判定
        collision.IsHit2DPlayerToGem(player, *gems[i]);
        // 宝石と宝箱の当たり判定
        bool _isHitGemAndChest = collision.IsHit2DGemToTreasureChest(*gems[i], chest);
        if (_isHitGemAndChest && gems[i]->GetGemStateWithTreasureChest() == Gem::GEM_STATE::ENTER)
        {
            _scoreUpFlag = true;
        }
    }
    return _scoreUpFlag;
}

/// <summary>
/// 宝石のデータリセット
/// </summary>
void GemManager::ResetGemData()
{
    // リセットフラグがたったら
    if (isResetEntryData)
    {
        Initialize();

        isResetEntryData = false;
    }
}

/// <summary>
/// 宝石のウェーブ更新
/// </summary>
/// <param name="nowTimer">現在の時間</param>
void GemManager::UpdateWaveGem(float nowTimer)
{
    // 現在のWAVEに必要な情報を引き出す
    // NOTE:(WAVE_STATE)gemWaveStateでキャスト変換しないと使用できない
    auto waveConstant = waveConstantsTable[(WAVE_STATE)gemWaveState];

    // もしもWAVEが終了していなければ
    if (gemWaveState != WAVE_END)
    {
        for (int i = 0; i < GEM_TOTAL_NUM; i++)
        {
            // 宝石の更新
            gems[i]->Update(calculation, nowTimer);
        }
        // そのウェーブの制限時間が終了したら
        if (nowTimer >= waveConstant->waveEndTime)
        {
            // タイマーをリセットするフラグを立てる
            resetTimer = true;

            // 宝石のデータを更新するフラグを立てる
            isResetEntryData = true;

            // 次のステージへ移行
            gemWaveState++;
        }
    }
    else
    {
        // クリアステートに移動させる
    }
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
    // 現在のWAVEに必要な情報を引き出す
    // NOTE:(WAVE_STATE)gemWaveStateでキャスト変換しないと使用できない
    auto waveConstant = waveConstantsTable[(WAVE_STATE)gemWaveState];

    // もしもWAVEが終了していなければ
    if (gemWaveState != WAVE_END)
    {
        // 宝石の更新
        gem.Update(calculation, nowTimer);

        // そのウェーブの制限時間が終了したら
        if (nowTimer >= waveConstant->waveEndTime)
        {
            // タイマーをリセットするフラグを立てる
            resetTimer = true;

            // 宝石のデータを更新するフラグを立てる
            isResetEntryData = true;

            // 次のステージへ移行
            gemWaveState++;
        }
    }
    else
    {
        // クリアステートに移動させる
    }
}

/// <summary>
/// 宝石の描画
/// </summary>
void GemManager::DrawGems()
{
    for (int i = 0; i < GEM_TOTAL_NUM; i++)
    {
        gems[i]->Draw();
    }
}

