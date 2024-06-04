#pragma once



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

	// 宝石が登場するデータ
	struct EntryGemDataBase
	{
		int entryFrameCount;		// 登場するフレーム数
		VECTOR entryPosition;		// 登場する位置
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
/// 宝石のエントリー情報を設定
/// </summary>
/// <param name="data">宝石のエントリー情報を格納する多次元配列</param>
/// <param name="size">多次元配列の添え字数</param>
	void SettingEntryData(EntryGemDataBase data[], int size);

	// 宝石のベースモデルハンドル
	int modelHandleDiamond;		// ダイアモンド
	int modelHandleRuby;		// ルビー
	int modelHandleSapphire;	// サファイア
	int	modelHandleEmerald;		// エメラルド

	
	// 実際のデータ
	EntryGemDataBase entryGemDataBase[100];

private:

};

