/*
创建人：神数不神
创建日期：2024-6-10
无修正
*/
#pragma once
#include <QList>
#include "../Client/clientcard.h"
namespace GameClient::Core { 
	using namespace GameClient::Client;
	struct FilterData { //筛选卡片时需要用到的数据
		quint64 type;
		qint64 level;
		quint64 attribute;
		quint64 race;
		Value atk;
		Value def;
		QString nameKey;
	}; 
	struct CoreData {
		QList<ClientCard*> cards;//存放我们最原初的卡片信息内存
		QList<ClientCard*> filterCards;//索引筛选之后的卡片信息
		FilterData filterData;
		CoreData() {
			filterData = {0,1,0,0,{0,ValueType::Common},{0,ValueType::Common},""};
		}
	};

}