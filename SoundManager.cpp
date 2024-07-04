#include "SoundManager.h"

// 初期化
SoundManager* SoundManager::soundManager = NULL;

/// <summary>
/// コンストラクタ
/// </summary>
SoundManager::SoundManager()
    : playingSoundHandle        (0)
{
    // サウンドデータ読み込み
    LoadData();
}

/// <summary>
/// デストラクタ
/// </summary>
SoundManager::~SoundManager()
{
}

/// <summary>
/// サウンドデータの読み込み
/// </summary>
void SoundManager::LoadData()
{
    pushuSE = LoadSoundMem("data/sound/Common/pushuSE.mp3");
    titleSceneBGM = LoadSoundMem("data/sound/TitleScene/TitleSceneBGM1.mp3");
    gameSceneBGM = LoadSoundMem("data/sound/GameScene/GameSceneBMG1.mp3");
    gemBoundSE = LoadSoundMem("data/sound/GameScene/gemHitSE2.mp3");
    gemGetSE = LoadSoundMem("data/sound/GameScene/gemGetSE.mp3");
    clearSceneBGM = LoadSoundMem("data/sound/ClearScene/ClearSceneBGM.mp3");
    fireworksSE = LoadSoundMem("data/sound/ClearScene/fireworksSE.mp3");
}

/// <summary>
/// インスタンスの作成
/// </summary>
void SoundManager::CreateInstance()
{
    if (soundManager == NULL)
    {
        soundManager = new SoundManager();
    }
}

/// <summary>
/// サウンドマネージャークラスのインスタンスポインタを渡す
/// </summary>
SoundManager* SoundManager::GetInstance()
{
    return soundManager;
}

/// <summary>
/// インスタンスの削除
/// </summary>
void SoundManager::DeleteInstance()
{
    delete(soundManager);
}

/// <summary>
/// 更新
/// </summary>
void SoundManager::Update()
{

}

/// <summary>
/// 再生中の音をすべて止める
/// </summary>
void SoundManager::StopAllSounds()
{
    // 再生中のサウンドを探す
    for (int i = playingList.size() - 1; i >= 0; i--)
    {
        if (CheckSoundMem(playingList[i]))
        {
            StopSoundMem(playingList[i]);               // 停止
        }
        playingList.erase(playingList.begin() + i);     // 削除
    }
}

/// <summary>
/// ボタンを押したときの音を再生
/// </summary>
void SoundManager::PlayPushuSE()
{
    if (!CheckSoundMem(pushuSE))
    {
        playingList.push_back(pushuSE);
        PlaySoundMem(pushuSE, DX_PLAYTYPE_BACK, true);
    }
}

/// <summary>
/// タイトルシーンのBGMを再生
/// </summary>
void SoundManager::PlayTitleSceneBGM()
{
    if (!CheckSoundMem(titleSceneBGM))
    {
        playingList.push_back(titleSceneBGM);
        PlaySoundMem(titleSceneBGM, DX_PLAYTYPE_LOOP, true);
    }
}

/// <summary>
/// ゲームシーンのBGMを再生
/// </summary>
void SoundManager::PlayGameSceneBGM()
{
    if (!CheckSoundMem(gameSceneBGM))
    {
        playingList.push_back(gameSceneBGM);
        PlaySoundMem(gameSceneBGM, DX_PLAYTYPE_LOOP, true);
    }
}

/// <summary>
/// 宝石が跳ねた時の音を再生
/// </summary>
void SoundManager::PlayGemBoundSE()
{
    // 音が重なってもいいため再生チェックなし
    playingList.push_back(gemBoundSE);
    PlaySoundMem(gemBoundSE, DX_PLAYTYPE_BACK, true);
}

/// <summary>
/// 宝石を獲得した時の音を再生
/// </summary>
void SoundManager::PlayGemGetSE()
{
    // 音が重なってもいいため再生チェックなし
    playingList.push_back(gemGetSE);
    PlaySoundMem(gemGetSE, DX_PLAYTYPE_BACK, true);
}

/// <summary>
/// クリアシーンのBGMを再生
/// </summary>
void SoundManager::PlayClearSceneBGM()
{
    if (!CheckSoundMem(clearSceneBGM))
    {
        playingList.push_back(clearSceneBGM);
        PlaySoundMem(clearSceneBGM, DX_PLAYTYPE_LOOP, true);
    }
}

/// <summary>
/// 花火が上がる音を再生
/// </summary>
void SoundManager::PlayFireWorksSE()
{
    if (!CheckSoundMem(fireworksSE))
    {
        playingList.push_back(fireworksSE);
        PlaySoundMem(fireworksSE, DX_PLAYTYPE_LOOP, true);
    }
}
