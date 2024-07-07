#include "Common.h"
#include "TutorialStateInformation.h"

/// <summary>
/// コンストラクタ
/// </summary>
TutorialStateInformation::TutorialStateInformation()
{
    // 処理なし
}

/// <summary>
/// 引数付きコンストラクタ
/// </summary>
/// <param name="imageHandle">画像ハンドル</param>
TutorialStateInformation::TutorialStateInformation(int _infoImageHandle)

    : infoImageHandle       (_infoImageHandle)
{
    // 処理なし
}


/// <summary>
/// デストラクタ
/// </summary>
TutorialStateInformation::~TutorialStateInformation()
{
    DeleteGraph(infoImageHandle);
}
