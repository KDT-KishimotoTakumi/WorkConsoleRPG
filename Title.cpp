#include "Title.h"
#include <iostream>

void Title::Update()
{
	//	���͔���p�ϐ�
	int input;
	//	���͂��擾
	std::cin >> input;
	//	�P�����͂��ꂽ�Ƃ��ɃQ�[���V�[���Ɉڍs����
	if (input == 1) {
		nextScene = SceneType::Game;
		endFlag = true;	//	�V�[���I������ɂ���
	}
	else if (input == 2) {	//	�Q�����͂��ꂽ�Ƃ��Q�[�����I������
		nextScene = SceneType::Exit;
		endFlag = true;	//	�V�[���I������ɂ���
	}
}

void Title::Draw()
{
	//	��ʂ��N���A�ƕ����̕`��
	system("cls");
	std::cout << "�^�C�g�����" << std::endl;
	std::cout << "�P�F�Q�[���X�^�[�g" << std::endl;
	std::cout << "�Q�F�Q�[���I��" << std::endl;
}
