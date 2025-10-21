#pragma once
#include "EnemyData.h"

//	�O���錾
class Enemy;

//	�G�N���X�̐������s���t�@�N�g���N���X
class EnemyFactory
{
public:

	//	�G�̃f�[�^���i�[����e�[�u��
	static const EnemyData EnemyTable[];
	//	�G�̃f�[�^�e�[�u���̗v�f
	static const int EnemyTableSize;

	// @brief �w�肳�ꂽ ID �Ɋ�Â��ēG�𐶐����܂��B
	// @param [in] ID �G�� ID
	// @return �������ꂽ�G�̃|�C���^�BID ��������Ȃ������ꍇ�� nullptr ��Ԃ��܂��B
	// @details
	// ���̃��\�b�h�́A�w�肳�ꂽ ID �Ɋ�Â��ēG�𐶐����܂��B
	// ID ��������Ȃ������ꍇ�� nullptr ��Ԃ��܂��B
	static std::shared_ptr<Enemy> CreateEnemy(int ID);
};