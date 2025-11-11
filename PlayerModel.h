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

	
	//	ゲッター
	//	プレイヤーコントローラークラスから値を取得
	//	HP、攻撃力、防御力の値を入れる
	int GetHP() const { return hp; }
	int GetATK() const { return atk; }
	int GetDEF() const { return def; }

	//	HP変動メソッド
	void ChangeHp( int damage) {

		hp -= damage;

	}

	//	体力が無くなった時にリターンで返す
	bool IsDead() const { return hp <= 0; }
};