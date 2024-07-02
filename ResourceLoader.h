#include "commapi.h"

/// <summary>
/// リソースのロード(シングルトン)
/// </summary>
class ResourceLoader
{
public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ResourceLoader();

    /// <summary>
    /// インスタンの作成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// リソースローダーのインスタンスのアドレスを渡す
    /// </summary>
    static void GetInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

private:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    ResourceLoader();

    // 変数
    ResourceLoader* resourceLoader;

};


