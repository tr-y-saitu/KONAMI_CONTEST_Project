// 2023 Takeru Yui All Rights Reserved.
#pragma once
#include <vector>

class WorldSprite;

/// <summary>
/// 2D�̔w�i�}�b�v
/// </summary>
class Map
{
public:
	Map();
	~Map();

	void Load(int stageNo);
	void Update();
	void Draw();

	// �}�b�v�`�b�v�̃T�C�Y
	static const float	ChipSize;
	static const int	ChipPixelSize;

private:
	static const int	StageData1ColNum = 16;		// �}�b�v�s
	static const int	StageData1RowNum = 20;		// �}�b�v��
	static const int	Stage1Data[StageData1ColNum][StageData1RowNum];
	static const int	StageData2ColNum = 14;		// �}�b�v�s
	static const int	StageData2RowNum = 18;		// �}�b�v��
	static const int	Stage2Data[StageData2ColNum][StageData2RowNum];

	std::vector<std::vector<int>> currentData;
	int dataColNum = 0;		// ���ۂɎg�p����}�b�v�̍s��
	int dataRowNum = 0;		// ���ۂɎg�p����}�b�v�̗�
	std::vector<WorldSprite*> sprites;
	int chipGraph;
};

