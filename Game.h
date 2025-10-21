#pragma once
#include "SceneBase.h"
#include <iostream>
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Player.h"

//	================================
//	�^�[�������ƃv���C���[�ƓG�̏���
//	================================

//	�Q�[���̏�Ԃ��Ǘ�����N���X�i�^�[���Ǘ��N���X�j
enum class GameState
{
	PlayerTurn,		//	�v���C���[�̃^�[��
	EnemyTurn,		//	�G�̃^�[��
	Wait,			//	�ҋ@	
	End				//	�I��
};

class GameScene : public SceneBase
{
	std::shared_ptr<Enemy> Enemy_Ptr;	//	�G�̃|�C���^�ϐ�
	Player* player;

private:
	bool endFlag;					//	�V�[�����I���������ǂ����̃t���O�ϐ�
	SceneType nextScene;			//	���̃V�[����ϐ��ɓ����

	GameState state;				//	�Q�[���̏�ԊǗ��ϐ�

public:

	//	�R���X�g���N�^
	//	���ł��ꂼ��̏����l������
	//	�v���C���[�̓C���X�^���X���擾
	GameScene()
	{
		this->endFlag = false;
		this->nextScene = SceneType::Clear;
		this->state = GameState::Wait;
		this->Enemy_Ptr = EnemyFactory::CreateEnemy((rand() % 4) + 1);
		player = Player::GetInstance();
	}

	//	�f�X�g���N�^
	virtual ~GameScene() {}
	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};