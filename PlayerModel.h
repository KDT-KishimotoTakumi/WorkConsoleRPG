#pragma once
#include <iostream>

class PlayerModel
{
private:

	//	プレイヤーのステータス
	int hp;		//	体力
	int atk;	//	攻撃力
	int def;	//	防御力

public:

	/// <summary>
	///	コンストラクタ
	/// </summary>
	/// <param name="arg_hp">体力</param>
	/// <param name="arg_atk">攻撃力</param>
	/// <param name="arg_def">防御力</param>
	PlayerModel(int arg_hp = 100, int arg_atk = 10, int arg_def = 5)
		:hp(arg_hp), atk(arg_atk), def(arg_def){}

	/// <summary>
	/// コピー・代入禁止
	/// </summary>
	/// <param name="">プレイヤー</param>
	PlayerModel(const PlayerModel&) = delete;
	PlayerModel& operator=(const PlayerModel&) = delete;

	//	シングルトン
	static PlayerModel* GetInstance()
	{
		//	プレイヤーモデルのインスタンス
		//	HP、攻撃力、防御力の値を入れる
		static PlayerModel instance(100, 10, 5);
		return &instance;
	}

	//	ゲッター
	//	プレイヤーコントローラークラスから値を取得
	//	HP、攻撃力、防御力の値を入れる
	int GetHP() const { return hp; }
	int GetATK() const { return atk; }
	int GetDEF() const { return def; }

	// セッター
	//	HP、攻撃力、防御力の値を入れる
	void SetHP(int value) { hp = value; }
	void SetATK(int value) { atk = value; }
	void SetDEF(int value) { def = value; }

	//	体力が無くなった時にリターンで返す
	bool IsDead() const { return hp <= 0; }
};