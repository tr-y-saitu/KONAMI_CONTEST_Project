#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
enum WAVE_STATE;

/// <summary>
/// ウェーブごとの定数管理クラス
/// </summary>
class WaveConstants
{
public:
    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    WaveConstants();

    /// <summary>
    /// 引数付きコンストラクタ
    /// </summary>
    /// <param name="_entryTime">登場時間</param>
    /// <param name="_waveEndTime">そのWAVEが終了する時間</param>
    /// <param name="_uiWaveState">そのWAVEの状態を表す文字列</param>
    WaveConstants(int _entryTime,int _waveEndTime,string _uiWaveState);
    ~WaveConstants();

    // メンバー変数
    int entryTime;      // 登場時間
    int waveEndTime;    // そのWAVEが終了する時間
    string uiWaveState;   // そのWAVEの状態を表す文字列


private:

};


