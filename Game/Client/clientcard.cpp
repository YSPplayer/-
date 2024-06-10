/*
创建人：神数不神
创建日期：2024-6-8
无修正
*/
#include "clientcard.h"
namespace GameClient::Client {
	ClientCard::ClientCard(quint64 id, quint32 ot, quint64 alias, quint64 type,quint64 setcode, qint64 level,qint64 lscale,qint64 rscale,qint64 linkMarker
,		quint64 attribute, quint64 race, const Value& atk, const Value& def, const QString& name,const QString& desc):
		id(id), ot(ot), alias(alias), type(type),setcode(setcode), level(level),lscale(lscale),rscale(rscale),linkMarker(linkMarker),
		attribute(attribute), race(race), atk(atk), def(def),name(name),desc(desc) {}
	ClientCard::~ClientCard() {
		
	}
}