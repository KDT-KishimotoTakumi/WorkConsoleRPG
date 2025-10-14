#pragma once
#include <string>

//	敵データ構造体
struct EnemyData
{
	//	敵のデータ
	//	3種類の敵を作成する予定なので、IDは0～2まで
	int id;				//	敵のID
	const char* name;	//	敵の名前
	int hp;				//	体力
	int atk;			//	攻撃力
};
