#pragma once
#include <iostream>

//	����
//	cin�̓��͂œ��͂��ꂽ�U����Enemy�̗͕̑ϐ��̒l�����炷
//	�l�����炷�Ƃ��̓��C���֐��ōs��

//	�R�}���h�N���X
class Command
{
public:

	//	�R�}���h�̎��
	enum class Type
	{
		Attack,			//	�ʏ�U��
		SkillAttack,	//	�X�L���U��
		Run,			//	����
		None			//	�����ȃR�}���h
	};

	//	�R�s�[�E����̋֎~
	Command(const Command&) = delete;
	Command& operator=(const Command&) = delete;

	//	�V���O���g���C���X�^���X���擾����֐�
	static	Command* GetInstance()
	{
		//	�V���O���g���C���X�^���X�̐���
		static Command instance;
		//	�C���X�^���X�̃|�C���^��Ԃ�
		return &instance;
	}

	// �ǂ̃X�L�����I�΂ꂽ�����i�[����ϐ��i�O�F�ʏ�U���A�P�F�X�L���U���A�Q�F�����A�R�F�����ȃR�}���h�j
	static int selectedskill;

	//	�R���X�g���N�^
	Command() : type(std::make_shared<Type>(Type::None)) 
	{
	}

	//	�f�X�g���N�^
	virtual ~Command() {}

private:
	std::shared_ptr<Type> type; //	�R�}���h�̎��
};