#pragma once


#include "DxLib.h"

class Game;
class Player;
class TreasureChest;

class UI
{
public:
	UI();		// コンストラクタ
	~UI();		// デストラクタ

	/// <summary>
	/// UIの初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// UIの更新
	/// </summary>
	/// <param name="state">ゲームステート</param>
	/// <param name="player">プレイヤークラス</param>
	/// <param name="clearFlag">クリアしているかどうか</param>
	/// <param name="chest">宝箱クラス</param>
	/// <param name="nowTimer">ゲームの現在経過時間</param>
	void Draw(int state,Player& player,bool clearFlag, TreasureChest& chest,float nowTimer);	// 描画

	// Getter
	const bool GetIsHitGemToChest()const { return isHitGemToChest; }

	// Setter
	void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
	// 定数

	// 変数
	int		menuGraph;		// メニュー画像
	int		strGetModleHandel;	// 「GET!」のモデルハンドル
	bool	isHitGemToChest;	// 宝石と宝箱が接触した
};






