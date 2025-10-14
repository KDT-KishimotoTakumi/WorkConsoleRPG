#pragma once
#include <iostream>

class Player
{
public:

	//	�X�e�[�^�X�ϐ�
	int hp;			//	�̗�
	int atk;		//	�U����
	int def;	//	�h���

	//	�����R���X�g���N�^
	Player(int arg_hp, int arg_atk, int arg_def)
	{
		//	�X�e�[�^�X�ϐ��̏�����
		hp = arg_hp;
		atk = arg_atk;
		def = arg_def;
	}

	//	�f�X�g���N�^
	virtual ~Player() {}

	//	�R�s�[�E����̋֎~
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

	//	�V���O���g���C���X�^���X���擾����֐�
	static Player* GetInstance()
	{
		//	�V���O���g���C���X�^���X�̐���
		static Player instance(100, 10, 5);
		//	�C���X�^���X�̃|�C���^��Ԃ�
		return &instance;
	}

	//	�v���C���[�̍X�V����
	void Update()
	{
		////	�v���C���[�̃X�e�[�^�X��\��
		//std::cout << "Player�̗̑́F" << hp << std::endl
		//	<< "Player�̍U���́F" << atk << std::endl
		//	<< "Player�̖h���" << def << std::endl;

		//	�t�H�[�}�b�g�w��q���g�p���ĕ\��
		printf("Player�̗̑́F%d, Player�̍U���́F%d, Player�̖h��́F%d\n", this->hp, this->atk, this->def);
		
	}
};
