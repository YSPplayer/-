/*
创建人：神数不神
创建日期：2024-6-10
无修正
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
	/// 程序加载时需要做的部分操作
	/// </summary>
	void Core::Load() {
		//加载数据库
		QUtil::LoadDb(QUtilGetRootPath()+ "/Data/cards.cdb",pdata->cards);

	}
}  