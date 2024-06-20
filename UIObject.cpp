#include "UIObject.h"

/// <summary>
/// コンストラクタ
/// </summary>
UIObject::UIObject(char* _graphHandle, VECTOR initPos)
    : isResetPosition   (false)
{
    graphHandle = LoadGraph(_graphHandle);
    position = initPos;
}

/// <summary>
/// デストラクタ
/// </summary>
UIObject::~UIObject()
{
    DeleteGraph(graphHandle);
}
