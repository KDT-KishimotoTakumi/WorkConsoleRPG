#include <iostream>
#include "EnemyFactory.h"
#include "Enemy.h"

//	データテーブルの中身（EnemyDataで定義した順番に記入）
//	エネミーの情報をここで定義
const EnemyData EnemyFactory::EnemyTable[] = {
	{ 1, "Slime", 10, 5 },
	{ 2, "Goblin", 20, 10},
	{ 3, "Orc", 30, 15},
	{ 4, "Dragon", 100, 30}
};

//	構造体を割った値を求める（40 / 4)
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

std::shared_ptr<Enemy> EnemyFactory::CreateEnemy(int ID)
{
	for (int i = 0; i < EnemyTableSize; ++i) {
		if (EnemyTable[i].id == ID) {
			return std::make_shared<Enemy>(EnemyTable[i]);
		}
	}

	return nullptr;
}
