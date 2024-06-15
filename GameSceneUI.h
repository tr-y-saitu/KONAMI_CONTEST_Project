﻿#pragma once
#include "DxLib.h"
#include <stdio.h>
#include <iostream>

/// <summary>
/// ゲームシーンUI
/// </summary>
class GameSceneUI
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameSceneUI();

    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize();

    /// <summary>
    /// 描画
    /// </summary>
    /// <param name="gameScore">ゲームスコア</param>
    /// <param name="nowTimer">現在の経過時間</param>
    /// <param name="gemWaveState">現在の宝石のウェーブステート</param>
    /// <param name="isBlackOutFlag">暗転処理するかどうか</param>
    void Draw(int gameScore, float nowTimer,
        int gemWaveState, bool isBlackOutFlag);

    /// <summary>
    /// スコアの描画
    /// </summary>
    /// <param name="pos">スコアを描画する座標</param>
    /// <param name="fontSize">フォントサイズ</param>
    /// <param name="score">スコア</param>
    void DrawScore(VECTOR pos, int fontSize, int score);

    // Setter
    void SetIsHitGemToChest(const bool set) { isHitGemToChest = set; }

private:
    // 定数
    const int UI_COLOR = GetColor(200, 200, 200);	        // UIの文字の色
    static constexpr int GET_DIRECTION_DRAW_TIME = 100;     // 獲得演出を描画する時間

    // 変数
    int		getDirectionModelHandle;	    // 宝石獲得演出用モデル
    int     getDirectionCount;              // 宝石獲得時の演出を管理するカウント
    bool	isHitGemToChest;	            // 宝石と宝箱が接触した


};

