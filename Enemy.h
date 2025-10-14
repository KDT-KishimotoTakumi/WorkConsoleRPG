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

	//	コピー・代入の禁止
	Enemy(const Enemy&) = delete;
	Enemy& operator=(const Enemy&) = delete;

	//	シングルトンインスタンスを取得する関数
	static	Enemy* GetInstance(const EnemyData& data)
	{
		//	シングルトンインスタンスの生成
		static Enemy instance(data);
		//	インスタンスのポインタを返す
		return &instance;
	}

	//	引数コンストラクタ
	//	EnemyData構造体を引数に取る
	Enemy(const EnemyData& data)
		: id(data.id), name(data.name), hp(data.hp), atk(data.atk)
	{
	}

	//	デストラクタ
	virtual ~Enemy() {}

	//	敵の更新処理
	virtual void Update()
	{
		//	Enemyのステータスを表示
		printf("Enemyの名前： % s, Enemyの体力： % d, Enemyの攻撃力： % d\n",
			this->name, this->hp, this->atk);
	}
};
