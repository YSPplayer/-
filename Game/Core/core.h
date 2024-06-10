/*
创建人：神数不神
创建日期：2024-6-10
无修正
*/
#pragma once
#include "coredata.h"
namespace GameClient::Core {  
	class Core {
	public:
		Core();
		~Core();
		static Core* Init();
		static void Load();
	private:
		static CoreData* pdata;
		static Core* pcore;
;
	};
}