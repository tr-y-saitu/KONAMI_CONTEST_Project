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

	void Initialize();		// 初期化
	void Draw(int state,Player& player,bool clearFlag, TreasureChest& chest);	// 描画

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






