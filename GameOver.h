#pragma once
#include "SceneBase.h"

class GameOver : public SceneBase
{
private:
	bool endFlag;					//	シーンが終了したかどうかのフラグ変数
	SceneType nextScene;			//	次のシーンを変数に入れる

public:
	//	コンストラクタ
	//	中でそれぞれの初期値を入れる
	GameOver()
	{
		this->endFlag = false;
		this->nextScene = SceneType::Title;
	}
	//	デストラクタ
	virtual ~GameOver() {}
	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};