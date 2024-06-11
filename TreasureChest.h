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
	void Update();			// 更新
	void Draw();			// 描画

	// Getter
	const VECTOR& GetPos()const { return pos; }
	const bool GetIsHitGem()const { return isHitGem; }
	const float GetRadius()const { return radius; }
    const float GetWidth()const { return width; }
    const float GetHeight()const { return height; }
    const int GetHitGemType()const { return hitGemType; }

	// Setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitGem(const bool set) { isHitGem = set; }
    void SetHitGemType(const int set) { hitGemType = set; }

private:
	// 変数
	// モデル
	int		modelHanlde;		// モデルハンドル

	// 情報
	VECTOR	pos;			// ポジション
	VECTOR	scale;			// スケール
	float	width;			// 幅
	float	height;			// 高さ

	// フラグ
	bool	isHitGem;		// 宝箱が宝石と接触したか

	// 当たり判定
	float	radius;			// 球型当たり判定用の半径
    int     hitGemType;   // 当たった宝石の種類
};


