#pragma once
#include "SceneBase.h"

class GameClear : public SceneBase
{
private:

	bool endFlag;					//	�V�[�����I���������ǂ����̃t���O�ϐ�
	SceneType nextScene;			//	���̃V�[����ϐ��ɓ����

public:
	//	�R���X�g���N�^
	//	���ł��ꂼ��̏����l������
	GameClear()
	{
		this->endFlag = false;
		this->nextScene = SceneType::Title;
	}
	//	�f�X�g���N�^
	virtual ~GameClear() {}
	void Update() override;
	void Draw() override;
	bool IsEnd() override { return endFlag; }
	SceneType NextScene() const override { return nextScene; }
};