#pragma once

/// <summary>
/// メニューシーンUI
/// </summary>
class MenuSceneUI
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    MenuSceneUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~MenuSceneUI();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:
    int menuGraph;      // メニューで使用する画像

};


