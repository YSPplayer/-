/*
�����ˣ���������
�������ڣ�2024-6-9
������
*/
#include "deckmanager.h"
namespace GameClient::Client {
	DeckManager* DeckManager::pdeckManager = nullptr;
	DeckManager::DeckManager() {

	}

	DeckManager::~DeckManager() {
	}

	DeckManager* DeckManager::Init() {
		return pdeckManager ? pdeckManager : new DeckManager();
	}
}