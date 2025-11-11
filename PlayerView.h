#pragma once
#include <iostream>
#include "PlayerModel.h"

//	プレイヤーに関する描画のクラス
class PlayerView
{
public:

	//	プレイヤーの描画処理
	void DisplayStatus( std::shared_ptr<PlayerModel> model)
	{
		//	プレイヤーが存在していないときはリターンを返し描画しない
		if (!model) return;

		//	HPが０以上の時に
		if (!model->IsDead())
		{
			//	プレイヤーのステータスを描画
			printf("Playerの体力：%d, Playerの攻撃力：%d, Playerの防御力：%d\n", 
				model->GetHP(), model->GetATK(), model->GetDEF());

			//	出力coutでやるべき
			//	統一しましょうねー


		}
		else {		//	HPが０になったとき
			//	文字の描画
			printf("プレイヤーは倒れた！");
		}
	}

	//	逃げ出したメッセージ
	void DispMassageRun()
	{
		std::cout << "プレイヤーは逃げ出した！！！！！" << std::endl;
	}

	//	被弾メッセ
	void DispMassageTakeDamage(const int value)
	{
		std::cout << value << "のダメージを受けてしまった！！" << std::endl;
	}
};
