#include <iostream>
#include "EnemyFactory.h"
#include "Enemy.h"

//	�f�[�^�e�[�u���̒��g�iEnemyData�Œ�`�������ԂɋL���j
//	�G�l�~�[�̏��������Œ�`
const EnemyData EnemyFactory::EnemyTable[] = {
	{ 1, "Slime", 10, 5 },
	{ 2, "Goblin", 20, 10},
	{ 3, "Orc", 30, 15},
	{ 4, "Dragon", 100, 30}
};

//	�\���̂��������l�����߂�i40 / 4)
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
