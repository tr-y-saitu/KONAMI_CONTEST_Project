﻿#pragma once

class Gem;

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
	/// 宝石のエントリー情報を設定
	/// </summary>
	/// <param name="data">宝石のエントリー情報を格納する多次元配列</param>
	/// <param name="size">多次元配列の添え字数</param>
	void CreateEntryData(EntryGemDataBase data[], int size);
		
	/// <summary>
	/// 宝石のエントリー情報を設定
	/// </summary>
	/// <param name="gem">宝石クラス</param>
	/// <param name="size">宝石の総数</param>
	void SettingEntryDataBase(Gem& gem, int index);

	// 変数
	// 宝石のベースモデルハンドル
	int modelHandleDiamond;		// ダイアモンド
	int modelHandleRuby;		// ルビー
	int modelHandleSapphire;	// サファイア
	int	modelHandleEmerald;		// エメラルド

	
	// 実際のデータ
	EntryGemDataBase entryGemDataBase[100];

private:

};

