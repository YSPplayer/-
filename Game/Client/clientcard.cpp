/*
创建人：神数不神
创建日期：2024-6-8
无修正
*/
#include "clientcard.h"
namespace GameClient::Client {
	ClientCard::ClientCard(quint64 id, quint32 ot, quint64 alias, quint64 type, quint32 level,
		quint64 attribute, quint64 race, const Value& atk, const Value& def, const QString& desc,
		const QPixmap& image,qint32 width,qint32 height,QWidget* parent):ImageCard(image,width,height,parent),
		id(id), ot(ot), alias(alias), type(type), level(level),
		attribute(attribute), race(race), atk(atk), def(def), desc(desc) {}
	ClientCard::~ClientCard() {
		
	}
}