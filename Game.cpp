#include "Game.h"

void GameScene::Update()
{
	//	ランダムにする（乱数の使用）
	srand(time(NULL));

	//	ゲームの状態管理用switch文
	switch (state)
	{
	case GameState::PlayerTurn:	//	待機状態（プレイヤーの入力待ち）
	{
		//	プレイヤーの入力処理を呼び出す
		Action = PlayerControllerPtr->GetInput();

		//	入力による攻撃処理の分岐switch文
		switch (Action)
		{
		case PlayerAction::Attack:							//	通常攻撃
			PlayerControllerPtr->Attack(Enemy_Ptr);			//	通常攻撃時の処理を呼び出す
			state = GameState::AttackTurn;					//	攻撃ターンに移行
			break;

		case PlayerAction::Skill:							//	スキル攻撃
			PlayerControllerPtr->SkillAttack(Enemy_Ptr);	//	スキル攻撃時の処理を呼び出す
			state = GameState::AttackTurn;					//	攻撃ターンに移行
			break;

		case PlayerAction::Run:								//	逃げる
			PlayerControllerPtr->Run();						//	逃げるときの処理を呼び出す
			endFlag = true;									//	シーン終了判定
			state = GameState::End;							//	ゲーム終了状態に移行
			nextScene = SceneType::Title;					//	タイトルシーンに移行
			break;

		default:	//	無効なコマンド
			std::cout << "もう一度コマンドを選択してください。" << std::endl;
			break;
		}
		break;
	}

	case GameState::AttackTurn:	//	攻撃ターン（プレイヤー及び敵の攻撃処理）
	{
		std::cout << "敵の攻撃ターン！" << std::endl;

		//	敵が倒れたかどうかの判定
		if (Enemy_Ptr && Enemy_Ptr->hp <= 0)
		{
			//	敵が倒れた処理が呼び出された場合
			if (Enemy_Ptr->IsDead())
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

	case GameState::EnemyTurn:	//	敵のターン（敵の攻撃処理）
	{
		//	敵が存在しているとき
		if (Enemy_Ptr)
		{
			std::cout << Enemy_Ptr->name << "の攻撃！" << std::endl;

			//	ダメージ処理
			//	エネミーの攻撃
			//	プレイヤーに防御力がマイナスされた分のダメージを与える
			int damage = Enemy_Ptr->atk - PlayerControllerPtr->GetModel()->GetDEF();
			//	ダメージコントロール処理を呼び出される
			//	PlayerViewにダメージを追った分の値を表示するため
			PlayerControllerPtr->TakeDamage(damage);

			//	プレイヤーがやられたとき
			if (PlayerControllerPtr->IsDead())
			{
				endFlag = true;					//	シーン終了判定
				nextScene = SceneType::Over;	//	ゲームオーバーシーンに移行
				return;
			}
		}

		//	そのまま攻撃ターンにもう一度移行
		state = GameState::AttackTurn;
		break;
	}

	case GameState::End:	//	ゲームが終了した時（逃げるが選択されたとき）
		std::cout << "ゲーム終了!!" << std::endl;
		endFlag = true;					//	シーン終了判定
		nextScene = SceneType::Title;	//	タイトルに移行
		break;
	}
}

void GameScene::Draw()
{
	PlayerControllerPtr->Draw();  // MVC化されたプレイヤー描画
	Enemy_Ptr->Draw();			  // 敵は従来通り

	//	攻撃ターンの時に描画する
	if (state == GameState::AttackTurn)
	{
		std::cout << "コマンドを選択" << std::endl;
		std::cout << "１：攻撃 攻撃力：" << PlayerControllerPtr->GetModel()->GetATK() << std::endl;
		std::cout << "２：攻撃スキル 攻撃力：" << PlayerControllerPtr->GetModel()->GetATK() * 2 << std::endl;
		std::cout << "３：逃げる ゲーム終了" << std::endl;
	}
}
