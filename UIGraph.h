#pragma once
#include "DxLib.h"

/// <summary>
/// UIで使用する画像
/// </summary>
class UIGraph
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="_graphHandle">画像ファイルパス</param>
    /// <param name="initPos">初期化座標</param>
    UIGraph(char* _graphHandle,VECTOR initPos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~UIGraph();

    // Getter/Setter
    const VECTOR GetPosition()const { return position; }
    const int GetGraphHandle()const { return graphHandle; }
    const bool GetIsResetPosition()const { return isResetPosition; }
    void SetPosition(const VECTOR set) { position = set; }
    void SetIsResetPosition(const bool set) { isResetPosition = set; }

private:
    VECTOR  position;       // 描画座標
    int     graphHandle;    // 画像ハンドル
    bool    isResetPosition;// 初期位置に戻るかどうか
};

