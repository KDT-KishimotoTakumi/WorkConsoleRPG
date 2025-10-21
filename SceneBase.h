#pragma once
#include "SceneType.h"

class SceneBase
{
public:

	//	仮想コンストラクタ
	SceneBase() {}
	
	//	仮想デストラクタ
	virtual ~SceneBase() {}

	//	更新処理
	//	描画処理
	//	純粋仮想関数で定義
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//	シーンが終わったかどうかの判定用関数
	virtual bool IsEnd() = 0;

	//	次のシーンを取得する関数
	virtual SceneType NextScene() const = 0;
};