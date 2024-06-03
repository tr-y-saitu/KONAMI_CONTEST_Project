#include "BackGroundObject.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
BGObj::BGObj()
    :returnPosX     (3000)
    ,scrollSpeed   (4)
{
    // ���W�ݒ�
    pos = VGet(0, 100, 800);
    // �����ݒ�
    dir = VGet(0, 0, 0);
    // �X�P�[����ݒ�
    scale = VGet(1, 1, 1);

    pos2 = VGet(0, 0, 0);

    // �w�i�摜�̓ǂݍ���
    graphHandle = LoadGraph("data/texture/�X�N���[���V���b�g (4).png");
    graphUniverse= LoadGraph("data/texture/OIP (10).jpg");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
BGObj::~BGObj()
{
    // ���f���n���h���̍폜
    MV1DeleteModel(modelHandle);
}

/// <summary>
/// ������
/// </summary>
/// <param name="graphHnadle">�O���t�n���h��</param>
void BGObj::Initialize(int graph, int texture,VECTOR initVec,int speed)
{
    // ���f���n���h���̐ݒ�
    modelHandle = graph;

    // �e�N�X�`���̐ݒ�
    texrureHandle = texture;

    // ���f���n���h���ɐݒ肵�����e�N�X�`����\��t��
    MV1SetTextureGraphHandle(modelHandle, 0, texrureHandle, true);

    // ���f���̃X�P�[����ݒ�
    MV1SetScale(modelHandle, scale);

    // ���W�ݒ�
    pos = initVec;

    // �����ݒ�
    dir = VGet(0, 0, 0);

    pos2 = VGet(0, 0, 0);

    // �s��ɒP�ʍs�����
    matrix = MGetIdent();

}

/// <summary>
/// �X�V
/// </summary>
void BGObj::Update()
{
    // �����Ɖ�]�ړ����Ă��Ăق���
    
    // MATRIX�Ɋp�x���w��
    //matrix = MGetRotY(DX_PI_F / 4.0f);  // (45�x��]����s��)
    // MATRIX���A������pos��ϊ������� 
    //pos = VTransform(pos, matrix);  // matrix�ɂ͉�]�s������Ă���̂ŉ�]����
    

    //// �w�莲�����ɉ�]����s����擾
    //matrix = MGetRotAxis(VGet(0, 0, 0), DX_PI_F / 180.0f);
    //// matrix���A�����̍��W��ϊ��i��]�j
    //pos = VTransform(pos, matrix);

    dir = VGet(-1, 0, 0);


    // ���K��
    if (VSquareSize(dir) > 0)
    {
        dir = VNorm(dir);
    }

    auto velocity = VScale(dir, scrollSpeed);
         
    // ��ʒ[�ɍs���Ă��܂�����
    if (pos.x <= -returnPosX)
    {
        pos.x = returnPosX;
    }

    pos = VAdd(pos, velocity);

    // ���f���̊g�嗦���Z�b�g
    //MV1SetScale(modelHandle, VGet(2, 2, 2));

    // 3D���f���̃|�W�V������ݒ�
    MV1SetPosition(modelHandle,pos);
    

}


/// <summary>
/// �`��
/// </summary>
void BGObj::Draw()
{
    // ���f���̕`��
    MV1DrawModel(modelHandle);

    //MV1DrawMesh(modelHandle, 0);

    // 3D��Ԃɉ摜��`��
    //DrawBillboard3D(VGet(3000, 0, 500), 0.5f, 0.5f, 2000.0f, 0.0f, graphHandle, true);

    // 3D��ԏ��2�����I�ȕό`���������摜��`��
   /* DrawModiBillboard3D(VGet(320.0f, 240.0f, 100.0f),
        -100.0f, 200.0f,
        100.0f, 200.0f,
        100.0f, -200.0f,
        -100.0f, -200.0f, graphUniverse, TRUE);*/


}
