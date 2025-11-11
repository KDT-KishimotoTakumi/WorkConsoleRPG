#include "Game.h"

void GameScene::Update()
{
	//	ランダムにする（乱数の使用）
//	srand(time(NULL));

	//	ゲームの状態管理用switch文
	switch (state)
	{

	case GameState::PlayerTurn:	//	待機状態（プレイヤーの入力待ち）
	{
		

		//	プレイヤーの入力処理を呼び出す
		auto action = playerControllerPtr->GetInput();

		//	入力による攻撃処理の分岐switch文
		switch (action)
		{
		case PlayerAction::Attack:							//	通常攻撃
			playerControllerPtr->Attack(enemy_ptr);			//	通常攻撃時の処理を呼び出す
			state = GameState::CheckEnemyAlive;				
			break;

		case PlayerAction::Skill:							//	スキル攻撃
			playerControllerPtr->SkillAttack(enemy_ptr);	//	スキル攻撃時の処理を呼び出す
			state = GameState::CheckEnemyAlive;				
			break;

		case PlayerAction::Run:								//	逃げる

			playerControllerPtr->Run();						//	逃げるときの処理を呼び出す
															//	呼び出してるの処理じゃないよね　これviewだよね

			state = GameState::End;							//	ゲーム終了状態に移行
		//	endFlag = true;									//	シーン終了判定
		//	nextScene = SceneType::Title;					//	タイトルシーンに移行
			//	シーン切り替えフラグと内部のステート切り替えフラグを同じ所で操作するな

			break;

		default:	//	無効なコマンド
			std::cout << "もう一度コマンドを選択してください。" << std::endl;
			break;
		}
		break;
	}

	case GameState::EnemyTurn:	//	敵のターン（敵の攻撃処理）
	{
	

		//	敵が存在しているとき
		if (enemy_ptr)
		{
			std::cout << enemy_ptr->name << "の攻撃！" << std::endl;

			//	ダメージ処理
			//	エネミーの攻撃
			//	プレイヤーに防御力がマイナスされた分のダメージを与える
			int damage = enemy_ptr->atk - playerControllerPtr->GetModel()->GetDEF();
			//	ダメージコントロール処理を呼び出される
			//	PlayerViewにダメージを追った分の値を表示するため
			playerControllerPtr->TakeDamage(damage);

			
		}

		//	そのまま攻撃ターンにもう一度移行
		state = GameState::CheckPlayerAlive;
		break;
	}

	case GameState::CheckEnemyAlive:	//	敵の生存確認
	{
		std::cout << "敵の攻撃ターン！" << std::endl;

		//	敵が倒れたかどうかの判定
		if (enemy_ptr && enemy_ptr->hp <= 0)
		{
			//	敵が倒れた処理が呼び出された場合
			if (enemy_ptr->IsDead())
			{
				endFlag = true;					//	シーン終了判定
				nextScene = SceneType::Clear;	//	クリアシーンに移行
				return;
			}
		}

		//	敵が倒れていない場合は敵のターンに移行
		state = GameState::EnemyTurn;
		break;
	}


	case GameState::CheckPlayerAlive: //　プレイヤーの生存確認
	{
		//	プレイヤーがやられたとき
		if (playerControllerPtr->IsDead())
		{
			endFlag = true;					//	シーン終了判定
			nextScene = SceneType::Over;	//	ゲームオーバーシーンに移行
			return;
		}
		state = GameState::PlayerTurn;
		break;
	}


	case GameState::End:	//	ゲームが終了した時（逃げるが選択されたとき）
		std::cout << "ゲーム終了!!" << std::endl;

		char a;
		std::cin >> a;

		if (a) {
			endFlag = true;					//	シーン終了判定
			nextScene = SceneType::Title;	//	タイトルに移行
		}

		break;
	}
}

//	描画用メソッド
void GameScene::Draw()
{
	std::cout << "///////////////////////////////////" << std::endl;
	playerControllerPtr->Draw();  // MVC化されたプレイヤー描画
	enemy_ptr->Draw();			  // 敵は従来通り

	//	攻撃ターンの時に描画する
	if (state == GameState::PlayerTurn)
	{
		std::cout << "コマンドを選択" << std::endl;
		std::cout << "１：攻撃 攻撃力：" << playerControllerPtr->GetModel()->GetATK() << std::endl;
		std::cout << "２：攻撃スキル 攻撃力：" << playerControllerPtr->GetModel()->GetATK() * 2 << std::endl;
		std::cout << "３：逃げる ゲーム終了" << std::endl;
	}
}
