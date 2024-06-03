#pragma once

class Gem;

/// <summary>
/// 宝箱クラス
/// </summary>
class TreasureChest final
{
public:
	TreasureChest();
	virtual ~TreasureChest();

	void Initialize();		// 初期化
	void Update(Gem& gem);			// 更新
	void Draw();			// 描画

	// Getter
	const VECTOR& GetPos()const { return pos; }
	const bool GetIsHitGem()const { return isHitGem; }
	const float GetRadius()const { return radius; }	

	// Setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitGem(const bool set) { isHitGem = set; }

private:
	// 変数
	// モデル
	int		modelHanlde;		// モデルハンドル

	// 情報
	VECTOR	pos;			// ポジション
	VECTOR	scale;			// スケール
	int		width;			// 幅
	int		height;			// 高さ

	// フラグ
	bool	isHitGem;		// 宝箱が宝石と接触したか

	// 当たり判定
	float	radius;			// 球型当たり判定用の半径
};


