/*
�����ˣ���������
�������ڣ�2024-6-10
������
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