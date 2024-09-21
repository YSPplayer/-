/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#pragma once
#include <QList>
#include "../Client/clientcard.h"
namespace GameClient::Core { 
	using namespace GameClient::Client;
	struct FilterData { //ɸѡ��Ƭʱ��Ҫ�õ�������
		quint64 type;
		qint64 level;
		quint64 attribute;
		quint64 race;
		Value atk;
		Value def;
		QString nameKey;
	}; 
	struct CoreData {
		QList<ClientCard*> cards;//���������ԭ���Ŀ�Ƭ��Ϣ�ڴ�
		QList<ClientCard*> filterCards;//����ɸѡ֮��Ŀ�Ƭ��Ϣ
		FilterData filterData;
		CoreData() {
			filterData = {0,1,0,0,{0,ValueType::Common},{0,ValueType::Common},""};
		}
	};

}