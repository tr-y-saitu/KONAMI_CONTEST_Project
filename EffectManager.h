#pragma once
#include <iostream>
#include <vector>


/// <summary>
/// エフェクトマネージャー
/// </summary>
class EffectManager
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EffectManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~EffectManager();

    /// <summary>
    /// インスタス作成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// エフェクトマネージャーのインスタンスのポインタを渡す
    /// </summary>
    /// <returns>EffectManagerのポインタ</returns>
    static EffectManager* GetInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// エフェクトの読み込み
    /// </summary>
    void LoadEffect();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 宝石獲得エフェクト
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayGemGetEffect(VECTOR playPosition);

    /// <summary>
    /// プレイヤーが宝石に当たった時のエフェクト
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayPlayerHitEffect(VECTOR playPosition);

private:
	int		effectResourceHandle;		// エフェクトリソース
	int		graphBackGroundHandle;		// 背景画像
	int		graphFrontHandle;			// 手前画像
	int		time;						// 定期的にエフェクトを再生する時間
	bool	isFullScreen;				// フルスクリーン切り替えようフラグ
	VECTOR	pos;						// エフェクトを描画する位置

    // エフェクト
    int     gemGetEffect;       // 宝石ゲット時
    int     playerHitEffect;    // プレイヤーと宝石のヒット時

    static EffectManager* effectManager;    // エフェクトマネージャーのインスタンス
    int playingEffectHandle;                // 現在再生中のエフェクトのハンドル
    std::vector<int> playingList;           // 現在再生中のリスト
};

