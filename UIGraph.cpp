#include "UIGraph.h"

/// <summary>
/// コンストラクタ
/// </summary>
UIGraph::UIGraph(char* _graphHandle, VECTOR initPos)
    : isResetPosition   (false)
{
    graphHandle = LoadGraph(_graphHandle);
    position = initPos;
}

/// <summary>
/// デストラクタ
/// </summary>
UIGraph::~UIGraph()
{
    DeleteGraph(graphHandle);
}
