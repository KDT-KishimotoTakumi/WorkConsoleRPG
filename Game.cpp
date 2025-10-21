#include "Game.h"

void GameScene::Update()
{
	//	ランダムにする（乱数の使用）
	//	乱数系列の初期化
	//	このコードを書かないとrand()を使用するとき何回も同じ値が入ってくる（制御するため）
	srand(time(NULL));

	////	乱数値の取得
	//r = (rand() % 4) + 1;

	////	乱数の値を描画
	//printf("%d\n", r);

	switch (state) {
	case GameState::Wait:
		int input1;
		std::cin >> input1;

		if (input1 == 1) {
			Enemy_Ptr->hp -= player->atk;
			std::cout << "敵に" << player->atk << "ダメージを与えた！" << std::endl;
			state = GameState::PlayerTurn;
		}
		else if (input1 == 2) {
			Enemy_Ptr->hp -= player->atk * 2;	//	スキル
			std::cout << "敵に" << player->atk * 2 << "ダメージを与えた！" << std::endl;
			state = GameState::PlayerTurn;
		}
		else if (input1 == 3) {
			std::cout << "プレイヤーは逃げ出した！" << std::endl;
			endFlag = true;
			state = GameState::End;
			nextScene = SceneType::Title;
		}
		else //	無効なコマンドが選ばれた場合
		{
			std::cout << "無効なコマンドが選ばれた！" << std::endl;
		}
		break;


	case GameState::PlayerTurn:
		//	プレイヤーの攻撃処理
		std::cout << "プレイヤーの攻撃！" << std::endl;
		state = GameState::Wait;

		if (Enemy_Ptr) {
			if (Enemy_Ptr->hp <= 0) {
				Enemy_Ptr->IsDead();
			}
			if (Enemy_Ptr->IsDead())
			{
				endFlag = true;
				nextScene = SceneType::Clear;
				return;
			}
		}
		else {
			std::cout << "敵が見つかりません。" << std::endl;
		}

		//	敵のターンへ移行
		state = GameState::EnemyTurn;

		break;

	case GameState::EnemyTurn:

		if (Enemy_Ptr)
		{
			//	敵の攻撃処理
			std::cout << Enemy_Ptr->name << "の攻撃！" << std::endl;
			//	プレイヤーのHPを減らす
			player->hp -= Enemy_Ptr->atk - player->def;

			//	プレイヤーがやられたとき
			if (player->IsDead())
			{
				endFlag = true;
				nextScene = SceneType::Over;
				return;
			}
		}

		//	ターンを戻す
		state = GameState::Wait;
		break;

	case GameState::End:

		std::cout << "ゲーム終了!!" << std::endl;
		endFlag = true;
		nextScene = SceneType::Title;
		break;
	}
}

void GameScene::Draw()
{
	//	プレイヤーの更新処理を呼び出す
	player->Draw();
	//	敵の更新処理を呼び出す
	Enemy_Ptr->Draw();

	switch (state)
	{
	case GameState::Wait:
		std::cout << "プレイヤーのターン" << std::endl;
		std::cout << "１：攻撃 攻撃力：" << player->atk << std::endl;
		std::cout << "２：攻撃スキル 攻撃力：" << player->atk * 2 << std::endl;
		std::cout << "３：逃げる ゲーム終了" << std::endl;
		break;
	}
}
