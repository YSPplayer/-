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
	struct CoreData {
		QList<ClientCard*> cards;//���������ԭ���Ŀ�Ƭ��Ϣ�ڴ�
		CoreData() {
			
		}
	};

}