#include "GameClear.h"
#include <iostream>

void GameClear::Update()
{
	//	���͔���p�ϐ�
	int input;
	//	���͂��擾
	std::cin >> input;
	//	�P�����͂��ꂽ�Ƃ��ɃQ�[���V�[���Ɉڍs����
	if (input == 1) {
		nextScene = SceneType::Title;
		endFlag = true;	//	�V�[���I������ɂ���
	}
	else if (input == 2) {	//	�Q�����͂��ꂽ�Ƃ��Q�[�����I������
		nextScene = SceneType::Exit;
		endFlag = true;	//	�V�[���I������ɂ���
	}
}

void GameClear::Draw()
{
	//	��ʂ��N���A�ƕ����̕`��
	system("cls");
	std::cout << "�Q�[���N���A!!" << std::endl;
	std::cout << "�P�F�^�C�g�����" << std::endl;
	std::cout << "�Q�F�Q�[���I��" << std::endl;
}
