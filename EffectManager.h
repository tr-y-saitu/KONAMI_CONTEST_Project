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

    /// <summary>
    /// 宝石が地面に落ちてしまった時のエフェクト
    /// </summary>
    /// <param name="playPosition">再生する座標</param>
    void PlayGemFallEffect(VECTOR playPosition);

private:
    // 管理用
    static EffectManager* effectManager;    // エフェクトマネージャーのインスタンス
    int playingEffectHandle;                // 現在再生中のエフェクトのハンドル
    std::vector<int> playingList;           // 現在再生中のリスト

    // ハンドル
    int     gemGetEffect;       // 宝石ゲット時
    int     playerHitEffect;    // プレイヤーと宝石のヒット時
    int     gemFallEffect;      // 宝石が落ちてしまった時
};

