#pragma once


#include "DxLib.h"

class Game;
class Player;
class TreasureChest;


/// <summary>
/// UIクラス
/// </summary>
class UI
{
public:
	UI();		// コンストラクタ
	virtual ~UI();		// デストラクタ

	/// <summary>
	/// UIの初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// UIの描画
	/// </summary>
	/// <param name="state">ゲームステート</param>
	/// <param name="player">プレイヤークラス</param>
	/// <param name="isDrawUIFlag">UIを描画する指示</param>
	/// <param name="chest">宝箱クラス</param>
	void Draw(int state, Player& player, bool& isDrawUIFlag, TreasureChest& chest);	// 描画

	// Getter
	const bool GetIsHitGemToChest()const { return isHitGemToChest; }

	// Setter
	void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
	// 定数
	const int STRING_GET_DRAW_TIME = 100;		// 「GET!」を描画するフレーム数

	// 変数
	int		menuGraph;			// メニュー画像
	bool	isHitGemToChest;	// 宝石と宝箱が接触した
	int		strGetModleHandel;	// 「GET!」のモデルハンドル
	int		strGetDrawCount;	// 「GET!」を描画する時間を設定するカウント
};






