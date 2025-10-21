#pragma once
#include "SceneType.h"

class SceneBase
{
public:

	//	���z�R���X�g���N�^
	SceneBase() {}
	
	//	���z�f�X�g���N�^
	virtual ~SceneBase() {}

	//	�X�V����
	//	�`�揈��
	//	�������z�֐��Œ�`
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//	�V�[�����I��������ǂ����̔���p�֐�
	virtual bool IsEnd() = 0;

	//	���̃V�[�����擾����֐�
	virtual SceneType NextScene() const = 0;
};