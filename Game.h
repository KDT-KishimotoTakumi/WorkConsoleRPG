#pragma once
#include "SceneBase.h"
#include <iostream>
#include "Enemy.h"
#include "EnemyFactory.h"
#include "PlayerController.h"

//	================================
//	ターン処理とプレイヤーと敵の処理
//	================================

//	ゲームの状態を管理するクラス（ターン管理クラス）
enum class GameState
{
	PlayerTurn,				//	プレイヤーの入力待機ターン
	EnemyTurn,				//	敵のターン
	CheckEnemyAlive,		//	敵の生存確認
	CheckPlayerAlive,		//	プレイヤーの生存確認
	Runaway,				//	逃げる
	End						//	終了
};

class GameScene : public SceneBase
{
	std::shared_ptr<Enemy> enemy_ptr;						//	敵のポインタ変数
	std::unique_ptr<PlayerController> playerControllerPtr;	//	プレイヤーコントローラーのポインタ変数

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
		this->state = GameState::PlayerTurn;
		this->enemy_ptr = EnemyFactory::CreateEnemy((rand() % 4) + 1);
		this->playerControllerPtr = std::make_unique<PlayerController>();
	}

	//	デストラクタ
	virtual ~GameScene() {}
	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};