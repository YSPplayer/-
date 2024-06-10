/*
创建人：神数不神
创建日期：2024-6-8
无修正
*/
#pragma once
#include <QObject>
#include "../Enum/enumtype.h"
namespace GameClient::Client {
	using namespace GameClient::GameEnum;
	struct Value {
		qint32 value;
		ValueType vtype;
	};
	class ClientCard {
	public:
		ClientCard(quint64 id, quint32 ot, quint64 alias, quint64 type, quint64 setcode,qint64 level,qint64 lscale,qint64 rscale,qint64 linkMarker,
			quint64 attribute, quint64 race, const Value& atk, const Value& def,const QString& name,const QString& desc); 
		~ClientCard();
		quint64 id;//卡号
		quint32 ot;//卡片卡包类别
		quint64 alias;//卡片别名
		quint64 type;//卡片类别
		quint64 setcode;//卡片字段
		qint64 level;//等级，阶级
		qint64 lscale;//左灵摆
		qint64 rscale;//右灵摆
		qint64 linkMarker;//链接标记
		quint64 attribute;//属性
		quint64 race;//种族
		Value atk;//攻击力
		Value def;//守备力
		QString name;//卡片名称
		QString desc;//文本描述
	private:
	};
}