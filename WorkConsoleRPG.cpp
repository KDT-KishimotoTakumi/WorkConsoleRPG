// WorkConsoleRPG.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <memory>

#include "SceneBase.h"
#include "SceneType.h"
#include "GameTitle.h"
#include "Game.h"
#include "GameOver.h"
#include "GameClear.h"

int main()
{
	////	ランダムにする（乱数の使用）
	////	乱数系列の初期化
	////	このコードを書かないとrand()を使用するとき何回も同じ値が入ってくる（制御するため）
	//srand(time(NULL));

	////	乱数値の取得
	//int r = (rand() % 4) + 1;

	////	乱数の値を描画
	//printf("%d\n", r);

 //   //  プレイヤーのシングルトンインスタンスを取得
	//Player* player = Player::GetInstance();

	////	プレイヤーの更新処理を呼び出す
	//player->Update();

	////	ランダムで表示する
	//std::shared_ptr<Enemy> enemy = EnemyFactory::CreateEnemy(r);

	//if (enemy) {
	//	//	敵の更新処理を呼び出す
	//	enemy->Update();
	//}
	//else {
	//	std::cout << "敵が見つかりません。" << std::endl;
	//}

	//	シーン管理のオブジェクト化
	//	最初のシーンはタイトルにする
	std::unique_ptr<SceneBase> ScenePtr = std::make_unique<Title>();
	SceneType currentScene = SceneType::Title;

	//	メインループ
	while (true)
	{
		//	処理を呼び出す
		ScenePtr->Draw();
		ScenePtr->Update();

		if (ScenePtr->IsEnd())
		{
			SceneType nextScene = ScenePtr->NextScene();

			//	シーンに合わせてそれぞれオブジェクト化を行う
			switch (nextScene)
			{
			case SceneType::Title:
				ScenePtr = std::make_unique<Title>();
				break;
			case SceneType::Game:
				ScenePtr = std::make_unique<GameScene>();
				break;
			case SceneType::Over:
				ScenePtr = std::make_unique<GameOver>();
				break;
			case SceneType::Clear:
				ScenePtr = std::make_unique<GameClear>();
				break;

			case SceneType::Exit:
				std::cout << "ゲームを終了" << std::endl;
				return 0;
			}

			//	現在のシーンを更新
			currentScene = nextScene;
		}
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
