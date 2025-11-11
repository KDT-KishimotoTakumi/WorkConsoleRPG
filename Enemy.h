#pragma once
#include <iostream>
#include "EnemyData.h"

//	敵クラスの母体クラス
class Enemy
{
public:

	//	ステータス変数
	int id;				//	敵のID
	const char* name;	//	敵の名前
	int hp;				//	体力
	int atk;			//	攻撃力
	//	publicに置くな

public:

	//	シングルトンをむやみやたらに使おうとするな

	//	引数コンストラクタ
	//	EnemyData構造体を引数に取る
	Enemy(const EnemyData& data)
		: id(data.id), name(data.name), hp(data.hp), atk(data.atk)
	{
	}

	//	デストラクタ
	virtual ~Enemy() {}

	//	敵の更新処理
	virtual void Draw()
	{
		//	HPが０より大きい場合のみ表示
		if (this->hp > 0)
			//	Enemyのステータスを表示
			printf("Enemyの名前： % s, Enemyの体力： % d, Enemyの攻撃力： % d\n",
				this->name, this->hp, this->atk);
	}
	//	敵が死んだかどうかの判定用関数
	virtual bool IsDead()
	{
		//	HPが０になったら消す
		if (this->hp <= 0) {
			std::cout << this->name << "は倒れた！" << std::endl;
		}

		return (this->hp <= 0);
	}

	virtual void Damage()
	{
		std::cout << this->name << "はダメージを受けた！" << std::endl;
	}


};
