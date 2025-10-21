#include "Game.h"

void GameScene::Update()
{
	//	�����_���ɂ���i�����̎g�p�j
	//	�����n��̏�����
	//	���̃R�[�h�������Ȃ���rand()���g�p����Ƃ�����������l�������Ă���i���䂷�邽�߁j
	srand(time(NULL));

	////	�����l�̎擾
	//r = (rand() % 4) + 1;

	////	�����̒l��`��
	//printf("%d\n", r);

	switch (state) {
	case GameState::Wait:
		int input1;
		std::cin >> input1;

		if (input1 == 1) {
			Enemy_Ptr->hp -= player->atk;
			std::cout << "�G��" << player->atk << "�_���[�W��^�����I" << std::endl;
			state = GameState::PlayerTurn;
		}
		else if (input1 == 2) {
			Enemy_Ptr->hp -= player->atk * 2;	//	�X�L��
			std::cout << "�G��" << player->atk * 2 << "�_���[�W��^�����I" << std::endl;
			state = GameState::PlayerTurn;
		}
		else if (input1 == 3) {
			std::cout << "�v���C���[�͓����o�����I" << std::endl;
			endFlag = true;
			state = GameState::End;
			nextScene = SceneType::Title;
		}
		else //	�����ȃR�}���h���I�΂ꂽ�ꍇ
		{
			std::cout << "�����ȃR�}���h���I�΂ꂽ�I" << std::endl;
		}
		break;


	case GameState::PlayerTurn:
		//	�v���C���[�̍U������
		std::cout << "�v���C���[�̍U���I" << std::endl;
		state = GameState::Wait;

		if (Enemy_Ptr) {
			if (Enemy_Ptr->hp <= 0) {
				Enemy_Ptr->IsDead();
			}
			if (Enemy_Ptr->IsDead())
			{
				endFlag = true;
				nextScene = SceneType::Clear;
				return;
			}
		}
		else {
			std::cout << "�G��������܂���B" << std::endl;
		}

		//	�G�̃^�[���ֈڍs
		state = GameState::EnemyTurn;

		break;

	case GameState::EnemyTurn:

		if (Enemy_Ptr)
		{
			//	�G�̍U������
			std::cout << Enemy_Ptr->name << "�̍U���I" << std::endl;
			//	�v���C���[��HP�����炷
			player->hp -= Enemy_Ptr->atk - player->def;

			//	�v���C���[�����ꂽ�Ƃ�
			if (player->IsDead())
			{
				endFlag = true;
				nextScene = SceneType::Over;
				return;
			}
		}

		//	�^�[����߂�
		state = GameState::Wait;
		break;

	case GameState::End:

		std::cout << "�Q�[���I��!!" << std::endl;
		endFlag = true;
		nextScene = SceneType::Title;
		break;
	}
}

void GameScene::Draw()
{
	//	�v���C���[�̍X�V�������Ăяo��
	player->Draw();
	//	�G�̍X�V�������Ăяo��
	Enemy_Ptr->Draw();

	switch (state)
	{
	case GameState::Wait:
		std::cout << "�v���C���[�̃^�[��" << std::endl;
		std::cout << "�P�F�U�� �U���́F" << player->atk << std::endl;
		std::cout << "�Q�F�U���X�L�� �U���́F" << player->atk * 2 << std::endl;
		std::cout << "�R�F������ �Q�[���I��" << std::endl;
		break;
	}
}
