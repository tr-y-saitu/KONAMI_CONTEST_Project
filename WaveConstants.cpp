#include "WaveConstants.h"

/// <summary>
/// デフォルトコンストラクタ
/// </summary>
WaveConstants::WaveConstants()
{
    // 処理なし
}


WaveConstants::WaveConstants(int _entryTime, int _waveEndTime, char* _uiWaveStateText)
    : entryTime     (_entryTime)
    , waveEndTime   (_waveEndTime)
    , uiWaveStateText(_uiWaveStateText)
{
}

WaveConstants::~WaveConstants()
{
}
