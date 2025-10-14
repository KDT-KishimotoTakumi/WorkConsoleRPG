#pragma once
#include <iostream>

class Player
{
public:

	//	ステータス変数
	int hp;			//	体力
	int atk;		//	攻撃力
	int def;	//	防御力

	//	引数コンストラクタ
	Player(int arg_hp, int arg_atk, int arg_def)
	{
		//	ステータス変数の初期化
		hp = arg_hp;
		atk = arg_atk;
		def = arg_def;
	}

	//	デストラクタ
	virtual ~Player() {}

	//	コピー・代入の禁止
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

	//	シングルトンインスタンスを取得する関数
	static Player* GetInstance()
	{
		//	シングルトンインスタンスの生成
		static Player instance(100, 10, 5);
		//	インスタンスのポインタを返す
		return &instance;
	}

	//	プレイヤーの更新処理
	void Update()
	{
		////	プレイヤーのステータスを表示
		//std::cout << "Playerの体力：" << hp << std::endl
		//	<< "Playerの攻撃力：" << atk << std::endl
		//	<< "Playerの防御力" << def << std::endl;

		//	フォーマット指定子を使用して表示
		printf("Playerの体力：%d, Playerの攻撃力：%d, Playerの防御力：%d\n", this->hp, this->atk, this->def);
		
	}
};
