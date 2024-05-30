#pragma once


#include "DxLib.h"

class Game;
class Player;

class UI
{
public:
	UI();		// コンストラクタ
	~UI();		// デストラクタ

	void Initialize();		// 初期化
	void Draw(int state,Player& player,bool clearFlag);	// 描画


private:
	// 定数

	// 変数
	int		menuGraph;		// メニュー画像
	int		menuSentenceGraph;	// メニュー説明画像
	int		titleGraph;		// タイトル画像
	int		overGraph;		// ゲームオーバー画像
	int		clearGraph;		// クリア画像
	int		timeLimitGraph;	// 制限時間画像
	int		frameGraph;		// 枠の画像
	int		playSentenceGraph;	// 操作説明画像
	int		greatGraph;			// グレイト！文字画像
	int		bloodGraph;		// 血のり画像
	int		bloodPosY;		// 血のり画像を描画するY位置
	double	clearCount;		// ゲームクリアしてからのカウント
	bool	countMaxFlag;	// カウント制限フラグ

	float	sizeRate;		// 大きさ

	
	// スコア
	float	distanceTraveled;	// 進んだ距離（メートルという設定）


};






