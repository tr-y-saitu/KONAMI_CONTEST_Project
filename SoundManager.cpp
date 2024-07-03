#include "SoundManager.h"

// 初期化
SoundManager* SoundManager::soundManager = NULL;

/// <summary>
/// コンストラクタ
/// </summary>
SoundManager::SoundManager()
    : playingSoundHandle        (0)
{
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
    pushuSE = LoadSoundMem("data/sound/");
    titleSceneBGM = LoadSoundMem("data/sound/TitleScene/TitleSceneBGM1.mp3");
    gameSceneBGM = LoadSoundMem("data/sound/GameScene/GameSceneBMG1.mp3");
    gemBoundSE = LoadSoundMem("data/sound/GameScene/gemHitSE2.mp3");
    gemGetSE = LoadSoundMem("data/sound/GameScene/gemGetSE.mp3");
    clearSceneBGM = LoadSoundMem("data/sound/ClearScene/gameClearSE.mp3");
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
/// ボタンを押したときの音を再生
/// </summary>
void SoundManager::PlayPushuSE()
{
    PlaySoundMem(pushuSE, DX_PLAYTYPE_BACK, true);
}

/// <summary>
/// タイトルシーンのBGMを再生
/// </summary>
void SoundManager::PlayTitleSceneBGM()
{
    PlaySoundMem(titleSceneBGM, DX_PLAYTYPE_LOOP, true);
}

/// <summary>
/// ゲームシーンのBGMを再生
/// </summary>
void SoundManager::PlayGameSceneBGM()
{
    PlaySoundMem(gameSceneBGM, DX_PLAYTYPE_LOOP, true);
}

/// <summary>
/// 宝石が跳ねた時の音を再生
/// </summary>
void SoundManager::PlayGemBoundSE()
{
    PlaySoundMem(gemBoundSE, DX_PLAYTYPE_BACK, true);
}

/// <summary>
/// 宝石を獲得した時の音を再生
/// </summary>
void SoundManager::PlayGemGetSE()
{
    PlaySoundMem(gemGetSE, DX_PLAYTYPE_BACK, true);
}

/// <summary>
/// クリアシーンのBGMを再生
/// </summary>
void SoundManager::PlayClearSceneBGM()
{
    PlaySoundMem(clearSceneBGM, DX_PLAYTYPE_LOOP, true);
}

/// <summary>
/// 花火が上がる音を再生
/// </summary>
void SoundManager::PlayFireWorksSE()
{
    PlaySoundMem(fireworksSE, DX_PLAYTYPE_LOOP, true);
}
