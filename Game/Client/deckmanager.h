/*
�����ˣ���������
�������ڣ�2024-6-9
������
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
		QList<ClientCard*> cards;//DB���ݿ��ȡ���Ŀ�Ƭ����
	};
}