#pragma once
#include "SceneBase.h"

class Title : public SceneBase
{
private:

	bool endFlag;							//	シーンが終了したかどうかのフラグ変数
	SceneType nextScene;					//	次のシーンを変数に入れる

public:

	//	コンストラクタ
	//	中でそれぞれの初期値を入れる
	Title()
	{
		this->endFlag = false;
		this->nextScene = SceneType::Game;	
	}
	//	デストラクタ
	virtual ~Title() {}

	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};
