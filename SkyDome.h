#pragma once

#include "DxLib.h"

/// <summary>
/// スカイドーム
/// </summary>
class SkyDome
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    SkyDome();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~SkyDome();

    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    // モデルハンドルの取得
    int GetModelHandle() { return modelHandle; }

    // ポジションのgetter/setter.
    const VECTOR& GetPos() const { return pos; }
    const int GetWidth() { return w; }
    const int GetHeight() { return h; }
    void SetPos(const VECTOR set) { pos = set; }

private:
    // 定数
    const float SPEED = 5.0f;

    int     modelHandle;    // モデルハンドル
    int     textureHandle;  // テクスチャハンドル
    VECTOR  pos;            // ポジション
    VECTOR  dir;            // 方向
    VECTOR  scale;          // 拡大率
    int     w;              // 幅
    int     h;              // 高さ

};


