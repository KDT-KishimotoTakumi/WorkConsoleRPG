#pragma once
#include <iostream>
#include "PlayerModel.h"

class PlayerView
{
public:

	//	プレイヤーの描画処理
	void DisplayStatus(const PlayerModel* player)
	{
		//	プレイヤーが存在していないときはリターンを返し描画しない
		if (!player) return;

		//	HPが０以上の時に
		if (player->GetHP() > 0)
		{
			//	プレイヤーのステータスを描画
			printf("Playerの体力：%d, Playerの攻撃力：%d, Playerの防御力：%d\n", 
				player->GetHP(), player->GetATK(), player->GetDEF());
		}
		else {		//	HPが０になったとき
			//	文字の描画
			printf("プレイヤーは倒れた！");
		}
	}
};
