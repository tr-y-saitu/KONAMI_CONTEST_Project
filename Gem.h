#pragma once
#include "DxLib.h"
#include "GemManager.h"

class Calculation;
class GemManager;
struct EntryGemDataBase;


/// <summary>
/// 宝石（ジェム）
/// </summary>
class Gem final
{
public:
	Gem();
	virtual ~Gem();

    /// <summary>
    /// 宝石の状態
    /// </summary>
    enum GEM_HIT_STATE
    {
        NORN,   // 接触していない
        ENTER,  // 接触した瞬間
        STAY,   // 接触し続けている
        EXIT    // 接触状態から接触していない状態へ移行した
    };

    /// <summary>
    /// 宝石の出現状態
    /// </summary>
    enum GEM_USE_STATE
    {
        UN_USED,        // 未使用
        IN_USE,         // 使用中
        USED,           // 使用済み
    };

	// メソッド

    /// <summary>
    /// 宝石のタイプごとの移動アルゴリズムの設定
    /// </summary>
    /// <param name="gemTyep">宝石の種類</param>
    /// <returns>そのタイプの移動方向</returns>
	VECTOR SettingMoveType(int gemType);

    /// <summary>
    /// 宝石のタイプ別で落下速度を設定
    /// </summary>
    /// <param name="gemType">宝石のタイプ</param>
    /// <returns>落下速度</returns>
    float SettingFallSpeedType(int gemType);

    /// <summary>
    /// 宝石の初期化
    /// </summary>
    /// <param name="_modelHandel"></param>
    void Initialize(int _modelHandel);

    /// <summary>
    /// 宝石の更新
    /// </summary>
    /// <param name="cal">計算クラス</param>
    /// <param name="nowTimer">現在の経過時間</param>
    void Update(Calculation& cal,float nowTimer);

    /// <summary>
    /// エンドウェーブでの宝石の更新
    /// </summary>
    void UpdateWaveEnd();

    /// <summary>
    /// 宝石の２次元での当たり判定を3D空間上で表示
    /// </summary>
    void Draw2DBOXCollision();

    /// <summary>
    /// 状態の移行
    /// </summary>
    /// <param name="state">宝石の状態</param>
    /// <param name="withTarget">対象と当たっているかどうか</param>
    /// <returns>宝石の対象との接触状態</returns>
    int UpdateGemHitState(GEM_HIT_STATE state, bool withTarget);

    /// <summary>
    /// 宝石の情報リセット
    /// </summary>
    void ResetGem(VECTOR resetPosition, int constantEntyrTime,int index);

    /// <summary>
    /// 宝石の使用状態の更新
    /// </summary>
    void UpdateGemUseState();

    /// <summary>
    /// 回転更新
    /// </summary>
    void UpdateRotation();

    /// <summary>
    /// 移動更新
    /// </summary>
    void UpdateMove();

    /// <summary>
    /// バウンド処理更新
    /// </summary>
    void UpdateBound();

    /// <summary>
    /// 重力を掛ける更新
    /// </summary>
    void UpdateGravity();

	/// <summary>
	/// 宝石の描画
	/// </summary>
	void Draw();

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	const float GetWidth() const{ return width; }
	const float GetHeight() const { return height; }
	const bool GetVisibleFlag() const { return visibleFlag; }
	const bool GetIsHitPlayer() const { return isHitPlayer; }
	const bool GetIsHitGround() const { return isHitGround; }
	const bool GetIsHitChest() const { return isHitTreasureChest; }
	const float GetEntyrTime()const { return entryTime; }
    const int GetGemType()const { return gemType; }
    const GEM_HIT_STATE GetGemStateWithPlayer()const { return statusWithPlayer; }
    const GEM_HIT_STATE GetGemStateWithTreasureChest()const { return statusWithTreasureChest; }
    const GEM_USE_STATE GetGemUseState()const { return useState; }

	// setter
	void SetIsHitPlayer(const bool set) { isHitPlayer = set; }
	void SetIsHitGround(const bool set) { isHitGround = set; }
	void SetIsHitChest(const bool set) { isHitTreasureChest = set; }
	void SetEntryTime(const float set) { entryTime = set; }
	void SetEntryPosition(const VECTOR set) { entryPosition = set; }

	// 定数
    static constexpr VECTOR END_POSITION = {80,0,0};    // WAVE_ENDでの座標位置
	const float GRAVITY_POWER = 0.003f;		// 宝石にかかる重力の値
	const float GRAVITY_POWER_LIMIT = 0.3f; // 宝石にかかる重力の限界値
	const float MOVE_SPEED = 0.17f;			// 移動速度
	const float JUMP_POWER = 0.14f;			// プレイヤーに当たった時のジャンプ量

	// 変数

	// モデル関係
	int		modelHandle;	// モデルハンドル
    int     collisionGraph; // 当たり判定の２次元画像

	// ステータス
	int             gemType;        // 宝石の種類(ダイア,ルビー,サファイア,エメラルド)
	VECTOR          pos;            // ポジション
	VECTOR          dir;            // 方向
	VECTOR          contactDir;     // 接触時の方向
	float           width;          // 幅
	float           height;         // 高さ
	VECTOR          scale;          // スケール
	float           scaleAdjust;    // スケールの調整
	float           speed;          // 移動スピード
	float           fallSpeed;      // 落下速度
	float           rotateCount;    // ゲーム中に少しづつ回転させるためのカウント
    GEM_USE_STATE   useState;       // 宝石の使用状態

    // 状態
    GEM_HIT_STATE     statusWithPlayer;           // プレイヤーとの状態
    GEM_HIT_STATE     statusWithTreasureChest;    // 宝箱との状態

	// フラグ
	bool	visibleFlag;	// 存在しているか
	bool	isHitPlayer;	// プレイヤーと接触中か
	bool	isHitGround;	// 床と接触したか
	bool	isHitTreasureChest;	// 宝箱と接触したか

	// エントリー情報
	float	entryTime;			// 登場する時間
	VECTOR	entryPosition;		// 登場する位置
private:
};

