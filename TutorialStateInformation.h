#pragma once

/// <summary>
/// チュートリアルごとの情報
/// </summary>
class TutorialStateInformation
{
public:
    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    TutorialStateInformation();

    /// <summary>
    /// 引数付きコンストラクタ
    /// </summary>
    /// <param name="_infoImageHandle">説明画像ハンドル</param>
    TutorialStateInformation(int _infoImageHandle);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TutorialStateInformation();

    int infoImageHandle;        // 説明画像ハンドル
private:

};


