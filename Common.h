#pragma once
#include "DxLib.h"
#include "EffectManager.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>

using namespace std;

// 共通の定数を持つヘッダー

static constexpr int SCREEN_SIZE_X= 1600;   // スクリーンの幅
static constexpr int SCREEN_SIZE_Y = 960;   // スクリーンの高さ
static constexpr int COLOR_BIT_DEPTH = 32;  // ビットタイプ
static constexpr int SCREEN_SIZE_X_HALF = SCREEN_SIZE_X / 2;    // スクリーンの半分の幅
static constexpr int SCREEN_SIZE_Y_HALF = SCREEN_SIZE_Y / 2;    // スクリーンの半分の高さ

