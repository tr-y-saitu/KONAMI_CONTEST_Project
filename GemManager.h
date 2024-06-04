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

	// メソッド
	GemManager();
	virtual ~GemManager();
	void LoadModle();			// 宝石モデルハンドルのロード
	int SettingGemModle(int type);		// 宝石のモデルを設定

	// 宝石のベースモデルハンドル
	int modelHandleDiamond;		// ダイアモンド
	int modelHandleRuby;		// ルビー
	int modelHandleSapphire;	// サファイア
	int	modelHandleEmerald;		// エメラルド

	// 宝石が登場するデータ
	struct EntryGemDataBase
	{
		int entryFrameCount;		// 登場するフレーム数
		VECTOR entryPosition;		// 登場する位置
	};
	
	// 実際のデータ
	EntryGemDataBase entryGemDataBase[100][2];

private:

};

