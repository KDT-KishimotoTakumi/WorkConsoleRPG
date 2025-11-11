#include "GameTitle.h"
#include <iostream>

void Title::Update()
{
	//	入力判定用変数
	int input;
	//	入力を取得
	std::cin >> input;
	//	１が入力されたときにゲームシーンに移行する
	if (input == 1) {
		nextScene = SceneType::Game;
		endFlag = true;	//	シーン終了判定にする
	}
	else if (input == 2) {	//	２が入力されたときゲームを終了する
		nextScene = SceneType::Exit;
		endFlag = true;	//	シーン終了判定にする
	}
}

void Title::Draw()
{
	//	画面をクリアと文字の描画
	system("cls");
	std::cout << "タイトル画面" << std::endl;
	std::cout << "１：ゲームスタート" << std::endl;
	std::cout << "２：ゲーム終了" << std::endl;
}
