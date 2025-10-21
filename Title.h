#pragma once
#include "SceneBase.h"

class Title : public SceneBase
{
private:

	bool endFlag;							//	�V�[�����I���������ǂ����̃t���O�ϐ�
	SceneType nextScene;					//	���̃V�[����ϐ��ɓ����

public:

	//	�R���X�g���N�^
	//	���ł��ꂼ��̏����l������
	Title()
	{
		this->endFlag = false;
		this->nextScene = SceneType::Game;	
	}
	//	�f�X�g���N�^
	virtual ~Title() {}

	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};
