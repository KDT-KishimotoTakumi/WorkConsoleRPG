#pragma once
#include <iostream>
#include "PlayerModel.h"
#include "PlayerView.h"
#include "Enemy.h" 

//	プレイヤーの行動種別enumクラス
enum class PlayerAction {
	None,	//	なし（他のキーが入力されたとき）
	Attack,	//	通常攻撃
	Skill,	//	スキル攻撃（スキル攻撃は通常攻撃のダメージ２倍）
	Run		//	逃げる
};

//	プレイヤーコントロールクラス
class PlayerController
{
private:

	PlayerModel* player;  //	モデル
	PlayerView view;      //	ビュー

public:

	//	コンストラクタ
	PlayerController()
	{
		player = PlayerModel::GetInstance();	//	モデルクラスのインスタンスをモデルクラスに入れ込む
	}

	//	モデルを取得
	//	プレイヤーをリターンで取得
	PlayerModel* GetModel() { return player; }

	//	入力受付（1:攻撃, 2:スキル, 3:逃げる）
	PlayerAction GetInput()
	{
		int input;			//	入力の値を入れ込むための変数
		std::cin >> input;	//	入力判定処理

		//	キー入力による処理分岐switch文
		switch (input)
		{
		case 1: return PlayerAction::Attack;	//	通常攻撃
		case 2: return PlayerAction::Skill;		//	スキル攻撃
		case 3: return PlayerAction::Run;		//	逃げる
		default:	//	１，２、３以外のコマンドが入力されたとき
			std::cout << "無効なコマンドが選ばれた！" << std::endl;
			return PlayerAction::None;	//	入力なしの処理を返す
		}
	}

	//	通常攻撃
	//	敵のオブジェクトを引数で持ってくる
	void Attack(std::shared_ptr<Enemy> EnemyPtr)
	{
		if (!EnemyPtr) return;				//	敵が存在しないときはリターン
		EnemyPtr->hp -= player->GetATK();	//	敵の体力をプレイヤーの通常攻撃の攻撃力分ダメージを与える
		std::cout << "敵に" << player->GetATK() << "ダメージを与えた！" << std::endl;
	}

	//	スキル攻撃
	void SkillAttack(std::shared_ptr<Enemy> EnemyPtr)
	{
		if (!EnemyPtr) return;				//	敵が存在しないときはリターン
		int damage = player->GetATK() * 2;	//	敵の体力をプレイヤーの通常攻撃の攻撃力分×２ダメージを与える
		EnemyPtr->hp -= damage;				//	ここで敵のHPを減らす
		std::cout << "スキル発動！敵に" << damage << "ダメージを与えた！" << std::endl;
	}

	//	逃げる
	void Run()
	{
		std::cout << "プレイヤーは逃げ出した！" << std::endl;
	}

	//	描画
	void Draw()
	{
		view.DisplayStatus(player);					//	Viewからプレイヤーの描画処理を呼び出す
	}

	//	被ダメージ処理
	void TakeDamage(int value)
	{
		player->SetHP(player->GetHP() - value);		//	プレイヤーのHPを減らす処理を呼び出す
	}

	//	死亡判定
	bool IsDead()
	{
		return player->IsDead();				
	}
};
