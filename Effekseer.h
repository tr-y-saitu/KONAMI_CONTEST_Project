#pragma once


class Effekseer1
{
public:
	Effekseer1();
	~Effekseer1();
	void ReadyEffekseerForDXLib();	// エフェクシアを使う準備
	void Initialize();
	void Update();
	void Draw();
	int		effectResourceHandle;		// エフェクトリソース
	int		graphBackGroundHandle;		// 背景画像
	int		graphFrontHandle;			// 手前画像
	int		time;						// 定期的にエフェクトを再生する時間
	bool	isFullScreen;				// フルスクリーン切り替えようフラグ
	VECTOR	pos;						// エフェクトを描画する位置
	int		playingEffectHandle;		// 再生中のエフェクトハンドル

private:



};

