/*
创建人：神数不神
创建日期：2024-6-9
无修正
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