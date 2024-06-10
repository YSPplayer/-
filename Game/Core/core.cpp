/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#include "core.h"
#include "../Util/util.h"
#include "../Util/qutil.h"
namespace GameClient::Core { 
	using namespace GameUtil;
	using namespace GameClient::Tool;
	CoreData* Core::pdata = nullptr;
	Core* Core::pcore = nullptr;
	
	Core::Core() {
	
	}

	Core::~Core() {
		Util::ReleasePointer(pdata);
	}

	Core* Core::Init()
	{
		if(pcore) return pcore;
		pdata = new CoreData;
		return new Core();
	}

	/// <summary>
	/// �������ʱ��Ҫ���Ĳ��ֲ���
	/// </summary>
	void Core::Load() {
		//�������ݿ�
		QUtil::LoadDb(QUtilGetRootPath()+ "/Data/cards.cdb",pdata->cards);

	}
}  