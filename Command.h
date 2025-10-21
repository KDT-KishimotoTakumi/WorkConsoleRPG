#pragma once
#include <iostream>

//	メモ
//	cinの入力で入力された攻撃分Enemyの体力変数の値を減らす
//	値を減らすときはメイン関数で行う

//	コマンドクラス
class Command
{
public:

	//	コマンドの種類
	enum class Type
	{
		Attack,			//	通常攻撃
		SkillAttack,	//	スキル攻撃
		Run,			//	逃走
		None			//	無効なコマンド
	};

	//	コピー・代入の禁止
	Command(const Command&) = delete;
	Command& operator=(const Command&) = delete;

	//	シングルトンインスタンスを取得する関数
	static	Command* GetInstance()
	{
		//	シングルトンインスタンスの生成
		static Command instance;
		//	インスタンスのポインタを返す
		return &instance;
	}

	// どのスキルが選ばれたかを格納する変数（０：通常攻撃、１：スキル攻撃、２：逃走、３：無効なコマンド）
	static int selectedskill;

	//	コンストラクタ
	Command() : type(std::make_shared<Type>(Type::None)) 
	{
	}

	//	デストラクタ
	virtual ~Command() {}

private:
	std::shared_ptr<Type> type; //	コマンドの種類
};