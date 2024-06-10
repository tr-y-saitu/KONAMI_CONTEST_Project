#include "WaveConstants.h"

/// <summary>
/// デフォルトコンストラクタ
/// </summary>
WaveConstants::WaveConstants()
{
    // 処理なし
}


WaveConstants::WaveConstants(int _entryTime, int _waveEndTime, string _uiWaveState)
    : entryTime     (_entryTime)
    , waveEndTime   (_waveEndTime)
    , uiWaveState   (_uiWaveState)
{
}

WaveConstants::~WaveConstants()
{
}
