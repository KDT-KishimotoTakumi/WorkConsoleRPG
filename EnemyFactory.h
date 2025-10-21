#pragma once
#include "EnemyData.h"

//	前方宣言
class Enemy;

//	敵クラスの生成を行うファクトリクラス
class EnemyFactory
{
public:

	//	敵のデータを格納するテーブル
	static const EnemyData EnemyTable[];
	//	敵のデータテーブルの要素
	static const int EnemyTableSize;

	// @brief 指定された ID に基づいて敵を生成します。
	// @param [in] ID 敵の ID
	// @return 生成された敵のポインタ。ID が見つからなかった場合は nullptr を返します。
	// @details
	// このメソッドは、指定された ID に基づいて敵を生成します。
	// ID が見つからなかった場合は nullptr を返します。
	static std::shared_ptr<Enemy> CreateEnemy(int ID);
};