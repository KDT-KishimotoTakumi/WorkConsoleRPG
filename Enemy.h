#pragma once
#include <iostream>
#include "EnemyData.h"

//	�G�N���X�̕�̃N���X
class Enemy
{

public:

	//	�X�e�[�^�X�ϐ�
	int id;				//	�G��ID
	const char* name;	//	�G�̖��O
	int hp;				//	�̗�
	int atk;			//	�U����

	//	�R�s�[�E����̋֎~
	Enemy(const Enemy&) = delete;
	Enemy& operator=(const Enemy&) = delete;

	//	�V���O���g���C���X�^���X���擾����֐�
	static	Enemy* GetInstance(const EnemyData& data)
	{
		//	�V���O���g���C���X�^���X�̐���
		static Enemy instance(data);
		//	�C���X�^���X�̃|�C���^��Ԃ�
		return &instance;
	}

	//	�����R���X�g���N�^
	//	EnemyData�\���̂������Ɏ��
	Enemy(const EnemyData& data)
		: id(data.id), name(data.name), hp(data.hp), atk(data.atk)
	{
	}

	//	�f�X�g���N�^
	virtual ~Enemy() {}

	//	�G�̍X�V����
	virtual void Draw()
	{
		//	HP���O���傫���ꍇ�̂ݕ\��
		if (this->hp > 0)
			//	Enemy�̃X�e�[�^�X��\��
			printf("Enemy�̖��O�F % s, Enemy�̗̑́F % d, Enemy�̍U���́F % d\n",
				this->name, this->hp, this->atk);
	}
	//	�G�����񂾂��ǂ����̔���p�֐�
	virtual bool IsDead()
	{
		//	HP���O�ɂȂ��������
		if (this->hp <= 0) {
			std::cout << this->name << "�͓|�ꂽ�I" << std::endl;
		}

		return (this->hp <= 0);
	}

	virtual void Damage()
	{
		std::cout << this->name << "�̓_���[�W���󂯂��I" << std::endl;
	}
};
