#include "Tutorial.h"
#include "TutorialStateInformation.h"
#include "Common.h"
#include "GemManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
Tutorial::Tutorial()
    : tutorialState             (START_TUTORIAL)
    , tutorialLastUpdateTime    (GetNowCount())
    , drawImageHandle           (0)
    , arrwoOffSet               (0)
{
    tutorialFrameGraph = LoadGraph("data/texture/Clear/FrameUINoClearColor.png");
    fireImageHandle = LoadGraph("data/texture/Tutorial/1FireTutorial.png");
    moveImageHandle = LoadGraph("data/texture/Tutorial/2MoveTutorial.png");
    cushionImageHandle = LoadGraph("data/texture/Tutorial/3CushionTutorial.png");
    chestImageHandle = LoadGraph("data/texture/Tutorial/4ChestTutorial.png");
    gemBoundImageHandle = LoadGraph("data/texture/Tutorial/5GemBoundTutorial.png");
    endImageHandle = LoadGraph("data/texture/Tutorial/6EndTutorial.png");
    arrowImageHandle = LoadGraph("data/texture/Tutorial/arrowImage.png");

    tutorialInfomation[START_TUTORIAL] = new TutorialStateInformation(fireImageHandle);
    tutorialInfomation[FIRE_TUTORIAL] = new TutorialStateInformation(fireImageHandle);
    tutorialInfomation[MOVE_TUTORIAL] = new TutorialStateInformation(moveImageHandle);
    tutorialInfomation[CUSHION_TUTORIAL] = new TutorialStateInformation(cushionImageHandle);
    tutorialInfomation[CHEST_TUTORIAL] = new TutorialStateInformation(chestImageHandle);
    tutorialInfomation[GEM_BOUND_TUTORIAL] = new TutorialStateInformation(gemBoundImageHandle);
    tutorialInfomation[END_TUTORIAL] = new TutorialStateInformation(endImageHandle);
}

/// <summary>
/// デストラクタ
/// </summary>
Tutorial::~Tutorial()
{
    delete(tutorialInfomation[FIRE_TUTORIAL]);
    delete(tutorialInfomation[MOVE_TUTORIAL]);
    delete(tutorialInfomation[CUSHION_TUTORIAL]);
    delete(tutorialInfomation[GEM_BOUND_TUTORIAL]);
    delete(tutorialInfomation[END_TUTORIAL]);
}

/// <summary>
/// チュートリアル更新
/// </summary>
/// <param name="gemWaveState">現在の宝石のウェーブステート</param>
/// <param name="playerPosition">プレイヤーの座標</param>
void Tutorial::Update(int gemWaveState, VECTOR playerPosition)
{
    // ファーストウェーブのみチュートリアル
    if (gemWaveState == GemManager::WAVE_FIRST)
    {
        // フレームを描画
        DrawGraph(FRAME_POSITION_X, FRAME_POSITION_Y, tutorialFrameGraph, true);

        // 時間を計測
        int _nowTime = GetNowCount();

        // ステート切り替え
        if (_nowTime - tutorialLastUpdateTime >= TUTORIAL_UPDATE_INTERVAL)
        {
            tutorialState++;                    // ステート更新
            tutorialLastUpdateTime = _nowTime;  // 更新時間のリセット
            // チュートリアル画像の更新
            drawImageHandle = tutorialInfomation[(TutorialState)tutorialState]->infoImageHandle;
        }

        // 現在のステートのチュートリアル画像を描画
        DrawRotaGraph(SCREEN_SIZE_X_HALF, SCREEN_SIZE_Y_HALF,
            TUTORIAL_IMAGE_EXPAND_RATE,TUTORIAL_IMAGE_ANGLE, drawImageHandle, true);

        // 矢印の更新
        UpdateArrow(playerPosition);
    }
}

/// <summary>
/// 矢印の更新
/// </summary>
/// <param name="position"></param>
void Tutorial::UpdateArrow(VECTOR position)
{
    // 矢印の描画
    switch (tutorialState)
    {
    case CUSHION_TUTORIAL:
        // 2D画像を3D空間上に描画
        DrawBillboard3D(position, CUSHION_TUTORIAL_OFFSET_X, CUSHION_TUTORIAL_OFFSET_Y - arrwoOffSet,
            CUSHION_TITPROAL_SIZE, TUTORIAL_ARROW_ANGLE, arrowImageHandle, true);
        break;

    case CHEST_TUTORIAL:
        // 2D画像を3D空間上に描画
        DrawBillboard3D(CHEST_TUTORIAL_ARROW_POSITION, CHEST_TUTORIAL_OFFSET_X, CHEST_TUTORIAL_OFFSET_Y - arrwoOffSet,
            CHEST_TUTORIAL_SIZE, TUTORIAL_ARROW_ANGLE, arrowImageHandle, true);
        break;

    default:
        break;
    }

    // 矢印を動かす
    if (arrwoOffSet <= ARROW_OFFSET_LIMIT)
    {
        arrwoOffSet += ARROW_OFFSET_ANIMATION_SPEED;    // 再生
    }
    else
    {
        arrwoOffSet = 0;    // 初期化
    }
}
