/*
创建人：神数不神
创建日期：2024-6-8
无修正
*/
#pragma once
#include "../Component/imagecard.h"
#include "../Enum/enumtype.h"
namespace GameClient::Client {
	using namespace GameClient::Component;
	using namespace GameClient::GameEnum;
	struct Value {
		qint32 value;
		ValueType vtype;
	};
	class ClientCard : public ImageCard {
		Q_OBJECT
	public:
		ClientCard(quint64 id, quint32 ot, quint64 alias, quint64 type, quint32 level,
			quint64 attribute, quint64 race, const Value& atk, const Value& def, const QString& desc,
			const QPixmap& image,qint32 width,qint32 height,QWidget* parent = nullptr); 
		~ClientCard();
	private:
		quint64 id;//卡号
		quint32 ot;//卡片卡包类别
		quint64 alias;//卡片别名
		quint64 type;//卡片类别
		quint32 level;//等级
		quint64 attribute;//属性
		quint64 race;//种族
		Value atk;//攻击力
		Value def;//守备力
		QString desc;//文本描述
	};
}