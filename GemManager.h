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

private:


};

