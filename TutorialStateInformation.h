#pragma once

/// <summary>
/// チュートリアルごとの情報
/// </summary>
/// TODO:今後チュートリアル画像を動かしたい時にposition、
///      説明用矢印もこのクラスに持たせたいが、時間がないため未実装
///      修正期日：7/10以降
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


