#pragma once
#include "SceneBase.h"
#include <iostream>
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Player.h"

//	================================
//	ターン処理とプレイヤーと敵の処理
//	================================

//	ゲームの状態を管理するクラス（ターン管理クラス）
enum class GameState
{
	PlayerTurn,		//	プレイヤーのターン
	EnemyTurn,		//	敵のターン
	Wait,			//	待機	
	End				//	終了
};

class GameScene : public SceneBase
{
	std::shared_ptr<Enemy> Enemy_Ptr;	//	敵のポインタ変数
	Player* player;

private:
	bool endFlag;					//	シーンが終了したかどうかのフラグ変数
	SceneType nextScene;			//	次のシーンを変数に入れる

	GameState state;				//	ゲームの状態管理変数

public:

	//	コンストラクタ
	//	中でそれぞれの初期値を入れる
	//	プレイヤーはインスタンスを取得
	GameScene()
	{
		this->endFlag = false;
		this->nextScene = SceneType::Clear;
		this->state = GameState::Wait;
		this->Enemy_Ptr = EnemyFactory::CreateEnemy((rand() % 4) + 1);
		player = Player::GetInstance();
	}

	//	デストラクタ
	virtual ~GameScene() {}
	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};