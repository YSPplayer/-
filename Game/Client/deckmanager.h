/*
创建人：神数不神
创建日期：2024-6-9
无修正
*/
#pragma once
#include <QList>
#include "clientcard.h"
namespace GameClient::Client {
	class DeckManager {
	public:
		DeckManager();
		~DeckManager();
		static DeckManager* Init();
	private:
		static DeckManager* pdeckManager;
		QList<ClientCard*> cards;//DB数据库读取到的卡片对象
	};
}