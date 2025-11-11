#pragma once
#include "SceneBase.h"
#include <iostream>
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Player.h"
#include "PlayerController.h"

//	================================
//	ターン処理とプレイヤーと敵の処理
//	================================

//	ゲームの状態を管理するクラス（ターン管理クラス）
enum class GameState
{
	AttackTurn,		//	攻撃ターン
	EnemyTurn,		//	敵のターン
	PlayerTurn,		//	プレイヤーの入力待機ターン
	End				//	終了
};

class GameScene : public SceneBase
{
	std::shared_ptr<Enemy> Enemy_Ptr;						//	敵のポインタ変数
	Player* player;											//	プレイヤーのポインタ変数（後でコメント）
	std::unique_ptr<PlayerController> PlayerControllerPtr;	//	プレイヤーコントローラーのポインタ変数
	PlayerAction Action;					//	プレイヤーの行動変数

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
		this->state = GameState::AttackTurn;
		this->Enemy_Ptr = EnemyFactory::CreateEnemy((rand() % 4) + 1);
		this->player = Player::GetInstance();
		this->PlayerControllerPtr = std::make_unique<PlayerController>();
		this->Action = PlayerAction::None;
	}

	//	デストラクタ
	virtual ~GameScene() {}
	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};