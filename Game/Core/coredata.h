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
	struct CoreData {
		QList<ClientCard*> cards;//存放我们最原初的卡片信息内存
		CoreData() {
			
		}
	};

}