#include "WorldSprite.h"

/// <summary>
/// ������
/// </summary>
/// <param name="textureGraph">�e�N�X�`���̉摜�n���h��</param>
/// <param name="chipPixelSize">�X�v���C�g�̂P�`�b�v�̃s�N�Z���T�C�Y</param>
/// <param name="spriteNo">�X�v���C�g�ԍ�</param>
void WorldSprite::Initialize(int textureGraph, int chipPixelSize, int spriteNo)
{
    this->textureGraph = textureGraph;

    // NOTE:���������ɌŒ肵�Ă��邪�A�ύX��������Ύ����Ŋ֐���ǉ�����K�v������
    // �S���_����uv�f�[�^��ݒ�
    int texW, texH;
    GetGraphTextureSize(textureGraph, &texW, &texH);
    int chipNum = texW / chipPixelSize;
    int chipNoX = spriteNo % chipNum;
    int chipNoY = spriteNo / chipNum;
    float oneChipUVRate = 1.0f / (float)chipNum;   // �e�N�X�`���S����1.0�Ƃ�������cihp��ɑ΂���uv�̃T�C�Y
    Vertex[0].u = (chipNoX + 0.0f) * oneChipUVRate;     // �e�N�X�`���̍��W��ݒ�
    Vertex[0].v = (chipNoY + 0.0f) * oneChipUVRate;     // u�͉������W v�͏c�����W
    Vertex[1].u = (chipNoX + 1.0f) * oneChipUVRate;
    Vertex[1].v = (chipNoY + 0.0f) * oneChipUVRate;
    Vertex[2].u = (chipNoX + 0.0f) * oneChipUVRate;
    Vertex[2].v = (chipNoY + 1.0f) * oneChipUVRate;
    Vertex[3].u = (chipNoX + 1.0f) * oneChipUVRate;
    Vertex[3].v = (chipNoY + 1.0f) * oneChipUVRate;

    // �f�B�t���[�Y�A�X�y�L�����͏��������ɌŒ�
    // �f�B�t���[�Y���g�U���ˌ��@�@�������ĂĖ��邭����
    // �X�y�L�����@�����ʔ��ˌ��@�@�������\��
    // �m�����@�@�@���x�N�g���̒���
    for (int i = 0; i < 4; i++)
    {
        Vertex[i].dif = GetColorU8(255, 255, 255, 255);
        Vertex[i].spc = GetColorU8(0, 0, 0, 0);
        Vertex[i].norm = VGet(0.0f, 0.0f, -1.0f);   // ��]���T�|�[�g���Ȃ��̂Ńm�[�}�����Œ�

        // �⏕�e�N�X�`�����T�|�[�g���Ȃ��̂�uv�Œ�
        Vertex[i].su = 0.0f;
        Vertex[i].sv = 0.0f;
    }

    // �Q�|���S�����̃C���f�b�N�X�f�[�^���Z�b�g
    Index[0] = 0;
    Index[1] = 1;
    Index[2] = 2;
    Index[3] = 3;
    Index[4] = 2;
    Index[5] = 1;
}

/// <summary>
/// �T�C�Y�ƃ|�W�V�����ɉ����ĂS���_���̒��_�ʒu�𒲐�
/// </summary>
/// <param name="pos">�|�W�V����</param>
/// <param name="chipSize">�z�u���郏�[���h�X�v���C�g�̃T�C�Y</param>
void WorldSprite::SetTransform(const VECTOR& pos, float spriteSize)
{
    this->pos = pos;
    // �s�{�b�g���S�Őݒ�
    Vertex[0].pos = VScale(VGet(-1.0f, 1.0f, 0.0f), spriteSize * 0.5f);
    Vertex[1].pos = VScale(VGet(1.0f, 1.0f, 0.0f), spriteSize * 0.5f);
    Vertex[2].pos = VScale(VGet(-1.0, -1.0f, 0.0f), spriteSize * 0.5f);
    Vertex[3].pos = VScale(VGet(1.0f, -1.0f, 0.0f), spriteSize * 0.5f);
    for (int i = 0; i < 4; i++)
    {
        Vertex[i].pos = VAdd(Vertex[i].pos, pos);
    }
}

/// <summary>
/// �`��
/// </summary>
void WorldSprite::Draw()
{
    // �Q�|���S���̕`��(3D��ԂɎO�p�`�|���S���̏W����`�悷��)
    DrawPolygonIndexed3D(Vertex, 4, Index, 2, textureGraph, FALSE);
}